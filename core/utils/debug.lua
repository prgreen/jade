local M = {}

--- Log errors, warnings, messages, etc.
-- Only appears if _DEBUG is set to true in core/core.lua.
-- @param m Message
function M.log (m)
    --TODO options for criticity, timestamps and saving logs to a file
    if _DEBUG == true then print (m) end
end

return M
