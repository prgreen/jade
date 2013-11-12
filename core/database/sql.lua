local M = {}

local core = require "core.core"
local ffi = require "ffi"

local sql = core.load_lib("sqlite3")
setmetatable(M, {__index = sql})

-- DATABASE
M.db = {}


function M.db.exec(db, command)
    sql.sqlite3_exec(db, command, nil, nil, nil)
end

function M.db.prepare(db, content)
    local ret = ffi.new("sqlite3_stmt*[1]")
    sql.sqlite3_prepare_v2(db, content, string.len(content), ret, nil)
    return ffi.gc(ret[0], sql.sqlite3_finalize)
end

ffi.metatype("sqlite3",{__index = M.db})

function M.create_db(filename)
     local ret = ffi.new("sqlite3*[1]")
     sql.sqlite3_open(filename, ret)
     return ffi.gc(ret[0], sql.sqlite3_close)
end


-- PREPARED STATEMENT
M.stmt = {}

function M.stmt.step(stmt)
    return sql.sqlite3_step(stmt) 
end

function M.stmt.reset(stmt)
    return sql.sqlite3_reset(stmt) 
end

function M.stmt.bind_int(stmt, position, value)
    return sql.sqlite3_bind_int(stmt, position, value) 
end
function M.stmt.bind_double(stmt, position, value)
    return sql.sqlite3_bind_double(stmt, position, value) 
end
function M.stmt.bind_text(stmt, position, value)
    return sql.sqlite3_bind_text(stmt, position, value, string.len(value), nil) 
end

ffi.metatype("sqlite3_stmt",{__index = M.stmt})



return M

