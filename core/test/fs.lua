local sha = require "core.utils.sha"
local ffi = require "ffi"

fs.make_dir("test")
if fs.is_dir("test") then
    print "ok"
else
    print "ko"
end
os.rename("test", "test_rem")
local ok, err = os.remove("test_rem")
if not ok then print (err) end

function sha_file(path)
    local file = assert(io.open (path, 'rb'))
    local x = sha.new256()
    x:add(file:read("*a"))
    file:close()
    return x:close()
end

function root_print_dir(root)
    function print_dir(name, is_dir)
        local d = ""
        if is_dir then
            d = "    DIR"
        end
        local shasum = ""
        if not is_dir then
            shasum = sha_file(root.."/"..name).." "
        end
        if (name ~= "." and name ~= "..") then
            print (shasum..root.."/".. name .. d)
        end
        if is_dir and name ~= "." and name ~= ".." then
            fs.list_dir(root.."/"..name, root_print_dir(root.."/"..name))

        end
    end
    return print_dir
end

function print_dir_rec(path)
    fs.list_dir(path, root_print_dir(path))
end

print_dir_rec("core")
