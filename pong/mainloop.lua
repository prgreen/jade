local M = {}

local sf = require "core.multimedia.sfml"
local jade = require "core.event.jade"
local time = require "core.utils.time"
require "core.core"

function M.init()
    M.init_mainloop()
    M.init_gamestate()
    -- draw stuff
    jade.trigger(jade.event.tick, M.mainloop)
    -- receive position updates
    jade.trigger(jade.event.position, M.receive_position)
    -- receive score updates
    jade.trigger(jade.event.scores, M.receive_scores)
    -- receive bong notifications
    jade.trigger(jade.event.bong, M.receive_bong)
end
function M.exit()
end

function M.init_mainloop()
    local video_mode = sf.create_video_mode(800,600,32)
    local context_settings = sf.create_context_settings(24, 8, 2)
    M.app = sf.create_window(video_mode,"RPonGo", 6, context_settings) -- TODO names for window style instead of "6"
    M.event = sf.create_event()
    
    -- TODO Set icon for the window (getPixels function not available for textures)
	M.app:set_icon("pong/data/jade.png")
	--[[
    M.icon = sf.create_image("pong/data/jade.png")
    M.app:set_icon(M.icon)
	]]--

    -- Create texts for scores and associate a font with them
    M.font = sf.create_font(_PATH_TEST .. "arial.ttf") -- TODO have a customised font in the game path, not the test one
    M.score_left_text = sf.create_text("0", {WIDTH/2-100,5}, sf.create_color(255,255,255,255))
    M.score_right_text = sf.create_text("0", {WIDTH/2+100,5}, sf.create_color(255,255,255,255))
	M.score_left_text:set_size(20)
	M.score_right_text:set_size(20)
    M.score_left_text:set_font(M.font)
    M.score_right_text:set_font(M.font)

    M.total_left_text = sf.create_text("0", {WIDTH/2-150, 5}, sf.create_color(255,0,0,255))
    M.total_right_text = sf.create_text("0", {WIDTH/2+150,5}, sf.create_color(0,0,255,255))
    M.sets_playing_text = sf.create_text("1", {WIDTH/2, 5}, sf.create_color(255,255,255,255))
	M.total_left_text:set_size(20)
	M.total_right_text:set_size(20)
	M.sets_playing_text:set_size(12) 
	M.total_left_text:set_font(M.font)
    M.total_right_text:set_font(M.font)
    M.sets_playing_text:set_font(M.font)

    -- Create bong sound
    M.bong = sf.create_music("pong/data/pong.wav")

    -- Create shapes for pads and ball
    M.to_draw = {}
end
function M.init_gamestate()
    M.might_boost_up = -1
    M.might_boost_down = -1
    M.game_has_started = false
    M.score_left = 0
    M.score_right = 0
end
function M.mainloop()
    local app = M.app
    local event = M.event
    local black = sf.create_color(0,0,0,255)
    -- Event treatment
    M.might_boost_up = M.might_boost_up - 1
    M.might_boost_down = M.might_boost_down - 1
    while app:get_event(event) ~= 0 do
        if event[0].type == sf.sfEvtClosed then -- TODO encapsulate event types
            app:close()
            jade.mainloop = false
        end
        -- send pad movement events to server, only when they change
        if event[0].type == sf.sfEvtKeyPressed then

            -- check if bot is wanted
            if event[0].key.code == sf.sfKeyB and not M.game_has_started then
                jade.send_event(server, jade.event.random_game, {robot=1})
            end

            if event[0].key.code == sf.sfKeyUp then
                if M.might_boost_up >= 0 then
                    M.send_move("boost_up")
                else
                    M.send_move("up")
                end
            elseif event[0].key.code == sf.sfKeyDown then
                if M.might_boost_down >= 0 then
                    M.send_move("boost_down")
                else
                    M.send_move("down")
                end
            end
            -- check volley
            if M.side == "left" and event[0].key.code == sf.sfKeyRight then
                jade.send_event(server, jade.event.volley, {activated = 1})
            elseif M.side ~= "left" and event[0].key.code == sf.sfKeyLeft then
                jade.send_event(server, jade.event.volley, {activated = 1})
            end

        elseif event[0].type == sf.sfEvtKeyReleased then
            if event[0].key.code == sf.sfKeyUp then
                M.send_move("none")
                M.might_boost_up = 12 -- number of frames
                M.might_boost_down = -1
            elseif event[0].key.code == sf.sfKeyDown then
                M.send_move("none")
                M.might_boost_down = 12
                M.might_boost_up = -1
            end

            if M.side == "left" and event[0].key.code == sf.sfKeyRight then
                jade.send_event(server, jade.event.volley, {activated = 0})
            elseif M.side ~= "left" and event[0].key.code == sf.sfKeyLeft then
                jade.send_event(server, jade.event.volley, {activated = 0})
            end
        end
    end

    -- Graphical display
    app:clear(black)

    -- Display scores
    app:draw(M.score_left_text)
    app:draw(M.score_right_text)
    app:draw(M.total_right_text)
    app:draw(M.total_left_text)
    app:draw(M.sets_playing_text)

    -- Display pads
    -- Display ball
    -- Interpolate positions
	if M.last ~= nil then
        M.draw_all(M.interpolate(M.last, M.last_time))
    end
	
    for _,v in pairs(M.to_draw) do
        app:draw(v)
    end

    app:display()

