local M = {}

-- Pickle.lua
-- table serialization utility for lua
-- @author Steve Dekorte, http://www.dekorte.com
-- @copyright Apr 2000
-- Freeware
--
-- TODO : boolean support

local json = require "core.utils.json"

local function pickle(t)
    return Pickle:clone():pickle_(t)
end

Pickle = {
    clone = function (t) local nt={}; for i, v in pairs(t) do nt[i]=v end return nt end 
}

function Pickle:pickle_(root)
    if type(root) ~= "table" then 
        error("can only pickle tables, not ".. type(root).."s")
    end
    self._tableToRef = {}
    self._refToTable = {}
    local savecount = 0
    self:ref_(root)
    local s = ""

    while table.getn(self._refToTable) > savecount do
        savecount = savecount + 1
        local t = self._refToTable[savecount]
        s = s.."{\n"
        for i, v in pairs(t) do
            s = string.format("%s[%s]=%s,\n", s, self:value_(i), self:value_(v))
        end
        s = s.."},\n"
    end

    return string.format("{%s}", s)
end

function Pickle:value_(v)
    local vtype = type(v)
    if     vtype == "string" then return string.format("%q", v)
    elseif vtype == "number" then return v
    elseif vtype == "table" then return "{"..self:ref_(v).."}"
    elseif vtype == "boolean" then return tostring(v)
    else --error("pickle a "..type(v).." is not supported")
    end  
end

function Pickle:ref_(t)
    local ref = self._tableToRef[t]
    if not ref then 
        if t == self then error("can't pickle the pickle class") end
        table.insert(self._refToTable, t)
        ref = table.getn(self._refToTable)
        self._tableToRef[t] = ref
    end
    return ref
end

local function unpickle(s)
    if type(s) ~= "string" then
        error("can't unpickle a "..type(s)..", only strings")
    end
    local gentables = loadstring("return "..s)
    if gentables ~= nil then
        local tables = gentables()

        for tnum = 1, table.getn(tables) do
            local t = tables[tnum]
            local tcopy = {}; for i, v in pairs(t) do tcopy[i] = v end
            for i, v in pairs(tcopy) do
                local ni, nv
                if type(i) == "table" then ni = tables[i[1]] else ni = i end
                if type(v) == "table" then nv = tables[v[1]] else nv = v end
                t[i] = nil
                t[ni] = nv
            end
        end
        return tables[1]
    else
        return nil
    end
end

--- Pickle a table.
-- Transforms a table into a string (to be transported through the network, or saved to a file, for example). Beware, not every type is supported.
-- @param t Table to pickle.
-- @return String representing the table.

function M.pickle(t)
    return json.encode(t)
end
--[[function M.pickle(t)
    return pickle(t)
end
]]--

--- Unpickle a table.
-- Transforms a string of a pickled table back into a table.
-- @param s String obtained with the M.pickle function
-- @return Table represented by the string.
function M.unpickle(s)
    return json.decode(s)
end
--[[function M.unpickle(s)
    return unpickle(s)
end
]]--

return M
