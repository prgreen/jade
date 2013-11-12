local M = {}

local ffi = require "ffi"
local core = require "core.core"
--core.load_header("ffi_mongo.h")

local mongo = core.load_lib("mongoc")
local bson_t = core.load_lib("bson")

setmetatable(M, {__index = mongo})
M.bson = bson_t

--- Create a connection object. 
-- Use it first with M.connect, then you can run commands
-- to the connected MongoDB database.
function M.create_connection()
    return ffi.gc(ffi.new("mongo_connection[1]"), mongo.mongo_destroy)
end

--- Connect to a MongoDB database on given host and port.
-- Use this function with an object created by M.create_connection.
-- @param conn Connection object.
-- @param host String containing IP address or hostname (default: "127.0.0.1").
-- @param port Number of the port used by Mongo daemon (default: 27017).
function M.connect(conn, host, port)
    if host == nil then host = "127.0.0.1" end
    if port == nil then port = 27017 end
    status = mongo.mongo_connect( conn, host, port)
    
    if status == mongo.mongo_conn_success then
        return true
    else
        return false
    end
end

--- Create a BSON object.
function M.create_bson()
    return ffi.gc(ffi.new("bson[1]"), M.bson.bson_destroy)
end

--- Create a cursor object.
function M.create_cursor()
    --TODO investigate why mongo_cursor_destroy double frees
    return ffi.new("mongo_cursor[1]")
end

--- Create an empty BSON object.
function M.empty()
    local empty = M.create_bson()
    M.bson_empty(empty)
    return empty
end

--- Initialize a BSON buffer.
-- @param buf BSON buffer to initialize.
function M.bson_buffer_init(buf)
    return M.bson.bson_buffer_init(buf)
end

--- Create a BSON object from a BSON buffer.
-- The buffer object is now owned and destroyed properly by the BSON object.
-- @param b BSON object.
-- @param buf BSON buffer.
function M.bson_from_buffer(b, buf)
    return M.bson.bson_from_buffer(b, buf) 
end

--- Insert a Lua Table inside the database.
-- Arbitrary depths not yet implemented.
-- @param conn Connection object already connected to a given database.
-- @param collection String containing the name of the database and collection in which to insert the table (example: "test.persons")
-- @param t Table to save.
function M.insert_table(conn, collection , t)
    b = M.create_bson()
    buf = ffi.new("bson_buffer[1]")
    M.bson.bson_buffer_init(buf)
    
    for k,v in pairs(t) do
        --TODO support integer keys(array), detect infinite loops and depths
        if type(k) == "string" then
            if type(v) == "number" then
                --TODO differentiate int and double
                M.bson.bson_append_int(buf, k, v)
            elseif type(v) == "string" then
                M.bson.bson_append_string(buf, k, v)
            end
        end
    end

    M.bson_from_buffer(b, buf)
    mongo.mongo_insert(conn, collection, b)
end
-- TODO implement batch inserts http://www.mongodb.org/display/DOCS/C+Tutorial

--- Query all elements of a given collection.
-- @param conn Connection object already connected to a database.
-- @param collection String containing database and collection (example: "test.persons")
-- @return Cursor upon which M.cursor_next should be used to iterate on all queried elements.
function M.query_all(conn, collection)
    local cursor = M.create_cursor()
    local empty = M.empty()

    cursor = mongo.mongo_find(conn, "test.persons", empty, empty, 0, 0, 0)
    return cursor
end

--- Get next element of a cursor.
-- @param cursor Cursor on which to iterate
-- @return true or false, should be used in a "while" loop
function M.cursor_next(cursor)
    local ret = mongo.mongo_cursor_next(cursor)
    if ret ~= 0 then return true end
    return false
end

--- Remove elements in a collection.
-- @param conn Connection object already connected to a database.
-- @param collection String containing database and collection (example: "test.persons")
-- @param cond BSON object containing a condition to remove only certain objects in the collection. (not implemented yet)
function M.remove(conn, collection, cond)
    --TODO implement condition
    mongo.mongo_remove(conn, collection, M.empty())
end
return M
