require "core.utils.luaunit"
local db = require "core.database.tables"
--local mongo = require "core.database.mongo"
local net = require "core.network.enet"
local jade = require "core.event.jade"
local pickle = require "core.utils.pickle"
local time = require "core.utils.time"
local list = require "core.utils.list"
local grid = require "core.utils.grid"
--local sf = require "core.multimedia.sfml"
local ffi = require "ffi"


function file_exists(name)
    local f=io.open(name,"r")
    if f~=nil then io.close(f) return true else return false end
end

-- BEGIN TESTING

TestCore = {}
-- test the "core of the core" 
function TestCore:testConstants ()
    --test that constants are well-defined
    assertEquals(_ARCH == "32" or _ARCH == "64", true)
    assertEquals(_OS == "linux" or _OS == "win", true)
    assertEquals(_APP_NAME == nil, false)
    assertEquals(_PATH_ROOT == nil, false)
    assertEquals(_PATH_RESOURCES == nil, false)
    assertEquals(_PATH_LIB_ROOT == nil, false)
    assertEquals(_PATH_INCLUDE_ROOT == nil, false)
    assertEquals(_PATH_OS_ARCH == nil, false)
    assertEquals(_PATH_LIB == nil, false)
    assertEquals(_PATH_INCLUDE == nil, false)
    assertEquals(_PATH_TEST == nil, false)
end


TestUtils = {}
function TestUtils:testGrid()
    grid.save_content(string.rep("\1", 2*100*100), _PATH_TEST .. "test.grid")
    local g = grid.load(2, 100, 100, _PATH_TEST .. "test.grid")
    
    assertEquals(g:total(), 100*100)
    assertEquals(g:x(), 100)
    assertEquals(g:y(), 100)
    assertEquals(g:bytes(), 2)
    assertEquals(g:get(1,1), "\1\1")
    assertEquals(g:get(g:x(), g:y()), "\1\1")
    g:set(50,50, "\2\2")
    assertEquals(g:get(50,50), "\2\2")
    assertEquals(g:get(51,50), "\1\1")
    assertEquals(g:get(49,50), "\1\1")
    assertEquals(g:get(1,1), "\1\1")
    assertEquals(g:get(g:x(), g:y()), "\1\1")
    g:set(100,100, "\3\3")
    assertEquals(g:get(g:x(), g:y()), "\3\3")
end
function TestUtils:testList()
    local l = list.new()
    l:pushright(5)
    l:pushright(6)
    l:pushright(7)
    assertEquals(l:len(), 3)
    assertEquals(l:get(1), 5)
    assertEquals(l:get(2), 6)
    assertEquals(l:remove(2), 6)
    assertEquals(l:len(), 2)
    assertEquals(l:popleft(), 5)
    assertEquals(l:popleft(), 7)
    l:pushright(1)
    l:pushright(2)
    local l2 = list.new()
    l2:pushright(3)
    local ls = l + l2
    assertEquals(ls:get(3), 3)
