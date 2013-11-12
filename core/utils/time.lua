local M={}

local ffi = require("ffi")
local core = require "core.core"
--[[if not _CLIENT then
ffi.cdef(io.open('core/utils/ffi_time.h', 'r'):read('*a'))
end
]]--


if _OS == "linux" then 

    ffi.cdef("void usleep(unsigned long usec);")
    M.t = ffi.load("rt")

    --- Sleep for a certain amount of time, in seconds.
    -- Beware, this also blocks everything else in the program, so it shouldn't be called from within a coroutine...
    -- @param t Time to sleep, in seconds (can be float)
    function M.sleep(t)
        ffi.C.usleep(t*1000000)
    end

    --- Get current timestamp.
    -- Useful to get absolute time references and differences. Accurate to the 100 ns.
    -- @return Timestamp in seconds (seconds elapsed since 1970 and counting...)
    function M.time()
        local tim = ffi.new("struct timespec[1]")
        M.t.clock_gettime(0, tim)
        local t = tonumber(tim[0].tv_sec) + tonumber(tim[0].tv_nsec)/1000000000.0
        return t
    end
    
elseif _OS == "win" then
    ffi.cdef("unsigned long time ( unsigned long * chose);")
    ffi.cdef("void Sleep ( unsigned long dwMilliseconds );")
	local winmm = core.load_lib("winmm") -- for high resolution timer on sleep
	ffi.cdef("unsigned int timeBeginPeriod(unsigned int resolution);")
	ffi.cdef("unsigned int timeEndPeriod(unsigned int resolution);") 
	ffi.cdef([[typedef union _LARGE_INTEGER {
  struct {
    unsigned long LowPart;
    long  HighPart;
  };
  struct {
    unsigned long LowPart;
    long  HighPart;
  } u;
  long long QuadPart;
} LARGE_INTEGER, *PLARGE_INTEGER;]])
	ffi.cdef("int QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency)") 
	ffi.cdef("int QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount)")
	-- TODO find a way to call timeEndPeriod when exiting a program that uses Begin !!
    
    M.initialized = 0
    M.CounterStart = 0
    M.PCFreq = 0
    function M.clock_gettime()
        local li = ffi.new("LARGE_INTEGER[1]")
        if M.initialized == 0 then
            M.initialized = 1
			winmm.timeBeginPeriod(1)
            ffi.C.QueryPerformanceFrequency(li)
            M.PCFreq = tonumber(ffi.cast("double", li[0].QuadPart))
			ffi.C.QueryPerformanceCounter(li)
			M.CounterStart = tonumber(ffi.cast("double", li[0].QuadPart))
			return 0
        end
		ffi.C.QueryPerformanceCounter(li)
		local res = 0
		res = (tonumber(li[0].QuadPart)-M.CounterStart)/M.PCFreq
	
		return res
    end
        
    --TODO use timeBeginPeriod to improve timer resolution
    --http://www.geisswerks.com/ryan/FAQS/timing.html
    function M.sleep(t)
            --sf.sfSleep(t)
			--ffi.C.timeBeginPeriod(1)
            ffi.C.Sleep(t*1000)
    end
    function M.time()
        return M.clock_gettime()
    end
end
    

    M.wait_time = M.time()

    --- Wait for a certain amount of time.
    -- Use this function in conjunction with M.end_wait in order to execute a block of instructions in at least a certain amount of time. Can be used to get a fixed framerate. Do not nest.
    -- @param t Time to wait (in seconds).
    function M.begin_wait(t)
        if t == nil then t=0 end
        M.wait_time = M.time()+t
    end

    --- Wait for a certain amount of time.
    -- Use with M.begin_wait.
    function M.end_wait()
        local now = M.time()
        if now < M.wait_time then
            M.sleep(M.wait_time-now)
        end
    end

    M.alloted_time = M.time()

    --- Execute a loop for a minimum amount of time.
    -- Give alloted time then use M.is_alloted inside a while loop so that the loop will be executed for a given amount of time.
    -- @param t Time (in seconds)
    function M.begin_alloted_time(t)
        M.alloted_time = M.time() + t
    end

    --- Conditional used in a while loop.
    -- Useful to loop for a certain amount of time. Used in conjunction with M.begin_alloted_time.
    -- @return false as soon as time is up, true otherwise
    function M.is_alloted()
        return (M.time() < M.alloted_time) 
    end

return M
