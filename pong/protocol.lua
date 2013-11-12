-- register app specific events
-- will be included by both client and server to agree on events they know
-- and how they are represented in a 2 bytes form


-- definition of useful constants
LEFT = 1
RIGHT = -1
WIDTH=800
HEIGHT=600
PAD_SPEED = 3.1
PAD_WIDTH = 10
PAD_HEIGHT = 60
BALL_SIZE = 10
BALL_INIT_VX = 2
BALL_INIT_VY = 0
IMPULSE_VX = 0.5
-- IMPULSE_VY = 2/35
IMPULSE_VY = 1
IMPULSE_VOLLEY = 2
BOOST_FACTOR = 2
BOOST_RESERVE = 100
GRAVITY = 1.1
VOLLEY = 3.1
BOOST_VOLLEY = 0.5


local jade = require "core.event.jade"

-- Definition of app specific events (init and tick are the only default events)
local events = {
    "random_game", -- start a random game
    "position", -- get position of pads and balls
    "scores",   -- get scores
    "move",     -- send up or down movement of pads
    "bong",     -- get when a ball hits a pad
    "volley",   -- send volley boost
}

for _,v in pairs(events) do
    jade.create_event(v)
end


--TODO list

-- DONE Prevent pads from going out of screen completely (partially is ok!)
-- Center scores and starting pads and ball perfectly (counting their size etc.)
-- DONE Display a "Waiting for opponent" message for player_left
-- DOING(grene) Add a sound effect when the ball hits the pad or scores or hits a wall
-- DONE Make ball vertical speed somewhat proportional to horizontal speed (constant angle with batting if ball hits the same place)
-- DONE Have linear interpolation on client side to smooth things out
-- Only check network 20 times per frame (not every tick, every 3 tick)
-- DONE Create a "match object" so that more pairs of players can play!
-- Identify players prior to connecting them
-- Add effect on the ball if pad is moving while batting
-- DOING(grene) Add posibility of volley boost and lateral boost using an energy reserve that replenishes after some time
-- DONE Put a cap on the maximum horizontal speed ! BALL_SIZE is a maximum so that all collisions are properly detected.
-- Possibility of restarting a match (3 points more than the opponent or first to 10 to win)

-- DONE Correction of the "double pong" bug
-- DONE Check disconnections and clean up games where one player disconnected (might need to add connect/disconnect events in core/event/jade.lua)
-- DONE Player who loses gets the serve.
-- Warn other player if one player gets disconnected.
-- Clean up match if one player starts it then disconnects.
-- Create a "terminator" bot who knows exactly where the ball will arrive (modulo calculations!) and hits furthest to the player possible
-- DONE Add a boost counter near the pad when boost is used
-- Factorize code so that you can put pads in a loop and give only their side as arguments in functions devoted to moving them
-- Free boost bug
-- Possibility of registering 12 messages and saying them in game with F1-12 keys.
-- Put names of players, (title) and sets. 
