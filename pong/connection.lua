-- module used to negotiate a game
-- plugged out at then of the program
local M = {}

local jade = require "core.event.jade"
local sf = require "core.multimedia.sfml"

function M.init()
    jade.trigger(jade.event.random_game, M.receive_side)
    M.init_mainloop()
    M.start_random_game()
end
function M.exit()
    print "exiting..."
end

function M.init_mainloop()
    -- there's too much to do, so mainloop gets its own module
    jade.plug_in(W, "mainloop")
end

function M.start_random_game()
    -- Ask server which side we get
    jade.send_event(server,jade.event.random_game) 
    -- left, right, or no empty place left...
end

function M.receive_side(ev)
    local t = jade.get_data(ev)
    local side = t.side
    --print (side)

    if side == "left" then
        local text = sf.create_text("Please wait for your opponent (or press B to play against a bot)", {50,50}, sf.create_color(255,255,255,255))
		text:set_size(20)
        text:set_font(W.mainloop.font)
        table.insert(W.mainloop.to_draw, text)
        
    end
    W.mainloop.side = side 
end


return M
