local M = {}


local core = require "core.core"
local ffi = require "ffi"

local curl = core.load_lib("curl")
setmetatable(M, {__index = curl})

M.curl = curl.curl_easy_init()

-- Core functions, pure binding of libcurl
function M.set_opt(opt_name, opt)
    curl.curl_easy_setopt(M.curl, opt_name, opt)
end

function M.perform()
    curl.curl_easy_perform(M.curl)
end
function M.exit()
    curl.curl_easy_cleanup(M.curl)
end

-- Helper functions, for ease of use


function M.get_url(url)
    local content = ""
    local function local_write(contents, size, nmemb)
        if size*nmemb ~= 0 then
            content = content..ffi.string(contents,size*nmemb)
        end
        return size*nmemb
    end
    M.set_opt(curl.CURLOPT_URL, url)
    M.set_opt(curl.CURLOPT_WRITEFUNCTION, ffi.cast("size_t(*)(void*,size_t,size_t,void*)",local_write))
    M.perform()
    return content
end

return M
