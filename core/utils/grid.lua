local M = {}

local list = require "core.utils.list"

-- a 2d grid is implemented as a table containing a 1d string of 2 bytes elements, arranged horizontally line by line 
function M.load(bytes, x, y, path)
    ret = {}
    ret.size_x = x
    ret.size_y = y
    ret.size_total = x*y
    ret.size_bytes = bytes
    ret.content = ""

    local f = io.open(path, "r")
    if f ~= nil then
        ret.content = f:read("*a")
        io.close(f)
    end

    if string.len(ret.content) ~= ret.size_total * ret.size_bytes then
        print "size error while loading grid"
    end

    setmetatable(ret, {__index = M})
    return ret
end
function M.save(grid, path)
    M.save_content(grid.content, path)
end
function M.save_content(content, path)
    -- simply dump content into a file
    local f = io.open(path, "w+")
    if f ~= nil then
        f:write(content)
        io.close(f)
        return true
    end
    return false
end

function M.get(grid, x, y)
    --TODO check out of bounds
    if x < 1 or y < 1 or x > grid:x() or y > grid:y() then
        print ("OUT OF BOUNDS ".. x .. " " .. y)
    end
    local index = ((y-1) * grid:x() + (x-1)) * grid:bytes() + 1
    return string.sub(grid.content, index, index + grid:bytes() - 1) 
end

function M.set(grid, x, y, value)
    -- TODO check out of bounds and value
    local index = ((y-1) * grid:x() + (x-1)) * grid:bytes() + 1
    local first_part = ""
    local last_part = ""
    if index ~= 1 then
        first_part = string.sub(grid.content, 1, index-1)
    end
    if index ~= ((grid:y()-1) * grid:x() + grid:x() - 1) * grid:bytes() + 1 then
        last_part = string.sub(grid.content, index + grid:bytes())
    end

    grid.content = first_part .. value .. last_part
end

function M.x(grid)
    return grid.size_x
end

function M.y(grid)
    return grid.size_y
end

function M.total(grid)
    return grid.size_total
end
-- number of bytes per square
function M.bytes(grid)
    return grid.size_bytes
end

-- Bresenham algorithm
-- returns points that make the line
--[[function M.line(grid, x_0, y_0, x_1, y_1)
local x0 = x_0
local x1 = x_1
local y0 = y_0
local y1 = y_1

ret = {}
local steep = math.abs(y1-y0) > math.abs(x1-x0)
if steep then
x0, y0 = y0, x0
x1, y1 = y1, x1
end
if x0 > x1 then
x0, x1 = x1, x0
y0, y1 = y1, y0
end
local deltax = x1 - x0
local deltay = math.abs(y1-y0)
local err = 0
local deltaerr = deltay / deltax
local y = y0
local ystep = 0
if y0 < y1 then ystep = 1 else ystep = -1 end
for x = x0, x1 do
if steep then table.insert(ret,{y,x}) else table.insert(ret,{x,y}) end
err = err + deltaerr
if err > 0.5 then
y = y + ystep
err = err - 1
end
end
return ret
end
]]--
-- 4-connected Bresenham
function M.line(arg_x0, arg_y0, arg_x1, arg_y1)
    local x0 = arg_x0
    local y0 = arg_y0
    local x1 = arg_x1
    local y1 = arg_y1

    local ret = list.new()

    local dx = math.abs(x1 - x0)
    local dy = math.abs(y1 - y0)
    local ix = 0
    local iy = 0
    if x0 < x1 then ix = 1 else ix = -1 end
    if y0 < y1 then iy = 1 else iy = -1 end
    --local ix = x0 < x1 and 1 or -1
    --local iy = y0 < y1 and 1 or -1
    local e = 0
    for i = 1, dx+dy do
        ret:pushright({x0,y0})
        local e1 = e + dy
        local e2 = e - dx
        if math.abs(e1) < math.abs(e2) then
            x0 = x0 + ix
            e = e1
        else
            y0 = y0 + iy
            e = e2
        end
    end
    ret:pushright({x0,y0})
    return ret
end