end

function M.receive_scores(ev)
    local t = jade.get_data(ev)

    M.score_left = t.left
    M.score_right = t.right
    --print ("SCORE UPDATE " .. t.left .. " " .. t.right)
    M.score_left_text:set_content(tostring(t.left))
    M.score_right_text:set_content(tostring(t.right))
    M.total_left_text:set_content(tostring(t.total_left))
    M.total_right_text:set_content(tostring(t.total_right))
    M.sets_playing_text:set_content(tostring(t.sets + 1))
end

function M.receive_position(ev)
    M.game_has_started = true
    local t = jade.get_data(ev)

    M.last = t -- save last position for interpolation
    M.last_time = time.time() -- save time we received it
    --M.draw_all(M.last)
end

function M.draw_all(t)

    M.to_draw = {}

    -- if boost ~= BOOST_RESERVE, display it
    if t.pad_left.boost <= 0 then t.pad_left.boost = 0 end
    if t.pad_right.boost <= 0 then t.pad_right.boost = 0 end
    if t.pad_left.boost < BOOST_RESERVE then
        local text = sf.create_text(tostring(math.floor(t.pad_left.boost)), {t.pad_left.x + PAD_WIDTH + 5 , t.pad_left.y + PAD_HEIGHT/2 - 5}, sf.create_color(255,255,0,255))
        text:set_font(M.font)
        text:set_size(12)
        table.insert(M.to_draw, text)
    end
    if t.pad_right.boost < BOOST_RESERVE then
        local text = sf.create_text(tostring(math.floor(t.pad_right.boost)), {t.pad_right.x - PAD_WIDTH - 5 , t.pad_right.y + PAD_HEIGHT/2 - 5}, sf.create_color(255,255,0,255))
        text:set_font(M.font)
        text:set_size(12)
        table.insert(M.to_draw, text)
    end
    -- display pads and ball
    local pad_left_rect = sf.create_rectangle(t.pad_left.x, t.pad_left.y, t.pad_left.x + PAD_WIDTH, t.pad_left.y + PAD_HEIGHT, sf.create_color(255,0,0,255))
    local pad_right_rect = sf.create_rectangle(t.pad_right.x, t.pad_right.y, t.pad_right.x + PAD_WIDTH, t.pad_right.y + PAD_HEIGHT, sf.create_color(0,0,255,255))
    local ball_rect = sf.create_rectangle(t.ball.x, t.ball.y, t.ball.x + BALL_SIZE, t.ball.y + BALL_SIZE, sf.create_color(0,255,0,255))

    table.insert(M.to_draw, pad_left_rect)
    table.insert(M.to_draw, pad_right_rect)
    table.insert(M.to_draw, ball_rect)

end
-- Function to copy a table, internal only
function deepcopy(object)
    local lookup_table = {}
    local function _copy(object)
        if type(object) ~= "table" then
            return object
        elseif lookup_table[object] then
            return lookup_table[object]
        end
        local new_table = {}
        lookup_table[object] = new_table
        for index, value in pairs(object) do
            new_table[_copy(index)] = _copy(value)
        end
        return setmetatable(new_table, getmetatable(object))
    end
    return _copy(object)
