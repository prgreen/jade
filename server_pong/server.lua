local M = {}

local jade = require "core.event.jade"

-- Store all game information (integer keys are game ids)
M.games = {}
M.games_index = 1
-- Associate every player id (key) with the appropriate game id (value)
-- in which they are playing
M.player_to_game = {}

function M.init()
    jade.trigger(jade.event.random_game, M.random_game)
    -- Receive player moves
    jade.trigger(jade.event.move, M.receive_move)
    -- Receive volley boosts
    jade.trigger(jade.event.volley, M.receive_volley)
    -- Receive disconnections
    jade.trigger(jade.event.disconnect, M.receive_disconnect)
end
function M.exit()
end

function M.init_gamestate(t)
    math.randomseed(os.time())
    t.score_left = 0
    t.score_right = 0
    t.pad_left_moving = "none"
    t.pad_right_moving = "none"
    t.total_left = 0
    t.total_right = 0
    t.sets_played = 0
end

function M.random_game(ev)
    local peer = jade.get_peer(ev)
    local peer_id = jade.get_id(ev)
    local t = jade.get_data(ev)
    local response = {}
    if M.games[M.games_index] == nil then
        M.games[M.games_index] = {}
    end
    if type(M.games[M.games_index].player_left) == "nil" then
        response.side = "left"
        M.games[M.games_index].player_left = jade.get_peer(ev)
        M.player_to_game[peer_id] = M.games_index
    elseif type(M.games[M.games_index].player_right) == "nil" then
        response.side = "right"
        if t ~=nil and t.robot ==1 then
            M.games[M.games_index].player_right = nil
            M.games[M.games_index].player_right_bot = true
        else
            M.games[M.games_index].player_right = jade.get_peer(ev)
            M.player_to_game[peer_id] = M.games_index
        end
        M.init_gamestate(M.games[M.games_index])
        M.games_index = M.games_index + 1
        M.start_point(M.games_index - 1)

    else -- TODO not used, count number of matches and have limitations!
        response.side = "full"
    end
    jade.send_event(peer, jade.event.random_game, response)
end 
function M.reset_point(G)
    G.pad_left = {}
    G.pad_left.x = 0
    G.pad_left.y = HEIGHT/2
    G.pad_left.moving = "none" -- can be "up" or "down" or "boost_up" or ...
    G.pad_left.boost = BOOST_RESERVE
    G.pad_left.volley = 0
    G.pad_right = {}
    G.pad_right.x = WIDTH-PAD_WIDTH
    G.pad_right.y = HEIGHT/2
    G.pad_right.moving = "none"
    G.pad_right.boost = BOOST_RESERVE
    G.pad_right.volley = 0
    G.ball= {}
    G.ball.x = WIDTH/2
    G.ball.y = HEIGHT/2
    G.ball.vx = BALL_INIT_VX
    G.ball.vy = BALL_INIT_VY