function M.surround_shortest(grid, obs, x0, y0, x1, y1, l_end)
    -- two temp lists, only the shortest will be returned
    ret_clock = list.new()
    ret_anti = list.new()

    local x_clock = x0
    local y_clock = y0
    local x_anti = x0
    local y_anti = y0

    local clock_loop = false
    local anti_loop = false

    -- find first square to turn around 
    if y0 > 1 and obs[grid:get(x0, y0-1)] and y1 < y0 then
        x_clock_around = x0
        y_clock_around = y0 - 1
        x_anti_around = x0
        y_anti_around = y0 - 1
    elseif y0 < grid:y() and obs[grid:get(x0, y0+1)] and y1 > y0 then
        x_clock_around = x0
        y_clock_around = y0 + 1
        x_anti_around = x0
        y_anti_around = y0 + 1
    elseif x0 > 1 and obs[grid:get(x0-1, y0)] and x1 < x0 then
        x_clock_around = x0 - 1
        y_clock_around = y0
        x_anti_around = x0 - 1
        y_anti_around = y0
    elseif x0 < grid:x() and obs[grid:get(x0+1, y0)] and x1 > x0 then
        x_clock_around = x0 + 1
        y_clock_around = y0
        x_anti_around = x0 + 1
        y_anti_around = y0
    end
    while true do
        -- turn around in both directions
        x_clock,y_clock, x_clock_around, y_clock_around = M.surround_clockwise(grid, obs, x_clock, y_clock, x_clock_around, y_clock_around)
        x_anti,y_anti, x_anti_around, y_anti_around = M.surround_anticlockwise(grid, obs, x_anti,y_anti, x_anti_around, y_anti_around)

        -- if trapped in one square
        if x_clock == false or x_anti == false then
            return false
        end

        -- if circling
        if x_clock == x0 and y_clock == y0 then
            clock_loop = true
        end
        if x_anti == x0 and y_anti == y0 then
            anti_loop = true
        end
        if clock_loop and anti_loop then
            return false
        end

        -- save in lists, stop if we reached the end, and return
        if M.is_in(l_end, {x_clock, y_clock}) then
            return ret_clock, x_clock, y_clock
        elseif M.is_in(l_end, {x_anti, y_anti}) then
            return ret_anti, x_anti, y_anti
        else
            ret_clock:pushright({x_clock, y_clock})
            ret_anti:pushright({x_anti, y_anti})
        end
    end

end
function M.is_in(l, e)
    for i = l.first, l.last do
        if l[i][1] == e[1] and l[i][2] == e[2] then
            return true
        end
    end
    return false
end
-- turn around x1 y1 from x0 y0
function M.surround_clockwise(grid, obs, arg_x0, arg_y0, arg_x1, arg_y1)
    local x0 = arg_x0
    local y0 = arg_y0
    local x1 = arg_x1
    local y1 = arg_y1

    local counter = 0

    while x0 == arg_x0 and y0 == arg_y0 and counter < 5 do
        counter = counter + 1
        -- 8 possibilities
        if x0 == x1 + 1 and y0 == y1 + 1 then
            if x0 == 1 or obs[grid:get(x0 - 1, y0)] then
                x1 = x0 - 1
                y1 = y0
            else
                x0 = x0 - 1
            end
        elseif x0 == x1 + 1 and y0 == y1 then
            if y0 == grid:y() or obs[grid:get(x0, y0 + 1)] then
                x1 = x0
                y1 = y0 + 1
            else
                y0 = y0 + 1
            end
        elseif x0 == x1 + 1 and y0 == y1 - 1 then
            if y0 == grid:y() or obs[grid:get(x0, y0 + 1)] then
                x1 = x0
                y1 = y0 + 1
            else
                y0 = y0 + 1
            end
        elseif x0 == x1 and y0 == y1 + 1 then
            if x0 == 1 or obs[grid:get(x0 - 1 , y0)] then
                x1 = x0 - 1
                y1 = y0
            else
                x0 = x0 - 1
            end
        elseif x0 == x1 and y0 == y1 - 1 then
            if x0 == grid:x() or obs[grid:get(x0 + 1 , y0)] then
                x1 = x0 + 1
                y1 = y0
            else
                x0 = x0 + 1
            end
        elseif x0 == x1 - 1 and y0 == y1 + 1 then
            if y0 == 1 or obs[grid:get(x0, y0 - 1)] then
                x1 = x0
                y1 = y0 - 1
            else
                y0 = y0 - 1
            end
        elseif x0 == x1 - 1 and y0 == y1 then
            if y0 == 1 or obs[grid:get(x0, y0 - 1)] then
                x1 = x0
                y1 = y0 - 1
            else
                y0 = y0 - 1
            end
        elseif x0 == x1 - 1 and y0 == y1 - 1 then
            if x0 == grid:x() or obs[grid:get(x0 + 1, y0)] then
                x1 = x0 + 1
                y1 = y0
            else
                x0 = x0 + 1
            end
        end
    end
    if counter == 5 then 
        return false
    end
    return x0,y0,x1,y1
