local time = require "core.utils.time"

print("testing granularity")
first = time.time();
cur = first;
last = first;
for n = 1,100 do
	time.sleep(1)
    cur = time.time();
	print(tostring(time.time()))
    print(tostring(cur-last))
    last = cur
end