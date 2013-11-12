-- mettre and un fichier stub.c un #include qui va bien puis 
-- gcc -I /usr/local/include/enet -E stub.c|grep -v '^#' > ffi_enet.h

local M = {}
local core = require "core.core"
local ffi = require "ffi"

--[[if _CLIENT then
    core.load_header("ffi_sfnet.h")
else
    core.load_header("ffi_enet.h")
end
]]--
local enet = core.load_lib("enet")
-- TODO: remove metatable when API is complete
setmetatable(M, {__index = enet})

--- Connected
M.CONNECT = enet.ENET_EVENT_TYPE_CONNECT
--- Data received
M.RECEIVE = enet.ENET_EVENT_TYPE_RECEIVE
--- Disconnected
M.DISCONNECT = enet.ENET_EVENT_TYPE_DISCONNECT
-- internal only
function M.init()
    local ret = enet.enet_initialize()
    if (ret == 0) then
        --print ("ENET OK")
    else
        print("ENet initialization failed")
        os.exit(-1)
    end
end

--- Init a server on given port.
-- @param port Port to use for server (ports under 1024 are usually reserved and must have root access)
-- @return (2 variables returned!) "server", and "event"
function M.init_server(port)
    _SERVER = true
    M.init()
    local address = ffi.new("ENetAddress[1]")
    local server = ffi.new("ENetHost[1]")
    local event = ffi.new("ENetEvent[1]")

    address[0].host = enet.ENET_HOST_ANY
    address[0].port = port 

    local server = enet.enet_host_create(address,32,2,0,0)
    if (server == nil) then
        print "Could not create server (already running or port already used)"
        os.exit(-1)
    end
    return server, event
end

--- Init a client for a given port and server address.
-- @param arg_port Port to use to contact server
-- @param arg_address Address of the server
-- @return (3 variables returned!) "client", "peer" and "event"
function M.init_client(arg_port, arg_address)
    M.init()
    client = ffi.new("ENetHost[1]")
    address = ffi.new("ENetAddress[1]")
    peer = ffi.new("ENetPeer[1]")
    event = ffi.new("ENetEvent[1]")

    -- TODO allow changing the bandwidth and number of channels
    client = enet.enet_host_create(nil, 1, 2, 57600/8, 14400/8)
    if client == nil then
        print "Error creating client"
        os.exit(-1)
    end

    enet.enet_address_set_host(address, arg_address)
    address[0].port = arg_port

    peer = enet.enet_host_connect(client, address, 2, 0)
    if peer == nil then 
        print "Server unavailable, please check IP address and port"
        os.exit(-1) 
    end

    if enet.enet_host_service(client, event, 5000) > 0 and event[0].type == enet.ENET_EVENT_TYPE_CONNECT then
        --print "Connection succeeded"
    else
        print "Connection failed, unable to reach server, try again later..."
        os.exit(-1)
    end

    return client, peer, event
end

--- Exit a client or server. Use this after client or server will not be used anymore.
-- @param host The host as returned by a call to M.init_client (client) or M.init_server (server).
function M.exit(host)
    enet.enet_host_destroy(host)
    enet.enet_deinitialize()
end

--- Update events on a host (client or server).
-- @param host Host as returned by M.init_client or M.init_server.
-- @param event Event as returned by same functions.
-- @return Positive number if events were received.
function M.update(host,event)
    local result = enet.enet_host_service(host, event, 0)
    return result
end

--- Update while blocking for a number of milliseconds.
-- @param host Host as returned by M.init_client or M.init_server.
-- @param event Event as returned by same functions.
-- @param t Time to use waiting for events.
-- @return Positive number if events were received.
function M.update_blocking(host,event,t)
    local result = enet.enet_host_service(host, event, t)
    return result
end

--- Send a packet to a peer.
-- Beware, packet is sent only after next call to M.update or M.update_blocking!
-- @param peer Peer to send the message to.
-- @param message String message to transmit.
function M.send(peer, message)
    local p = ffi.new("ENetPacket[1]")
    p = enet.enet_packet_create(message, string.len(message), enet.ENET_PACKET_FLAG_RELIABLE)
    --p = enet.enet_packet_create(message, string.len(message), 0)
    
    enet.enet_peer_send(peer, 0, p)
end

--- Send an unreliable packet to a peer.
-- Beware, packet is sent only after next call to M.update or M.update_blocking!
-- @param peer Peer to send the message to.
-- @param message String message to transmit.
function M.send_unreliable(peer, message)
    local p = ffi.new("ENetPacket[1]")
    --p = enet.enet_packet_create(message, string.len(message), enet.ENET_PACKET_FLAG_RELIABLE)
    p = enet.enet_packet_create(message, string.len(message), 0)
    
    enet.enet_peer_send(peer, 0, p)
end


--- Send a packet immediately to a peer (less efficient than M.send!).
-- @param host Host who is sending the message.
-- @param peer Peer to send the message to.
-- @param message String message to transmit.
function M.dosend(host, peer, message)
    M.send(peer, message)
    enet.enet_host_flush(host)
end

--- Get event type from an event object (use with a switch after an update).
function M.type_event(event)
    return event[0].type
end

function M.get_address(peer)
    --TODO : implement
end

-- timer functions (make it the default one?)
function M.timer()
    local tim = ffi.new("struct timeval[1]")
    enet.gettimeofday(tim, nil)
    local t = tim[0].tv_sec+ (tim[0].tv_usec/1000000.0)
    return t
end

--- Destroy packet after it is used.
function M.packet_destroy(p)
    enet.enet_packet_destroy(p)
end

--- Disconnect from given peer.
function M.disconnect(p)
    enet.enet_peer_disconnect(p, 0)
end

return M
