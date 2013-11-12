---------------------------------------------------------------------
-- Author: Jørn Skaarud Karlsen
---------------------------------------------------------------------
local M = {}

require("bit")
require("core.utils.hex")
bit.brshift = bit.rshift
bit.blshift = bit.lshift
---------------------------------------------------------------------
-- Constants
---------------------------------------------------------------------

delta = 0x9E3779B9

---------------------------------------------------------------------
-- Conversion
---------------------------------------------------------------------

function convertStringToBytes(str)
    local bytes = {}
    local strLength = string.len(str)
    for i=1,strLength do
        table.insert(bytes, string.byte(str, i))
    end

    return bytes
end

function convertBytesToString(bytes)
    local bytesLength = table.getn(bytes)
    local str = ""
    for i=1,bytesLength do
        str = str .. string.char(bytes[i])
    end

    return str
end

function convertHexStringToBytes(str)
    local bytes = {}
    local strLength = string.len(str)
    for k=2,strLength,2 do
        local hexString = "0x" .. string.sub(str, (k - 1), k)
        table.insert(bytes, hex.to_dec(hexString))
    end

    return bytes
end

function convertBytesToHexString(bytes)
    local str = ""
    local bytesLength = table.getn(bytes)
    for i=1,bytesLength do
        local hexString = string.sub(hex.to_hex(bytes[i]), 3)
        if string.len(hexString) == 1 then
            hexString = "0" .. hexString
        end
        str = str .. hexString
    end

    return str
end

function convertBytesToUIntArray(bytes, includeLength)
    local bytesLength = table.getn(bytes)
    local result = {}

    if includeLength then
        local n = bit.brshift(bytesLength, 2) + 1
        if bit.band(bytesLength, 3) ~= 0 then
            n = n + 1
        end

        result[n] = bytesLength;
    end

    for i=0,(bytesLength - 1) do
        local resultIndex = bit.brshift(i, 2) + 1
        if result[resultIndex] == nil then
            result[resultIndex] = 0
        end

        local resultValue = bit.blshift(bit.band(0x000000ff, bytes[i+1]), bit.blshift(bit.band(i, 3), 3))
        result[resultIndex] = bit.bor(result[resultIndex], resultValue);
    end

    return result
end

function convertUIntArrayToBytes(data, includeLength)
    local dataLength = table.getn(data)
    local n = bit.blshift(dataLength, 2)
    local result = {}

    if includeLength then
        local m = data[dataLength]
        if m > n then
            return nil
        end

        n = m
    end

    for i=0,(n-1) do
        local value = bit.band(bit.brshift(data[bit.brshift(i, 2) + 1], (bit.blshift(bit.band(i, 3), 3))), 0xff)
        table.insert(result, value)
    end

    return result
end

function convertToUInt32(value)
    if value < 0 then
        local absValue = math.abs(value)
        local a = math.floor(absValue / 0xFFFFFFFF)
        local b = value + a * 0xFFFFFFFF
        local c = 0xFFFFFFFF + b + 1
        return c
    end

    return math.mod(value, 0xFFFFFFFF) - math.floor(value / 0xFFFFFFFF)
end

---------------------------------------------------------------------
-- Encryption/decryption common
---------------------------------------------------------------------

function mx(sum, y, z, p, e, k)
    local aa = bit.brshift(z, 5)
    local ab = convertToUInt32(bit.blshift(y, 2))
    local ac = bit.bxor(aa, ab)

    local ba = bit.brshift(y, 3)
    local bb = convertToUInt32(bit.blshift(z, 4))
    local bc = bit.bxor(ba, bb)
    local ca = bit.bxor(sum, y)

    local dia = bit.band(p, 3)
    local dib = bit.bxor(dia, e)
    local da = k[dib + 1]
    local db = bit.bxor(da, z)

    local ea = convertToUInt32(ca + db)
    local fa = convertToUInt32(ac + bc)
    local ga = bit.bxor(fa, ea)

    return ga
end

---------------------------------------------------------------------
-- Decryption
---------------------------------------------------------------------

function decryptIntArray(v, k)
    local n = table.getn(v)
    local z = v[n]
    local y = v[1]
    local e = 0
    local p = 0

    local q = 6 + math.floor(52 / n)
    local sum = convertToUInt32(q * delta)
    while sum ~= 0 do
        e = bit.band(bit.brshift(sum, 2), 3)
        for p=n,2,-1 do
            z = v[p - 1]
            v[p] = convertToUInt32(v[p] - mx(sum, y, z, (p-1), e, k))
            y = v[p]
        end

        z = v[n]
        v[1] = convertToUInt32(v[1] - mx(sum, y, z, p, e, k))
        y = v[1]

        local sumBefore = sum
        sum = convertToUInt32(sum - delta)
    end

    return v
end

function M.decrypt(data, key)
    local dataLength = string.len(data)
    local keyLength = string.len(key)

    if keyLength == 0 then
        return data
    end

    local keyBytes = convertStringToBytes(key)
    local encryptedBytes = convertHexStringToBytes(data)

    local dataIntArray = convertBytesToUIntArray(encryptedBytes, false)
    local keyIntArray = convertBytesToUIntArray(keyBytes, false)

    local decryptedIntArray = decryptIntArray(dataIntArray, keyIntArray)
    local decryptedBytes = convertUIntArrayToBytes(decryptedIntArray, true)
    local decryptedString = convertBytesToString(decryptedBytes)

    return decryptedString
end

---------------------------------------------------------------------
-- Encryption
---------------------------------------------------------------------

function encryptIntArray(v, k)

    n = table.getn(v)
    if n < 2 then
        return v
    end

    local z = v[n]
    local y = v[1]
    local sum = 0
    local e = 0
    local p = 0
    local initQ = 6 + math.floor(52 / n)

    for q=initQ,1,-1 do
        sum = convertToUInt32(sum + delta);
        e = bit.band(bit.brshift(sum, 2), 3);
        for p=1,(n-1) do
            y = v[p + 1];
            v[p] = convertToUInt32(v[p] + mx(sum, y, z, (p-1), e, k));
            z = v[p]
        end
        y = v[1];
        v[n] = convertToUInt32(v[n] + mx(sum, y, z, (n-1), e, k));
        z = v[n]
    end

    return v;

end

function M.encrypt(data, key)
    local dataLength = string.len(data)
    local keyLength = string.len(key)

    if (keyLength == 0) then
        return data
    end

    local dataBytes = convertStringToBytes(data)
    local keyBytes = convertStringToBytes(key)

    local dataIntArray = convertBytesToUIntArray(dataBytes, true)
    local keyIntArray = convertBytesToUIntArray(keyBytes, false)

    local encryptedIntArray = encryptIntArray(dataIntArray, keyIntArray)
    local encryptedBytes = convertUIntArrayToBytes(encryptedIntArray, false)
    local encryptedString = convertBytesToHexString(encryptedBytes)

    return encryptedString
end

return M
