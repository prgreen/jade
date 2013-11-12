local M = {}

local bit = require "bit"
local DELTA = 0x9e3779b9
local function MX (y, z, e, p, key, sum)
    return bit.bxor((bit.bxor(bit.rshift(z,5),bit.lshift(y,2)) + bit.bxor(bit.rshift(y,3),bit.lshift(z,4))) , (bit.bxor(sum,y) + bit.bxor(key[bit.bxor(bit.band(p,3),e)+1] , z)))
end

-- v is the vector, n the number of blocks, key is 4*32 bits 
function M.xxtea(v, n, key)
    local y
    local z
    local sum
    local p
    local rounds
    local e
    if n > 1 then
        rounds = 6 + math.floor(52/n)
        sum = 0
        z = v[n]
        repeat
            sum = sum + DELTA
            e = bit.band(bit.rshift(sum, 2), 3)
            for p = 0, n-2 do
                y = v[p+2]
                v[p+1] = v[p+1] + MX(y, z, e, p, key, sum)
                z = v[p+1]
            end
            y = v[1]
            v[n] = v[n] + MX(y, z, e, n-1, key, sum)
            z = v[n]
        rounds = rounds - 1
        until rounds == 0
        return 0
    elseif n < -1 then
        local n = -n
        rounds = 6 + math.floor(52/n)
        sum = rounds * DELTA
        y = v[1]
        repeat
            e = bit.band(bit.rshift(sum, 2), 3)
            for p = n-1, 1, -1 do
                z = v[p]
                v[p+1] = v[p+1] - MX(y, z, e, p, key, sum)
                y = v[p+1]
            end
            z = v[n]
            v[1] = v[1] - MX(y, z, e, 0, key, sum)
            y = v[1]
            sum = sum - DELTA
        until sum == 0
        return 0
    end
    return 1
end

return M
