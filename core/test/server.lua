local net = require "core.network.enet"
local jade = require "core.event.jade"
require "core.test.protocol"

local server, ev = net.init_server(5556)

local function quit(ev)
    -- send exit event to the client so that he shuts down too
    jade.send_event(jade.get_peer(ev), jade.event.exit)
    -- stop jade mainloop
    jade.mainloop = false
end

--- check network every tick
jade.trigger(jade.event.tick, function() jade.net(server,ev) end)

-- on receiving exit, call quit function
jade.trigger(jade.event.exit, quit)

-- jade mainloop
jade.run()

-- clean up resources
net.exit(server)
