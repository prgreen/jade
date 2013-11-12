local net = require "core.network.enet"
local jade = require "core.event.jade"
require "core.test.protocol"

local client, server, ev = net.init_client(5556, "127.0.0.1")

-- let jade framework check network every tick
jade.trigger(jade.event.tick, function() jade.net(client, ev) end)

-- send exit event to server on client init plus a 180 tick delay
jade.trigger(jade.event.init, 
function() 
    local i = 0
    while i < 180 do
        i = i+1
        jade.wait_for_event(jade.event.tick)
    end
    jade.send_event(server, jade.event.exit)
end)


--[[jade.trigger(jade.event.init,
function()
    jade.send_event(server, jade.event.exit)
end
)
]]--
-- on receiving exit, quit jade mainloop
jade.trigger(jade.event.exit, function() jade.mainloop = false end)

-- run jade event framework
jade.run()

-- clean up resources
net.exit(client)
