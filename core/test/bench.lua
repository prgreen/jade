local time = require "core.utils.time"
local pickle = require "core.utils.pickle"
local list = require "core.utils.list"
local grid = require "core.utils.grid"
local db = require "core.database.tables"
local mongo = require "core.database.mongo"
local core = require "core.core"
local sha = require "core.utils.sha"
local xxtea = require "core.utils.xxtea"

-- pickle and unpickle 10 000 tables
local t1 = time.time()
local t = {hello="salut", {a="bonjour", b=34}}
t[0]="chose"

for i = 1,10000 do
    local temp = pickle.unpickle(pickle.pickle(t))
end

local t2 = time.time()
print ("UTILS/PICKLE " .. tostring(t2-t1) .. "s or " .. 10000/(t2-t1) .. " operations/s")

-- table save/load 100 tables
local t1 = time.time()
for i = 1, 100 do 
    db.save(t,_PATH_TEST .. "test_bench.lua")
    local temp = db.load(_PATH_TEST .. "test_bench.lua")
end
local t2 = time.time()
print ("DATABASE/TABLE " .. tostring(t2-t1) .. "s or " .. 100/(t2-t1) .. " operations/s")

-- number of mongodb insertions, query, remove per second
local conn = mongo.create_connection()
MONGO_TEST = true
if mongo.connect(conn, "127.0.0.1", 27017) == false then
    print "No Mongodb daemon detected on localhost, port 27017, skipping mongo tests..."
    MONGO_TEST = false
end
local t1 = time.time()
if MONGO_TEST then
    for i = 1,1000 do
    -- Insertion
    --local t = {["name"]="lucifer",["age"]=666}
    mongo.insert_table(conn, "test.persons", t)
    -- Query
    local cursor = mongo.query_all(conn, "test.persons")
    while mongo.cursor_next(cursor) do
        --mongo.bson.bson_print(cursor[0].current)
    end
    -- Remove
    mongo.remove(conn, "test.persons")
    end
    local t2 = time.time()

    print ("DATABASE/MONGO " .. tostring(t2-t1) .. "s or " .. 1000/(t2-t1) .. " operations/s")
end

-- List insertion/access/removal
local t1 = time.time()
local l = list.new()
local LIST_SIZE = 1000
for i = 1, LIST_SIZE do 
    l:pushright(i)
end
for i = 1, LIST_SIZE do
    l:set(i, l:get(i) + 1)
end
for i = 1, LIST_SIZE do
    l:remove(1)
end
local t2 = time.time()
print ("UTILS/LIST " .. tostring(t2-t1) .."s or " .. LIST_SIZE/(t2-t1) .. " operations/s")

-- Grid set/get
grid.save_content(string.rep("\1", 2*100*100), _PATH_TEST .. "test.grid")
local g = grid.load(2,100,100, _PATH_TEST .. "test.grid")
local t1 = time.time()
for i=1,100 do
    for j = 1,100 do
        g:set(i,j,g:get(i,j))
    end
end
local t2 = time.time()
print ("UTILS/GRID " .. tostring(t2-t1) .. "s or " .. 10000/(t2-t1) .. " operations/s")

-- grid pathfinding
-- random obstacles
math.randomseed(os.time())

for j = 1, 100 do
    for i = 1,100 do
        if math.random(5) == 1 then 
            g:set(i,j, "\1\2")
        end
    end
end
local t1 = time.time()
for i = 1, 100 do
    -- choose 2 random points
    local x1 = math.random(100)
    local y1 = math.random(100)
    local x2 = math.random(100)
    local y2 = math.random(100)

    g:find_path({["\1\2"]=true}, x1, y1, x2, y2)
end
local t2 = time.time()
print ("UTILS/GRID PATHFINDING " .. 100/(t2-t1).." paths/s")

