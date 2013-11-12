-- CLIENT for the game of pong

local jade = require "core.event.jade"
local net = require "core.network.enet"


-- CONFIG
_APP = "pong"
local host = "88.191.131.158"
--local host = "127.0.0.1"
local port = 5556

-- load app specific events
require (_APP .. ".protocol")

-- global world container
W = {}

-- initiate network globally, connect to server 
client, server, ev = net.init_client(port, host)
-- let jade framework check network every tick
jade.trigger(jade.event.tick, function() jade.net(client, ev) end)

-- plug in the initial module that negotiates with the server
jade.plug_in(W,"connection")

-- and run the application
jade.run()

-- clean up network resources after usage
net.exit(client)
