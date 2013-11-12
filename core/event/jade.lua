local M = {}

-- TODO jade.net every xframe with events
--      and jade.sfml with texts, sprites, images, and sfml events
--      as jade events
--      Make it possible to add events and treat them in the same frame.

local time = require "core.utils.time"
local net = require "core.network.enet"
local debug = require "core.utils.debug"
local pickle = require "core.utils.pickle"
local ffi = require "ffi"
M.mainloop = true
M.event = {}

M.event_number=0
--- Create new jade events specific to your application.
-- Events must have different names. They can be accessed with M.event.name.
-- @param Name given to the event
function M.create_event(name)
    -- For network transmission reasons, events are made of 2 bytes.
    M.event[name] = string.char(M.event_number/256) .. string.char(M.event_number%256) 
    M.event[M.event_number] = name
    M.event_number = M.event_number + 1
end
-- Four events are always present:
-- init at the beginning of the program, to load stuff.
M.create_event("init")
-- tick every frame for regular updates of game objects.
M.create_event("tick")
-- when someone connects
M.create_event("connect")
-- when someone disconnects
M.create_event("disconnect")


-- Table used to map events to the functions that respond to them.
local events_to_handlers={}

-- Used locally only
local function register_handler(ev, cond, func)
    if ev ~= nil then
        if events_to_handlers[ev] == nil then
            events_to_handlers[ev] = {}
        end
        table.insert(events_to_handlers[ev], {cond, func})
    end
end

-- Used locally only
local function unregister_handler(ev, cond, func)
    local indexes_to_remove = {}
    if events_to_handlers[ev] ~= nil then
        for k,v in pairs(events_to_handlers[ev]) do
            if v[1] == cond and v[2] == func then
                table.insert(indexes_to_remove, k)
            end
        end
        table.sort(indexes_to_remove, function(a,b) return a>b end)
        for _,v in ipairs(indexes_to_remove) do
            table.remove(events_to_handlers[ev],v)
        end
    end
end

--[[local function table.contains(table, element)
if table == nil then return false end
for _, value in pairs(table) do
if value == element then
return true
end
end
return false
end
]]--

-- Tables used in coroutine and event management.
local coros = {}
local events_queue = {{M.event.init,{}}}
local added_events={}
local waiting_coros={}


-- HELPER functions
local TRUE = function() return true end
--- Wait for specific M.event before pursuing the script.
-- Does not block execution of other events.
-- @param ev Name of the jade event (registered with M.create_event)
function M.wait_for_event(ev)
    return coroutine.yield({event=ev, closure=TRUE})
end
--- Wait for specific M.event and execute a condition function.
-- If the condition is true, then the execution continues, if not
-- the script will wait until another same event and reevaluate 
-- the condition.
-- @param ev Name of the event.
-- @param cond Condition function (must return true or false).
function M.wait_for_event_cond(ev, cond)
    return coroutine.yield({event=ev, closure=cond})
end
--- Trigger a function on a certain event.
-- @param ev On this event.
-- @param func Trigger this function. The function will receive one table argument with the event that triggered it.
-- @param cond Condition function (optional).
function M.trigger(ev,func,cond)
    if cond == nil then
        register_handler(ev,TRUE,func)
    else
        register_handler(ev,cond,func)
    end
end
--- Remove an already present trigger.
-- @param ev Event on which the function was triggered.
-- @param func Function that was triggered.
-- @param cond Condition function.
function M.remove_trigger(ev,func,cond)
    if cond == nil then
        unregister_handler(ev,TRUE,func)
    else
        register_handler(ev,cond,func)
    end
end

--- Add an event to the event queue.
-- Use this function to produce events.
-- @param ev A registered M.event.
-- @param arg Table associated with event to transmit additional data (optional).
function M.fire_event(ev, arg)
    table.insert(added_events, {ev,{event=arg}})
end

--- Send an event through the network to a remote peer (client or server).
-- @param p Peer.
-- @param ev A registered M.event.
-- @param arg A table for additional data associated with the event.
function M.send_event(p,ev,arg)
    --print "calling send event"
    if p ~= nil then
        if arg == nil then
            net.send(p,ev)
        elseif type(arg) == "table" then
            net.send(p,ev..pickle.pickle(arg))
        end
    end
end

