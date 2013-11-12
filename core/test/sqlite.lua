local ffi = require "ffi"
local core = require "core.core"

--[[
local sql = core.load_lib("sqlite3")

local db = ffi.new("sqlite3*[1]") 
local conn = sql.sqlite3_open("test.db", db)

conn = sql.sqlite3_exec(db[0], "CREATE TABLE mytable(num_client INT PRIMARY KEY NOT NULL, nom_client TEXT)", nil, nil, nil)

sql.sqlite3_close(nil)
]]

local sql = require "core.database.sql"

local db = sql.create_db("test.db")

db:exec("PRAGMA synchronous=OFF")
db:exec("PRAGMA count_changes=OFF")
db:exec("PRAGMA journal_mode=MEMORY")
db:exec("PRAGMA temp_store=MEMORY")

db:exec([[DROP TABLE mytable]])
db:exec([[CREATE TABLE mytable(num_client INT PRIMARY KEY NOT NULL, nom_client TEXT)]])

db:exec("BEGIN")
local stmt = db:prepare([[INSERT INTO mytable VALUES(?,?)]])
for i = 1,100000 do
    stmt:bind_int(1,i)
    stmt:bind_text(2,"toto"..i)
    stmt:step()
    stmt:reset()
end
db:exec("COMMIT")

local select_stmt = db:prepare([[SELECT * FROM mytable WHERE num_client < 10]])

local res = 0
while res ~= 101 do
    res = select_stmt:step()
    if res == 100 then
        print (tostring(sql.sqlite3_column_int(select_stmt, 0)).." "..ffi.string(sql.sqlite3_column_text(select_stmt, 1)))
    end
end