end

function M.surround_anticlockwise(grid, obs, arg_x0, arg_y0, arg_x1, arg_y1)
    local x0 = arg_x0
    local y0 = arg_y0
    local x1 = arg_x1
    local y1 = arg_y1

    local counter = 0

    while x0 == arg_x0 and y0 == arg_y0 and counter < 5 do
        counter = counter + 1
        -- 8 possibilities
        --print (x0)
        --print (y0)
        --print (x1)
        --print (y1)
        --print " "
        if x0 == x1 + 1 and y0 == y1 + 1 then
            if y0 == 1 or obs[grid:get(x0, y0 - 1)] then
                x1 = x0
                y1 = y0 - 1
            else
                y0 = y0 - 1
            end
        elseif x0 == x1 + 1 and y0 == y1 then
            if y0 == 1 or obs[grid:get(x0, y0 - 1)] then
                x1 = x0
                y1 = y0 - 1
            else
                y0 = y0 - 1
            end
        elseif x0 == x1 + 1 and y0 == y1 - 1 then
            if x0 == 1 or obs[grid:get(x0 - 1, y0)] then
                x1 = x0 - 1
                y1 = y0
            else
                x0 = x0 - 1
            end
        elseif x0 == x1 and y0 == y1 + 1 then
            if x0 == grid:x() or obs[grid:get(x0 + 1 , y0)] then
                x1 = x0 + 1
                y1 = y0
            else
                x0 = x0 + 1
            end
        elseif x0 == x1 and y0 == y1 - 1 then
            if x0 == 1 or obs[grid:get(x0 - 1 , y0)] then
                x1 = x0 - 1
                y1 = y0
            else
                x0 = x0 - 1
            end
        elseif x0 == x1 - 1 and y0 == y1 + 1 then
            if x0 == grid:x() or obs[grid:get(x0 + 1, y0)] then
                x1 = x0 + 1
                y1 = y0
            else
                x0 = x0 + 1
            end
        elseif x0 == x1 - 1 and y0 == y1 then
            if y0 == grid:y() or obs[grid:get(x0, y0 + 1)] then
                x1 = x0
                y1 = y0 + 1
            else
                y0 = y0 + 1
            end
        elseif x0 == x1 - 1 and y0 == y1 - 1 then
            if y0 == grid:y() or obs[grid:get(x0, y0 + 1)] then
                x1 = x0
                y1 = y0 + 1
            else
                y0 = y0 + 1
            end
        end
    end
    if counter == 5 then
        return false 
    end
    return x0,y0,x1,y1
end

