local M = {}

local time = require "core.utils.time"

-- Execute a string safely, giving limited environment and instructions 
local env_default = {print=print, pairs=pairs, ipairs=ipairs,
select=select,
string= {rep = string.rep, byte=string.byte, char = string.char}
}


function M.run(untrusted_code, callback, num_instructions, env)
    env = env or env_default
    local untrusted_function, message = loadstring(untrusted_code)
    if not untrusted_function then return nil, message end
    setfenv(untrusted_function, env)
    local co = coroutine.create(untrusted_function)
    while coroutine.status(co) ~= 'dead' do
        hook.set_hook(num_instructions)
        local ok, m = coroutine.resume(co)
        hook.remove_hook()
        if not ok then
            print (m)
        elseif coroutine.status(co) ~= 'dead' then
            if type(callback) ~= 'nil' and callback() == false then
                break
            end
        end
    end
    -- coroutine goes out of scope and memory is freed
    collectgarbage()
    collectgarbage()
    return getfenv(untrusted_function)
end


return M
