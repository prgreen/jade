local sb = require "core.event.sandbox"
local time = require "core.utils.time"

-- Trying memory over-allocation 
sb.run([[
a = {}
for i = 1,1000000 do
    a.i = (string.char(i%256))
end

print(select('#', ("a"):rep(999):rep(999):byte(1, -1)))
]], function() return false end)

-- Trying infinite loop
sb.run([[while true do end]], function() print "infinite loop prevention OK" return false end, 100) 

-- Checking overhead (between 20% and 100% depending on maskcount)
print "begin"
local t1 = time.time()
sb.run([[
local j = 999
for i = 1,100000 do
    if j%2 == 0 then j = j/2 else j = 3*j +1 end
end
print (j)
]], function()  end, 10) 
local t2 = time.time()
local coro = coroutine.create(function()
local j = 999
for i = 1,100000 do
    if j%2 == 0 then j = j/2 else j = 3*j +1 end
end
print (j)
end)
coroutine.resume(coro)
local t3 = time.time()
print "end"
print (t2-t1)
print (t3-t2)
print ((t2-t1)/(t3-t2))
