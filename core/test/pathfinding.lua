-- Testing pathfinding with graphical display

local core = require "core.core"
local jade = require "core.event.jade"
local sf = require "core.multimedia.sfml"
local grid = require "core.utils.grid"
local time = require "core.utils.time"

GRID_SIZE = 20
BYTES_PER_SQUARE = 2

function mainloop()
    local event = sf.create_event()
    local blue = sf.create_color(0,0,255,255)
    local black = sf.create_color(0,0,0,255)
    local red = sf.create_color(255,0,0,255)
    local green = sf.create_color(0,255,0,255)
    running = true
    local pix = SCREEN_SIZE/GRID_SIZE
    local blue_rect = sf.create_rectangle(0, 0, pix-1, pix-1, blue)
    local red_rect =  sf.create_rectangle(0, 0, pix-1, pix-1, red)
    local green_rect = sf.create_rectangle(0,0,pix-1,pix-1, green)
        
    while running do 
        while app:get_event(event) ~= 0 do
            if event[0].Type == sf.sfEvtClosed then
                app:close()
                jade.mainloop = false
                running = false
            end

            if event[0].Type == sf.sfEvtMouseButtonPressed then
                local button = event[0].MouseButton.Button
                local x = event[0].MouseButton.X
                local y = event[0].MouseButton.Y
                if button == sf.sfButtonLeft then
                    g:set(math.floor(x/pix)+1, math.floor(y/pix)+1, "\1\2")
                    print (math.floor(x/pix)+1)
                    print (math.floor(y/pix)+1)
                    print " "
                elseif button == sf.sfButtonRight then
                    g:set(math.floor(x/pix)+1, math.floor(y/pix)+1, "\1\1")
                end
            elseif event[0].Type == sf.sfEvtKeyPressed then
                if event[0].Key.Code == sf.sfKeyReturn then
                    -- reput green into blue
                    for j = 1, GRID_SIZE do
                        for i = 1, GRID_SIZE do
                            if g:get(i,j) == "\1\3" then
                                g:set(i, j, "\1\1")
                            end
                        end
                    end
                    l = g:find_path({["\1\2"] = true}, 1, GRID_SIZE, GRID_SIZE, 1)
                    --l = g:surround_shortest({["\1\2"] = true}, 5,7,5,4)
                    if l then
                        for i = l.first, l.last do
                            g:set(l[i][1], l[i][2], "\1\3")
                        end
                    end

                end
            end
        end
        local t1 = time.time()
        app:clear(black)

        -- draw grid
        for j = 1, GRID_SIZE do
            for i = 1, GRID_SIZE do
                if g:get(i,j) == "\1\1" then
                    sf.sfShape_SetPosition(blue_rect, pix*(i-1), pix*(j-1))
                    app:draw(blue_rect)
                elseif g:get(i,j) == "\1\2" then
                    sf.sfShape_SetPosition(red_rect, pix*(i-1), pix*(j-1))
                    app:draw(red_rect)
                elseif g:get(i,j) == "\1\3" then
                    sf.sfShape_SetPosition(green_rect, pix*(i-1), pix*(j-1))
                    app:draw(green_rect)
                end
            end
        end

        app:display()
        local t2 = time.time()
        --print (t2-t1)
        jade.wait_for_event(jade.event.tick)
    end
end

function init()
    -- create window
    SCREEN_SIZE = 600
    local video_mode = sf.create_video_mode(SCREEN_SIZE, SCREEN_SIZE, 32)
    local video_settings = sf.create_video_settings(24, 8, 2)
    app = sf.create_window(video_mode,"Pathfinding test", 6, video_settings)
    -- load test grid
    grid.save_content(string.rep("\1",BYTES_PER_SQUARE * GRID_SIZE * GRID_SIZE), _PATH_TEST .. "test.grid") 
    g = grid.load(BYTES_PER_SQUARE, GRID_SIZE, GRID_SIZE, _PATH_TEST .. "test.grid")
    -- draw obstacle lines
    local l = grid.line(2,2, GRID_SIZE-1, GRID_SIZE-1)
    for i = l.first, l.last do
        g:set(l[i][1],l[i][2],"\1\2")
    end

    l = g:find_path({["\1\2"] = true}, 1, GRID_SIZE, GRID_SIZE, 1)
    --l = g:surround_shortest({["\1\2"] = true}, 5,7,5,4)
    for i = l.first, l.last do
        g:set(l[i][1], l[i][2], "\1\3")
    end

    mainloop()
end


jade.trigger(jade.event.init, init)

jade.run(20)

