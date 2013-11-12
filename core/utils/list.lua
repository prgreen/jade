local M = {}

function M.new()
    local ret = {first = 0, last = -1}
    setmetatable(ret, {__index = M, __add = M.add})
    return ret
end

function M.pushleft(list, value)
    local first = list.first - 1
    list.first = first
    list[first] = value
end

function M.pushright(list, value)
    local last = list.last + 1
    list.last = last
    list[last] = value
end

function M.popleft(list)
    local first = list.first
    if first > list.last then return nil end
    local value = list[first]
    list[first] = nil        -- to allow garbage collection
    list.first = first + 1
    return value
end

function M.popright(list)
    local last = list.last
    if list.first > last then return nil end
    local value = list[last]
    list[last] = nil         -- to allow garbage collection
    list.last = last - 1
    return value
end

-- get nth element
function M.get(list, nth)
    --TODO check bounds
    return list[list.first + nth - 1]
end

-- set nth element
function M.set(list, nth, value)
    list[list.first + nth - 1] = value
end

-- remove nth element
function M.remove(list, nth)
    --TODO remove from side where the less shifting occurs
    local ret = list[list.first + nth - 1]
    list[list.first + nth - 1] = nil
    for i = list.first + nth - 1, list.last - 1 do
        list[i] = list[i+1]
    end
    list[list.last] = nil
    list.last = list.last - 1
    return ret
end

function M.len(list)
    return list.last - list.first + 1
end

function M.add(a,b)
    local s = M.new()
    for i = a.first, a.last do
        s:pushright(a[i])
    end
    for i = b.first, b.last do
        s:pushright(b[i])
    end
    return s
end

return M