--- Send an unreliable event through the network to a remote peer (client or server).
-- @param p Peer.
-- @param ev A registered M.event.
-- @param arg A table for additional data associated with the event.
function M.send_event_unreliable(p,ev,arg)
    --print "calling send event"
    if p ~= nil then
        if arg == nil then
            net.send_unreliable(p,ev)
        elseif type(arg) == "table" then
            net.send_unreliable(p,ev..pickle.pickle(arg))
        end
    end
end

-- Object
local Object = {}
function Object:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

--- Main jade loop. Treats events using coroutines.
-- @param framerate Number of frames per second (default 60)
-- @param cpu Used processing power, between 0 and 1 (default 60/100)
function M.run(framerate, cpu)
    if cpu == nil then cpu = 60/100 end
    if framerate == nil then framerate = 60 end
    M.cpu = cpu
    M.framerate = framerate
    while M.mainloop do
        time.begin_wait(1/framerate) -- 60 frames/second
        -- inject TICK
        table.insert(events_queue, {M.event.tick, {event=nil}})
        -- BEGIN EVENT
        for event_k = 1,#events_queue do
            local full_event_v = events_queue[event_k]
            local event_v = full_event_v[1]
            local event_arg = full_event_v[2]
            -- start event treatment
            --print ("event_k="..event_k.."  event_v="..event_v)

            if events_to_handlers[event_v] ~= nil then
                for k,v in ipairs(events_to_handlers[event_v]) do
                    if v[1](full_event_v) then --TODO : don't test only once, add v[1] function to insert
                        if waiting_coros[event_v] == nil then
                            waiting_coros[event_v] = {}
                        end
                        --print "event to handler, creating coroutine"
                        table.insert(waiting_coros[event_v],{function()return true end, coroutine.create(function() return v[2](full_event_v) end)})
                    end
                end
            end


            -- resume coroutines if this is the event they are waiting for
            local waiting_coros_to_remove = {}
            if waiting_coros[event_v] ~= nil then
                for k = 1, #waiting_coros[event_v] do
                    --print "waking up coroutine"
                    local closure = waiting_coros[event_v][k][1]
                    local coro = waiting_coros[event_v][k][2]
                    if closure(event_arg) then
                        --TODO only insert if not dead
                        --print "waiting coroutine called"
                        --TODO while with timeout
                        local ok, ev = coroutine.resume(coro,{event_v, event_arg})
                        if ok == false or coroutine.status(coro) == "dead" then
                            if ev ~=nil then print (ev) end
                        elseif ev ~=nil then
                            -- get coroutines that wait for events and tuck them away
                            if waiting_coros[ev.event] == nil then
                                waiting_coros[ev.event] = {}
                            end
                            table.insert(waiting_coros[ev.event],{ev.closure,coro})
                            --print "reinsert de coroutines"
                        else

                            table.insert(coros, coro)
                            --print "coroutine vers coros car yield sans arg"
                        end
                        table.insert(waiting_coros_to_remove, k)
                    end
                end
            end
            table.sort(waiting_coros_to_remove, function(a,b) return a>b end)
            for _,v in ipairs(waiting_coros_to_remove) do
                table.remove(waiting_coros[event_v],v)
            end
            -- execute coroutines after all events have been pumped
            --TODO while with timeout around here
        end

        -- execute coroutines
        time.begin_alloted_time(cpu*(1/framerate))
        while time.is_alloted() and #coros > 0 do
            --print (#coros)
            local coros_to_remove = {}
            for k = 1,#coros do
                --print "coroutine executing without args"
                local ok, ev = coroutine.resume(coros[k])
                if ok == false or coroutine.status(coros[k]) == "dead" then
                    if ev ~= nil then print (ev) end
                    --print "Killing coroutine"
                    table.insert(coros_to_remove, k)
                elseif ev ~=nil then
                    -- get coroutines that wait for events and tuck them away
                    if waiting_coros[ev.event] == nil then
                        waiting_coros[ev.event] = {}
                    end
                    table.insert(waiting_coros[ev.event],{ev.closure,coros[k]})
                    table.insert(coros_to_remove, k)
                end
            end
            table.sort(coros_to_remove, function(a,b) return a>b end)
            for _,v in ipairs(coros_to_remove) do
                table.remove(coros, v)
            end
        end

        -- remove events
        events_queue={}
        for _,v in ipairs(added_events) do
            table.insert(events_queue,v)
        end
        added_events={}

        --- wait for frame time to be complete
        time.end_wait()
    end
end

M.cdata = {}
M.i = 0
--- Network function for ease of integration with jade framework.
-- Add this function with a trigger every x ticks. You must have already initiated a client or a server, so that you can use the returned enet event.
-- @param peer Local peer that will be checked for traffic (localhost).
-- @param event Network event as returned by init_server or init_client functions.
function M.net(peer, event)
    local serviceResult = 1
    while serviceResult > 0 do
        serviceResult = net.update(peer,event)
        --debug.log (serviceResult)
        if serviceResult > 0 then
            if net.type_event(event) == net.CONNECT then
                debug.log "A new client connected"
                local p = event[0].peer
                --- Big messy hack... don't touch this...
                _G["pointer".. M.i] = ffi.new("double[1]",{M.i})
                p.data = ffi.cast("void*",_G["pointer".. M.i])
                M.cdata[M.i] = {connected=true, peer=p, id= M.i}
                M.i = M.i+1
                M.fire_event(M.event.connect, {peer=p,id=M.i})
            elseif net.type_event(event) == net.RECEIVE then
                --debug.log ("Packet received")
                local p = event[0].packet
                local m = ffi.string(p.data,p.dataLength)
                local pe = event[0].peer
                local cd = {}

                -- This is a bit hackish too...
                if _SERVER == true then
                    local d_pointer = ffi.cast("double*",pe.data)
                    local d = d_pointer[0]
                    --print (m)
                    --print (p.dataLength)
                    --print(d)
                    cd = M.cdata[tonumber(d)]
                end
                if string.len(m) > 2 then  --event with arguments
                    local t1 = time.time()
                    --handler[string.sub(m,1,2)](cd,string.sub(m,3))
                    table.insert(added_events, {string.sub(m,1,2),{cdata=cd, event=pickle.unpickle(string.sub(m,3))}})
                    --net.send(cd.peer, "Your request was treated.")
                    local t2 = time.time()
                    --print (string.format("Request treated in %.6f seconds", t2-t1))
                elseif string.len(m) == 2 then --event without arguments
                    --handler[m](cd)
                    table.insert(added_events, {m, {cdata=cd, event=nil}})
                end
                net.packet_destroy(event[0].packet)
            elseif net.type_event(event) == net.DISCONNECT then
                debug.log "Disconnected"
                if _SERVER == true then
                    local t1 = time.time()
                    local pe = event[0].peer
                    local index_pointer = ffi.cast("double*",pe.data)
                    local index = tonumber(index_pointer[0])
                    --print (index)
                    if index ~= nil then
                        M.cdata[index].peer = nil
                        --TODO implement load/save login and save everything at exit too!
                        -- db.save_player(M.cdata[index])
                        M.fire_event(M.event.disconnect, {id=index, peer = pe})
                        M.cdata[index] = nil
                        _G["pointer".. M.i]=nil
                    end
                    pe.data = nil
                    local t2 = time.time()
                    --print (string.format("Saving to database in %.6f seconds",t2-t1))
                end
            end
        end
    end
end


--create objects, register events
function M.plug_in(t,mod,name)
    if _APP == nil then
        print "Error, _APP must be defined to be the name and folder containing jade modules of your application"
    end
    local final_name = name
    if name == nil then final_name = mod end
    t[final_name] = require (_APP .. "." .. mod)
    --call init function ?
    if t[final_name] ~= nil then
        if type(t[final_name].init)=="function" then
            t[final_name].init()
        end
    end
    --get triggers and register them ?
end
function M.plug_out(t,name)
    if t[name] ~= nil then
        if type(t[name].exit) == "function" then
            t[name].exit()
        end
    end
end

--- Get peer id from jade event (only on server side)
-- @param event Jade event.
function M.get_id(event)
    return event[2].cdata.id
end
--- Get table data associated with an event.
-- @param event Jade event.
function M.get_data(event)
    return event[2].event
end
--- Get peer object associated with an event (only on server side).
-- @param event Jade event.
function M.get_peer(event)
    return event[2].cdata.peer
end
--- Get peer object associated with a login (only on server side).
-- @param login String used as login by a client.
function M.get_peer_by_login(login)
    for k,v in pairs(cdata) do
        if v.login == login then
            return v.peer
        end
    end
    return nil
end
--- Get event 2 bytes associated with an event.
-- @param event Jade event.
function M.get_event(event) -- not the most explicit name for this function...
    return event[1]
end

--- Reset attributes for a new loop
function M.reset()
    M.mainloop = true

    events_to_handlers={}
    coros = {}
    events_queue = {{M.event.init,{}}}
    added_events={}
    waiting_coros={}


end

return M
