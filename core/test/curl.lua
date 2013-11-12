-- Testing curl

local curl = require "core.network.curl"

--curl.set_opt(curl.CURLOPT_URL, "http://curl.haxx.se")
--curl.perform()

local text = curl.get_url("http://wiki.answers.com/Q/What_the_fuck")
-- find <div id="editorText"> and then </div>

local index = string.find(text, "<div id=\"editorText\">")
if index ~= nil then
    -- print answer
    local index_end = string.find(text, "</div>", index)
    print (index)
    print (index_end)
    print (string.sub(text, index, index_end))
else
    -- suggest other questions
end
curl.exit()
