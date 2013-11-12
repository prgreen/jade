local net = require "core.network.enet"
local jade = require "core.event.jade"
require "pong.protocol"

-- Config
local port = 5556
_APP = "server_pong"


W={}

local server, ev = net.init_server(port)
jade.trigger(jade.event.tick, function() jade.net(server, ev) end)

jade.plug_in(W,"server")

jade.run()

net.exit(server)