end
--- Interpolate positions linearly from a state and a time
function M.interpolate(t, last_time)
    -- How many ticks have elapsed ?
    local time_now = time.time()
    local ticks = (time_now - last_time) * jade.framerate

    -- make a copy of argument table
    local G = deepcopy(t)

    -- Now we can interpolate new positions linearly
    -- Same physics as server except no collision detection
    if G.pad_left.volley == 0 or G.pad_left.boost <= 0 then
        -- gravity effect
        if G.pad_left.x > 0 then
            G.pad_left.x = G.pad_left.x - GRAVITY*ticks
            if G.pad_left.x < 0 then G.pad_left.x = 0 end
        end
    elseif G.pad_left.volley == 1 then
        -- volley effect
        if G.pad_left.x <= WIDTH/2-PAD_WIDTH/2 and G.pad_left.boost > 0 then
            G.pad_left.x = G.pad_left.x + VOLLEY*ticks
            G.pad_left.boost = G.pad_left.boost - BOOST_VOLLEY
            if G.pad_left.x > WIDTH/2 - PAD_WIDTH then
                G.pad_left.x = WIDTH/2 - PAD_WIDTH
                G.pad_left.boost = G.pad_left.boost + BOOST_VOLLEY
            end
        end
    end
    if G.pad_right.volley == 0 or G.pad_right.boost <= 0 then
        -- gravity effect
        if G.pad_right.x > 0 then
            G.pad_right.x = G.pad_right.x + GRAVITY*ticks
            if G.pad_right.x > WIDTH-PAD_WIDTH then G.pad_right.x = WIDTH-PAD_WIDTH end
        end
    elseif G.pad_right.volley == 1 then
        -- volley effect
        if G.pad_right.x >= WIDTH/2+PAD_WIDTH/2 and G.pad_right.boost > 0 then
            G.pad_right.x = G.pad_right.x - VOLLEY*ticks
            G.pad_right.boost = G.pad_right.boost - BOOST_VOLLEY
            if G.pad_right.x < WIDTH/2 then
                G.pad_right.x = WIDTH/2
                G.pad_right.boost = G.pad_right.boost + BOOST_VOLLEY
            end
        end
    end



    if G.pad_left.moving == "boost_down" then
        if G.pad_left.boost >= 0 then
            G.pad_left.y = G.pad_left.y + PAD_SPEED * BOOST_FACTOR * ticks
            G.pad_left.boost = G.pad_left.boost - 1
        else
            G.pad_left.moving = "down"
        end
    elseif G.pad_left.moving == "boost_up" then
        if G.pad_left.boost >= 0 then
            G.pad_left.y = G.pad_left.y - PAD_SPEED * BOOST_FACTOR * ticks
            G.pad_left.boost = G.pad_left.boost - 1
        else
            G.pad_left.moving = "up"
        end
    end
    if G.pad_right.moving == "boost_down" then
        if G.pad_right.boost >= 0 then
            G.pad_right.y = G.pad_right.y + PAD_SPEED * BOOST_FACTOR * ticks
            G.pad_right.boost = G.pad_right.boost - 1
        else
            G.pad_right.moving = "down"
        end
    elseif G.pad_right.moving == "boost_up" then
        if G.pad_right.boost >= 0 then
            G.pad_right.y = G.pad_right.y - PAD_SPEED * BOOST_FACTOR * ticks
            G.pad_right.boost = G.pad_right.boost - 1
        else
            G.pad_right.moving = "up"
        end
    end



    -- Move pads
    if G.pad_left.moving == "down" then
        G.pad_left.y = G.pad_left.y + PAD_SPEED*ticks
    elseif G.pad_left.moving == "up" then
        G.pad_left.y = G.pad_left.y - PAD_SPEED*ticks
    end
    if G.pad_right.moving == "down" then
        G.pad_right.y = G.pad_right.y + PAD_SPEED*ticks
    elseif G.pad_right.moving == "up" then
        G.pad_right.y = G.pad_right.y - PAD_SPEED*ticks
    end
    -- If pads are out by more than half their height, place them back
    if G.pad_left.y < -PAD_HEIGHT/2 then
        G.pad_left.y = - PAD_HEIGHT/2
    elseif G.pad_left.y > HEIGHT - PAD_HEIGHT/2 then
        G.pad_left.y = HEIGHT - PAD_HEIGHT/2
    end
    if G.pad_right.y < -PAD_HEIGHT/2 then
        G.pad_right.y = - PAD_HEIGHT/2
    elseif G.pad_right.y > HEIGHT - PAD_HEIGHT/2 then
        G.pad_right.y = HEIGHT - PAD_HEIGHT/2
    end

    -- Move ball
    G.ball.x = G.ball.x + G.ball.vx*ticks
    G.ball.y = G.ball.y + G.ball.vy*ticks

    return G
end

function M.send_move(arg_move)
    jade.send_event(server, jade.event.move, {move=arg_move})
end

function M.receive_bong()
    M.bong:play()
end

return M