end
function M.start_point(game_index)
    -- Local table containing game information
    local L = M.games[game_index]

    -- Starting a point, reset coordinates
    local G = {} -- game state we want to send to the clients
    M.reset_point(G)

    -- Physics loop
    local tick_count = 0
    while true do
        -- check whether we are shutting down
        if L.shutdown == true then
            -- destroy game and stop coroutine
            -- TODO warn client, hey!
            L = nil
            return
        end

        -- Calculate new coordinates
        -- Update movement of pads
        G.pad_left.moving = L.pad_left_moving
        if not L.player_right_bot then
            G.pad_right.moving = L.pad_right_moving
        end

        G.pad_left.volley = L.pad_left_volley
        if not L.player_right_bot then
            G.pad_right.volley = L.pad_right_volley
        end

        -- call AI function if necessary
        -- AI takes game state as argument and pad to move and returns a move
        if L.player_right_bot and tick_count % 12 == 0 then
            G.pad_right.moving, G.pad_right.volley = M.bot_ai1(G, G.pad_right)
        end

        -- Volley boost
        M.apply_volley(G.pad_left, LEFT)
        M.apply_volley(G.pad_right, RIGHT)

        -- Lateral boost
        M.apply_lateral(G.pad_left, LEFT)
        M.apply_lateral(G.pad_right, RIGHT)

        -- If not moving replenish boost at half usage speed
        M.replenish_boost(G.pad_left, G.ball.vx, LEFT)
        M.replenish_boost(G.pad_right, G.ball.vx, RIGHT)

        -- Move up or down
        M.move(G.pad_left)
        M.move(G.pad_right)

        -- Move ball
        G.ball.x = G.ball.x + G.ball.vx
        G.ball.y = G.ball.y + G.ball.vy

        -- Detect collisions
        -- Top or bottom wall collisions
        if G.ball.y - BALL_SIZE/2 < 0 then
            G.ball.y = BALL_SIZE/2
            G.ball.vy = - G.ball.vy
        end
        if G.ball.y + BALL_SIZE/2 > HEIGHT then
            G.ball.y = HEIGHT - BALL_SIZE/2
            G.ball.vy = - G.ball.vy
        end

        -- Pad and ball collisions
        if M.collide(G.pad_left.x, G.pad_left.y, PAD_WIDTH, PAD_HEIGHT,
            G.ball.x, G.ball.y, BALL_SIZE, BALL_SIZE) then
            M.solve_collision(G.pad_left, G.ball, LEFT)
            -- send bong event to clients
            jade.send_event(L.player_left, jade.event.bong)
            jade.send_event(L.player_right, jade.event.bong)
        elseif M.collide (G.pad_right.x, G.pad_right.y, PAD_WIDTH, PAD_HEIGHT,
            G.ball.x, G.ball.y, BALL_SIZE, BALL_SIZE) then
            M.solve_collision(G.pad_right, G.ball, RIGHT)
            -- send bong event to clients
            jade.send_event(L.player_left, jade.event.bong)
            jade.send_event(L.player_right, jade.event.bong)
        end

        -- if right player scores
        if G.ball.x + BALL_SIZE < 0 then
            L.score_right = L.score_right + 1
            --check if match is over
            if L.score_right >= L.score_left + 3 or L.score_right == 10 then
                L.total_right = L.total_right + 10 - L.score_left
                L.sets_played = L.sets_played + 1
                L.score_right = 0
                L.score_left = 0
            end
            M.send_scores(game_index)
            M.reset_point(G)
            G.ball.vx = -BALL_INIT_VX
        end
        -- if left player scores
        if G.ball.x > WIDTH then
            L.score_left = L.score_left + 1
            --check if match is over
            if L.score_left >= L.score_right + 3 or L.score_left == 10 then
                L.total_left = L.total_left + 10 - L.score_right
                L.sets_played = L.sets_played + 1
                L.score_right = 0
                L.score_left = 0
            end
            M.send_scores(game_index)
            M.reset_point(G)
        end

        -- Send coordinates to both players (20 times/second only!)
        if tick_count % 3 == 0 then
            jade.send_event_unreliable(L.player_left, jade.event.position, G)
            jade.send_event_unreliable(L.player_right, jade.event.position, G)
        end

        -- Wait for next tick
        jade.wait_for_event(jade.event.tick)
        tick_count = tick_count + 1
    end
end

--- Send game scores to the players.
function M.send_scores(game_index)
    local L = M.games[game_index]
    jade.send_event(L.player_left, jade.event.scores, {left=L.score_left, right=L.score_right, total_left = L.total_left, total_right = L.total_right, sets = L.sets_played})
    jade.send_event(L.player_right, jade.event.scores, {left=L.score_left, right=L.score_right, total_left = L.total_left, total_right = L.total_right, sets = L.sets_played})

end

--- Receive the player's move intention (up or down or none).
function M.receive_move(ev)
    local t = jade.get_data(ev)
    local peer = jade.get_peer(ev)
    local peer_id = jade.get_id(ev)
    local L = M.games[M.player_to_game[peer_id]]

    if peer == L.player_left then
        L.pad_left_moving = t.move
    elseif peer == L.player_right then
        L.pad_right_moving = t.move
    end
end

--- Check if two rectangles (top left x y, width height w h) collide.
function M.collide(x1, y1, w1, h1, x2, y2, w2, h2)
    local left1 = x1
    local left2 = x2
    local right1 = x1 + w1
    local right2 = x2 + w2
    local top1 = y1
    local top2 = y2
    local bottom1 = y1 + h1
    local bottom2 = y2 + h2

    if bottom1 < top2 then return false end
    if top1 > bottom2 then return false end
    if right1 < left2 then return false end
    if left1 > right2 then return false end

    return true
end

function M.receive_volley(ev)
    local t = jade.get_data(ev)
    local peer = jade.get_peer(ev)
    local peer_id = jade.get_id(ev)
    local L = M.games[M.player_to_game[peer_id]]
    local activated = t.activated

    if peer == L.player_left then
        L.pad_left_volley = activated
    elseif peer == L.player_right then
        L.pad_right_volley = activated
    end
end

function M.receive_disconnect(ev)
    local t = jade.get_data(ev)
    local peer = t.peer
    local id = t.id
    local L = M.games[M.player_to_game[t.id]]

    -- shut down game
    L.shutdown= true

end

