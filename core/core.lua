-- Set up useful globals and paths for core functionalities
local M = {}

_DEBUG = true
_APP_NAME = "core"

--package.path = package.path .. ";./core/?.lua"
local debug = require "core.utils.debug"

_ARCH = jit.arch == "x86" and "32" or "64"
_OS = jit.os == "Linux" and "linux" or "win"

-- TEMPORARY FIX  for windows 64 bits to allow running in compatibility mode we pretend to be in 32 bits !!!
if _OS == "win" and _ARCH == "64" then _ARCH = "32" end

debug.log ("OS: ".._OS)
debug.log ("ARCH: ".._ARCH)

_PATH_ROOT = _APP_NAME .. "/"
_PATH_RESOURCES = _PATH_ROOT .. "resources/"
_PATH_LIB_ROOT = _PATH_RESOURCES .. "lib/"
_PATH_INCLUDE_ROOT = _PATH_RESOURCES .. "include/"
_PATH_OS_ARCH = _OS .. _ARCH .. "/"

_PATH_LIB = _PATH_LIB_ROOT .. _PATH_OS_ARCH
_PATH_INCLUDE = _PATH_INCLUDE_ROOT .. _PATH_OS_ARCH

_PATH_TEST = _PATH_RESOURCES .. "testdata/"

local ffi = require "ffi"

--- Load C preprocessed headers to be used with LuaJIT FFI.
-- @param name Name of the header file to be loaded.
function M.load_header(name)
    debug.log("HEADER: " .. _PATH_INCLUDE .. name)
    ffi.cdef(io.open(_PATH_INCLUDE .. name, 'r'):read('*a'))
end

--- Load C shared objects (.dll or .so) to be used with LuaJIT FFI.
-- @param name Name of the shared object to load.
-- @param glob If true, put symbols in global namespace.
function M.load_lib(name, glob)
    debug.log("LIB: " .. name)
    if glob == nil then glob = false end
    if _OS == "linux" then
        --TODO only add lib and .so if the version without is not found!
        local err, res = pcall(ffi.load, _PATH_LIB .. "lib" .. name .. ".so", glob)
        return res
    elseif _OS == "win" then
        local err, res = pcall(ffi.load, _PATH_LIB .. name .. ".dll", glob)
        return res
    end
    local err, res = pcall(ffi.load, _PATH_LIB .. name, glob)
    return res
end
-- Load all declarations to be able to use dynamically loaded objects
M.load_header("ffi_all.h")

return M