-- find the path (list of couple of coordinates) from x0 y0 to x1 y1
-- avoiding obstacles in set obs
-- TODO last step, smoothing 
function M.find_path(grid, obs, x0, y0, x1, y1)
    if x0 == x1 and y0 == y1 then
        return false
    end
    if obs[grid:get(x0,y0)] or obs[grid:get(x1,y1)] then
        return false
    end
    local ret = list.new()
    -- first draw a line
    local l = M.line(x0, y0, x1, y1)
    local l_obs = list.new()
    -- make a list of points between obstacles
    local not_obs_index = -1
    for i = l.first, l.last do
        if not obs[grid:get(l[i][1], l[i][2])] then
            if not_obs_index ~= -1 and not_obs_index ~= i-1 then
                l_obs:pushright({l[i][1], l[i][2]})
                --print ("OBS "..l[i][1].." "..l[i][2])
            end
            not_obs_index = i
        end
    end
    -- then iterate on the points, removing obstacles and placing
    -- surround_shortest lists in-between
    local start_index = -1
    M.x_fin = 0
    M.y_fin = 0
    for i = l.first, l.last do
        if not obs[grid:get(l[i][1],l[i][2])] then
            if start_index == -1 then
                --print ("just before cond, x_fin "..M.x_fin.." y_fin "..M.y_fin)
                --print ("and "..l[i][1].. " " .. l[i][2])
                if (M.x_fin == 0 and M.y_fin == 0) or (M.x_fin == l[i][1] and M.y_fin == l[i][2]) then
                    ret:pushright(l[i])
                    M.x_fin = 0
                    M.y_fin = 0
                    --print ("adding "..l[i][1].." "..l[i][2])
                end
                start_index = -1
            elseif M.x_fin ==0 and M.y_fin == 0 then
                local end_index = i
                local l_temp, x_fin, y_fin = M.surround_shortest(grid, obs, l[start_index][1], l[start_index][2], l[end_index][1], l[end_index][2], l_obs)
                M.x_fin = x_fin
                M.y_fin = y_fin
                if l_temp == false then
                    --print ("NO PATH from "..l[start_index][1].. " ".. l[start_index][2])
                    return false
                end

                --print ("x_fin " .. M.x_fin)
                --print ("y_fin " .. M.y_fin)

                local l_obs_temp = list.new()
                local verse = false
                for j = l_obs.first,l_obs.last do
                    if l_obs[j][1] == M.x_fin and l_obs[j][2] == M.y_fin then
                        verse = true
                    elseif verse == true then
                        l_obs_temp:pushright(l_obs[j])
                    end
                end
                l_obs = l_obs_temp

                --print ("start at ".. l[start_index][1] .. " " .. l[start_index][2])
                --print ("end at " .. l[end_index][1] .. " " .. l[end_index][2])
                for j = l_temp.first, l_temp.last do
                    ret:pushright(l_temp[j])
                end
                if M.x_fin == l[i][1] and M.y_fin == l[i][2] then
                    ret:pushright(l[i])
                    M.x_fin = 0
                    M.y_fin = 0
                end
                start_index = -1
            end
        else
            if start_index == -1 and M.x_fin ==0 and M.x_fin == 0 then
                start_index = i-1
            end
        end
    end

    -- smooth with segments
    local current_point = 1
    local ret_final = list.new()
    local no_repeat_x = -1
    local no_repeat_y = -1
    while current_point <= ret:len() do
        -- check lines from current point and add line to path if shorter
        local increment = ret:len()-current_point
        while increment > 1 and not M.no_obstacle_line(grid, obs, ret:get(current_point), ret:get(current_point + increment)) do
            increment = increment - 1
        end

        if increment > 1 then
            local l = M.line(ret:get(current_point)[1], ret:get(current_point)[2], ret:get(current_point + increment)[1], ret:get(current_point + increment)[2]) 
            --print ("line between "..ret:get(current_point)[1].. " "..ret:get(current_point)[2].. " and "..ret:get(current_point+increment)[1], ret:get(current_point+increment)[2])
            for i = l.first, l.last do
                if l[i][1] ~= no_repeat_x or l[i][2] ~= no_repeat_y then
                    ret_final:pushright(l[i])
                end
            end
            no_repeat_x = l[l.first][1]
            no_repeat_y = l[l.first][2]
            current_point = current_point + increment
            -- if no shorter line
        else
            ret_final:pushright(ret:get(current_point))
            current_point = current_point + 1
        end
    end

    --DEBUG
    --[[
    for i = ret_final.first, ret_final.last do
        print (ret_final[i][1] .. " " .. ret_final[i][2])
    end
    --]]--

    return ret_final

end

function M.no_obstacle_line(grid, obs, point1, point2)

    l = M.line(point1[1], point1[2], point2[1], point2[2])
    for i = l.first, l.last do
        if obs[grid:get(l[i][1], l[i][2])] then
            return false
        end
    end

    return true
end

return M