function M.bot_ai1(G, pad)
    local ball_center = G.ball.y + BALL_SIZE/2
    local pad_center = pad.y + PAD_HEIGHT/2
    local volley = 0
    if G.ball.vx > 0 then 
        if math.abs(G.ball.x-pad.x) < 250 then
            if math.abs(G.ball.vy)>PAD_SPEED/2 then
                volley = 0
            else
                volley = 1
            end
            if pad_center - ball_center > 3/4*PAD_HEIGHT then
                return "boost_up", volley
            elseif ball_center - pad_center > 3/4*PAD_HEIGHT then
                return "boost_down", volley
            end
        end
        if pad_center - ball_center > PAD_HEIGHT/3 then
            return "up", volley
        elseif ball_center - pad_center > PAD_HEIGHT/3 then
            return "down", volley
        else
            return "none", volley
        end
    else
        -- replace in the center and recharge
        if pad_center - HEIGHT/2 > 2*PAD_HEIGHT then
            return "up", volley
        elseif HEIGHT/2 - pad_center > 2*PAD_HEIGHT then
            return "down", volley
        else
            return "none", volley
        end
    end
end
function M.is_inside(pad, side)
    if side == LEFT then
        return pad.x >= M.baseline(side)
    elseif side == RIGHT then
        return pad.x <= M.baseline(side)
    end
end
function M.baseline(side)
    if side == LEFT then
        return 0
    elseif side == RIGHT then
        return WIDTH-PAD_WIDTH
    end
end
function M.netline(side)
    if side == LEFT then
        return WIDTH/2-PAD_WIDTH
    elseif side == RIGHT then
        return WIDTH/2
    end
end
function M.is_in_own_half(pad, side)
    if side == LEFT then
        return pad.x <= M.netline(side)
    elseif side == RIGHT then
        return pad.x >= M.netline(side)
    end
end
function M.is_in_the_air(pad, side)
    if side == LEFT then
        return pad.x > M.baseline(side)
    elseif side == RIGHT then
        return pad.x < M.baseline(side)
    end
end
-- check if to numbers have the same sign
function M.has_sign(a,b)
    if a > 0 then
        if b >= 0 then
            return true
        else
            return false
        end
    elseif a < 0 then
        if b <= 0 then
            return true
        else
            return false
        end
    end
end
function M.apply_volley(pad, side) -- 1 for left, -1 for right
    if pad.volley == 0 or pad.boost <= 0 then
        -- gravity effect
        if M.is_in_the_air(pad, side) then
            pad.x = pad.x - side * GRAVITY
            if not M.is_inside(pad, side) then pad.x = M.baseline(side) end
        end
    elseif pad.volley == 1 then
        -- volley effect
        if M.is_in_own_half(pad, side) and pad.boost > 0 then
            pad.x = pad.x + side * VOLLEY
            pad.boost = pad.boost - BOOST_VOLLEY
            if not M.is_in_own_half(pad, side) then
                pad.x = M.netline(side)
                -- don't lose boost if at the net
                pad.boost = pad.boost + BOOST_VOLLEY
            end
        end
    end
end

function M.apply_lateral(pad, side)
    if pad.moving == "boost_down" then
        if pad.boost >= 0 and pad.x == M.baseline(side) then
            pad.y = pad.y + PAD_SPEED * BOOST_FACTOR
            pad.boost = pad.boost - 1
        else
            pad.moving = "down"
        end
    elseif pad.moving == "boost_up" then
        if pad.boost >= 0 and pad.x == M.baseline(side) then
            pad.y = pad.y - PAD_SPEED * BOOST_FACTOR
            pad.boost = pad.boost - 1
        else
            pad.moving = "up"
        end
    end
end

function M.replenish_boost(pad, ballvx, side)
    if pad.moving == "none" and M.has_sign(ballvx, -side) and pad.x == M.baseline(side) then
        pad.boost = pad.boost + 0.5
        if pad.boost > BOOST_RESERVE then
            pad.boost = BOOST_RESERVE
        end
    end
end

function M.move(pad)
    if pad.moving == "down" then
        pad.y = pad.y + PAD_SPEED
    elseif pad.moving == "up" then
        pad.y = pad.y - PAD_SPEED
    end

    if pad.y < -PAD_HEIGHT/2 then
        pad.y = - PAD_HEIGHT/2
    elseif pad.y > HEIGHT - PAD_HEIGHT/2 then
        pad.y = HEIGHT - PAD_HEIGHT/2
    end
end

function M.solve_collision(pad, ball, side)
    if side == LEFT then
        ball.x = pad.x + PAD_WIDTH
    elseif side == RIGHT then
        ball.x = pad.x - BALL_SIZE
    end

    -- horizontal speed is increased slightly
    ball.vx = side * (math.abs(ball.vx)+IMPULSE_VX)
    if pad.volley == 1 then
        ball.vx = ball.vx + side * IMPULSE_VOLLEY
    end
    if math.abs(ball.vx) > BALL_SIZE then
        ball.vx = side * BALL_SIZE
    end
    -- difference of center heights determines vertical speed
    local center_pad_y = pad.y + PAD_HEIGHT/2
    local center_ball_y = ball.y + BALL_SIZE
    local diff =  center_ball_y - center_pad_y
    local coeff = diff/(PAD_HEIGHT/2)
    ball.vy = (coeff * math.abs(ball.vx) * 0.5773) +  3*coeff/(ball.vx*ball.vx)
end

return M