end
function TestUtils:testPickle()
    local t1 = {
        login = "test",
        password = "toto",
        connected = true,
        number=45,
        subtable= 
        {subtable1 = "ok", subtable2= {subsub1="fine", subsub2=1337.1337}}
    }
    local t2 = pickle.unpickle(pickle.pickle(t1))
    assertEquals(t2 == nil, false)
    assertEquals(t2.connected, true)
    assertEquals(t2.password, "toto")
    assertEquals(t2.number, 45)
    assertEquals(t2.subtable == nil, false)
    assertEquals(t2.subtable.subtable2 == nil, false)
    assertEquals(t2.subtable.subtable1, "ok")
    assertEquals(t2.subtable.subtable2.subsub1, "fine")
    assertEquals(t2.subtable.subtable2.subsub2, 1337.1337)
    assertEquals(t2.hallucination == nil, true)
    assertError(function() t2.hallucination.bs = "test" end)
    assertEquals(#t1 == #t2, true)
end
function TestUtils:test1TimeTenthResolution()
    local t1 = time.time()
    time.sleep(1)
    local t2 = time.time()
    assertEquals(t2-t1 < 1.1, true)
    assertEquals(t2-t1 > 0.9, true)
end
function TestUtils:test2TimeHundredthResolution()
    local t1 = time.time()
    time.sleep(1)
    local t2 = time.time()
    assertEquals(t2-t1 < 1.01, true)
    assertEquals(t2-t1 > 0.99, true)
end


TestDatabase = {}
function TestDatabase:setUp()
end
function TestDatabase:tearDown()
end
function TestDatabase:test1TableSave()
    local t = {
        login = "test",
        password = "toto",
        connected = true,
        number=45,
        subtable= 
        {subtable1 = "ok", subtable2= {subsub1="fine", subsub2=1337.1337}}
    }
    db.save(t, _PATH_TEST .. "test_table.lua")
    assertEquals(file_exists(_PATH_TEST .. "test_table.lua"), true)
end
function TestDatabase:test2TableLoad()
    local t = db.load(_PATH_TEST .. "test_table.lua")
    assertEquals(t == nil, false)
    assertEquals(t.connected, true)
    assertEquals(t.password, "toto")
    assertEquals(t.number, 45)
    assertEquals(t.subtable == nil, false)
    assertEquals(t.subtable.subtable2 == nil, false)
    assertEquals(t.subtable.subtable1, "ok")
    assertEquals(t.subtable.subtable2.subsub1, "fine")
    assertEquals(t.subtable.subtable2.subsub2, 1337.1337)
    assertEquals(t.hallucination == nil, true)
    assertError(function() t.hallucination.bs = "test" end)
end
--[[function TestDatabase:test3MongoConnect()

    local conn = mongo.create_connection()
    MONGO_TEST = true
    if mongo.connect(conn, "127.0.0.1", 27017) == false then
        print "No Mongodb daemon detected on localhost, port 27017, skipping mongo tests..."
        MONGO_TEST = false
    end

    if MONGO_TEST then
        -- Insertion
        local t = {["name"]="lucifer",["age"]=666}
        mongo.insert_table(conn, "test.persons", t)
        -- Query
        local cursor = mongo.query_all(conn, "test.persons")
        while mongo.cursor_next(cursor) do
            mongo.bson.bson_print(cursor[0].current)
        end
        -- Remove
        mongo.remove(conn, "test.persons")
    end
end
]]--

TestNetwork = {}
function TestNetwork:test1Connect()
end

TestEvent = {}
function TestEvent:test1SimpleEvent()
    local a = false
    local function hello()
        a = true
    end
    local function quit()
        jade.mainloop = false
    end
    jade.trigger(jade.event.init, hello)
    jade.trigger(jade.event.tick, quit)
    
    local t1 = time.time()
    jade.run()
    local t2 = time.time()

    assertEquals(a, true)
	print ("REAL TIME (16ms) " .. tostring(t2-t1))
    assertEquals((t2-t1) < 0.018, true)
    assertEquals((t2-t1) > 0.015, true)
    
    --jade.remove_trigger(jade.event.init, hello)
    --jade.remove_trigger(jade.event.tick, quit)
    jade.reset()
end
function TestEvent:test2DelayedEvent()
    jade.create_event("exit")
    local function delayed()
        local i = 0
        while i < 60 do
            i = i + 1
            jade.wait_for_event(jade.event.tick)
        end
        jade.fire_event(jade.event.exit)
    end
    local function exit()
        jade.mainloop = false
    end
    
    jade.trigger(jade.event.init, delayed)
    jade.trigger(jade.event.exit, exit)

    local t1 = time.time()
    jade.run()
    local t2 = time.time()
	print ("REAL TIME (1s) " .. tostring(t2-t1))
    assertEquals((t2-t1) > 0.95, true)
    assertEquals((t2-t1) < 1.2, true)
    jade.reset()
end
function TestEvent:test3TimeoutEvent()
    jade.create_event("top")
    -- send a top after x ticks
    local function send_top(x)
        local i = 0
        while i < x do
            i = i + 1
            jade.wait_for_event(jade.event.tick)
        end
        jade.fire_event(jade.event.top)
    end
    
    -- wait for a top for x ticks or timeout
    local function wait_top(x)
        jade.wait_for_event(jade.event.top)
        jade.mainloop = false
    end

    jade.trigger(jade.event.init, function() send_top(50) end)
    jade.trigger(jade.event.init, function() wait_top(60) end)

    jade.run()

    jade.reset()
end
--[[
TestMultimedia = {}
function TestMultimedia:testLoadMusic()
    local music = sf.create_music(_PATH_TEST .. "sound.wav")
    assertEquals(music == nil, false)
end
function TestMultimedia:testLoadFont()
    local font = sf.create_font(_PATH_TEST .. "arial.ttf", 20, nil)
    assertEquals(font == nil, false)
end
function TestMultimedia:testLoadImage()
    local image = sf.create_image(_PATH_TEST .. "jade.jpg")
    assertEquals(image == nil, false)
end
--]]

LuaUnit:run()
