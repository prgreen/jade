local pickle = require "core.utils.pickle"
local M = {}

--- Save lua table in a file.
-- Only one table per file!
-- @param t Table to save. Cycles, userdata, and exotic stuff won't be saved.
-- @param path Path of the saved file (file is created if it does not exist, erased if it exists, new folders won't be created)
-- @return true on success, false on failure
function M.save(t,path)
    local f = io.open(path, "w+")
    if f ~= nil then
        f:write(pickle.pickle(t))
        io.close(f)                 
    else
        return false
    end 
    return true
end 

--- Load lua table from a file.
-- Only one table per file!
-- @param path Path of the file where a lua table is saved.
-- @returns Saved lua table or nil if an error occurred or the file does not exist.
function M.load(path)
    local t = nil
    local f = io.open(path, "r")
    if f ~= nil then
        t = pickle.unpickle(f:read("*a"))
        io.close(f)         
    end                         
    return t                        
end 

return M
