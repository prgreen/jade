-- sprite music videosettings videomode

local M = {}

local ffi = require "ffi"
local core = require "core.core"
--[[if not _CLIENT then
    core.load_header("ffi_sfml.h")
end
]]--
--TODO check Windows equivalent
ffi.cdef("unsigned int sleep(unsigned int seconds);")

local sf = core.load_lib('csfml-graphics-2')

local sf_sys = core.load_lib('csfml-system-2', true)
--local sf_win = ffi.load(sfml_path..'libcsfml-window.so')
--setmetatable(M, {__index = enet})
local sf_aud = core.load_lib('csfml-audio-2')


setmetatable(M, {__index = sf})
M.sf_aud = sf_aud
M.sf_sys = sf_sys


-- type definitions
M.window = {}
--- (METHOD) Clear the window with a color.
function M.window.clear(window, color)
    return  M.clear_window(window, color)
end
--- (METHOD) Display the window.
function M.window.display(window)
    return M.display_window(window)
end
--- (METHOD) Close the window.
function M.window.close(window)
    return M.close_window(window)
end
--- (METHOD) Draw text OR image inside the window.
function M.window.draw(window, thing)
    if ffi.istype("sfText*", thing) then
        M.draw_text(window, thing)
    elseif ffi.istype("sfSprite*", thing) then
        M.draw_sprite(window, thing)
    elseif ffi.istype("sfRectangleShape*", thing) then
        M.draw_rectangle(window, thing)
    end
end
--- (METHOD) Pump an event happening within the window.
-- Use this in a while loop to get all events one by one.
-- @param window self
-- @param event gets replaced with an event in the event queue.
function M.window.get_event(window, event)
    return M.get_event(window, event)
end
--- (METHOD) Set the icon of the window from the path of an image
function M.window.set_icon(window, icon)
	local i = sf.sfImage_createFromFile(icon)
	
    return sf.sfRenderWindow_setIcon(window, sf.sfImage_getSize(i).x, sf.sfImage_getSize(i).y, sf.sfImage_getPixelsPtr(i))
end
ffi.metatype("sfRenderWindow",{__index = M.window})

M.text = {}
--- (METHOD) Set font of a text.
function M.text.set_font(text, font)
    sf.sfText_setFont(text, font)
end
--- (METHOD) Set size of a text.
function M.text.set_size(text, size)
    sf.sfText_setCharacterSize(text, size)
end
--- (METHOD) Set string content of a text.
function M.text.set_content(text, str)
    sf.sfText_setString(text, str)
end    
--- (METHOD) Set color of a text.
function M.text.set_color(text, color)
    sf.sfText_setColor(text, color)
end
--- (METHOD) Set position of a text.
function M.text.set_position(text, x, y)
	local v = ffi.new("sfVector2f")
	v.x = x
	v.y = y
    sf.sfText_setPosition(text, v)
end
ffi.metatype("sfText", {__index = M.text})

M.sprite = {}
--- (METHOD) Set texture of a sprite.
function M.sprite.set_texture(sprite, texture)
    sf.sfSprite_setTexture(sprite, texture, 1)
end
--- (METHOD) Set part of a texture to a sprite.
function M.sprite.set_texture_rect(sprite, texture, left, top, width, height)
	local r = ffi.new("sfIntRect")
	r.left = left
	r.top = top
	r.width = width
	r.height = height
    sf.sfSprite_setTextureRect(sprite, texture, r)
end
--- (METHOD) Resize a sprite.
--[[
function M.sprite.resize(sprite, x, y)
    sf.sfSprite_Resize(sprite, x, y)
end
]]--
--- (METHOD) Set color of a sprite.
function M.sprite.set_color(sprite, color)
    sf.sfSprite_setColor(sprite, color)
end
--- (METHOD) Set position of a sprite.
function M.sprite.set_position(sprite, x, y)
	local v = ffi.new("sfVector2f")
	v.x = x
	v.y = y
    sf.sfSprite_setPosition(sprite, v)
end
ffi.metatype("sfSprite", {__index = M.sprite})

M.music = {}
--- (METHOD) Play a music.
function M.music.play(music)
    return M.play_music(music)
end
--- (METHOD) Stop a music.
function M.music.stop(music)
    return M.stop_music(music)
end
ffi.metatype("sfMusic", {__index = M.music})

M.texture = {}
--- (METHOD) Get size of a texture (2d vector with x y components).
function M.texture.get_size(texture)
    return sf.sfTexture_getSize(texture)
end
ffi.metatype("sfTexture", {__index = M.texture})

-- WINDOW

--- Create a video_mode object to be used by M.create_window.
-- @param width Width of the window (in pixels, default: 800).
-- @param height Height of the window (in pixels, default: 600).
-- @param bpp Bits per pixel (default: 32).
function M.create_video_mode(width, height, bpp)
    if type(width) == "nil" then local width = 800 end
    if type(height) == "nil" then local height = 600 end
    if type(bpp) == "nil" then local bpp = 32 end
    return ffi.new("sfVideoMode",width,height,bpp)
end

--- Create a video_settings object to be used by M.create_window.
-- @param depth Bits of the depth buffer (default: 24).
-- @param stencil Bits of the stencil buffer (default: 8).
-- @param antialiasing Level of the antialiasing (default: 0).
function M.create_context_settings(depth, stencil, antialiasing)
    if type(depth) == "nil" then local depth = 24 end
    if type(stencil) == "nil" then local stencil = 8 end
    if type(antialiasing) == "nil" then local antialiasing = 0 end
    return ffi.new("sfContextSettings", depth, stencil, antialiasing, 2, 0)
end

--- Create a window for graphical applications.
-- Use M.create_video_mode and M.create_video_settings to build the arguments for this function.
-- @param video_mode Video mode object.
-- @param title String object, title of the window (if not fullscreen).
-- @param style Style of the window (resizeable, closeable, fullscreen) TO BE IMPLEMENTED.
-- @param video_settings Video settings object.
-- @return Window object.
function M.create_window(video_mode, title, style, context_settings)
    -- TODO check whether we can detect nil arguments !
    local ret =  ffi.gc(sf.sfRenderWindow_create(video_mode, title, style, context_settings), sf.sfRenderWindow_destroy)

    sf.sfRenderWindow_setKeyRepeatEnabled(ret, 0)
    return ret
end

--- Clear window before drawing.
function M.clear_window(window, color)
    if type(color) == "nil" then local color = M.create_color() end
    sf.sfRenderWindow_clear(window, color)
end

--- Display window after drawing.
function M.display_window(window)
    sf.sfRenderWindow_display(window)
end

--- Close a window.
function M.close_window(window)
    sf.sfRenderWindow_close(window)
end

--- Draw a text inside a window. (Use app:draw instead)
-- @param window Window on which the text will be drawn.
-- @param txt Text object obtained through M.create_text.
function M.draw_text(window, txt)
    sf.sfRenderWindow_drawText(window, txt, ffi.cast("void*",0))
end

--- Draw a sprite inside a window. (Use app:draw instead)
-- @param window Window on which the sprite will be drawn.
-- @param spr Sprite object obtained through M.create_sprite.
function M.draw_sprite(window, spr)
    sf.sfRenderWindow_drawSprite(window, spr, ffi.cast("void*",0))
end

--- Draw a shape inside a window. (Use app:draw instead)
-- @param window Window on which the shape will be drawn.
-- @param shape Rectangle object
function M.draw_rectangle(window, rect)
    sf.sfRenderWindow_drawRectangleShape(window, rect, ffi.cast("void*",0))
end

--- Sleep for a certain amount of time (in seconds)
function M.sleep(t)
    M.sf_sys.sfSleep(ffi.new("sfTime",t*1000000))
end

--- Create an event object.
function M.create_event()
    return ffi.new("sfEvent[1]")
end

--- Get events happening on a window.
-- Use inside a while loop.
-- @param window Window object.
-- @param event Event object.
-- @return One event is pumped from the event queue and placed in the event variable, returns true if an event was pumped.
function M.get_event(window, event)
    return sf.sfRenderWindow_pollEvent(window, event)
end
-- GRAPHICS

--- Create a font object from a ttf file.
function M.create_font(path)
    --TODO check for errors during creation
    return ffi.gc(sf.sfFont_createFromFile(path), sf.sfFont_destroy)
end

--- Create a color object.
function M.create_color(r, g, b, a)
    if type(r) == "nil" then local r = 0 end
    if type(g) == "nil" then local g = 0 end
    if type(b) == "nil" then local b = 0 end
    if type(a) == "nil" then local a = 255 end
    return ffi.new("sfColor", r, g, b, a)
end
--- Create a text object to be displayed. Don't forget to create a font and associate it with the text!
function M.create_text(content, pos, color)
    local ret = ffi.gc(sf.sfText_create(), sf.sfText_destroy)
    sf.sfText_setString(ret, content)
	local p = ffi.new("sfVector2f", pos and pos[1] or 0, pos and pos[2] or 0)
    sf.sfText_setPosition(ret, p)
    sf.sfText_setColor(ret, color and color or ffi.new("sfColor",255,255,255,255))
    return ret
end

--- Create a texture object to be used by M.create_sprite.
-- @param path Path of an image (.jpg, .png, ...).
-- @param mask_color Color made transparent for non-rectangular images with colored background (optional).
function M.create_texture(path, mask_color)
    --TODO error checking
    local ret = ffi.gc(sf.sfTexture_createFromFile(path, nil),sf.sfTexture_destroy)
    --[[if type(mask_color) ~= "nil" then
        sf.sfTexture_createMaskFromColor(ret, mask_color, 0)
    end]]--
	
	-- TODO transparency ?
    return ret
end

--- Create a sprite object to be displayed.
function M.create_sprite(texture,pos)
    local ret = ffi.gc(sf.sfSprite_create(),sf.sfSprite_destroy)
    sf.sfSprite_setTexture(ret, texture, 1)
	local p = ffi.new("sfVector2f", pos and pos[1] or 0, pos and pos[2] or 0)
    sf.sfSprite_setPosition(ret, p)

    return ret
end
--- Create a rectangle shape to be displayed.
function M.create_rectangle(x1, y1, x2, y2, color) -- TODO make sure x1 > x2 and y1 > y2
	local rect = ffi.gc(sf.sfRectangleShape_create(), sf.sfRectangleShape_destroy)
	sf.sfRectangleShape_setPosition(rect, ffi.new("sfVector2f", x1, y1))
	sf.sfRectangleShape_setSize(rect, ffi.new("sfVector2f", x2-x1, y2-y1))
	sf.sfRectangleShape_setFillColor(rect, color)
    return rect
end


--AUDIO

--- Create music object to be played from a music file (.wav, .ogg, ...).
function M.create_music(path)
    return ffi.gc(M.sf_aud.sfMusic_createFromFile(path), M.sf_aud.sfMusic_destroy)
end

--- Play a music object.
function M.play_music(music)
   M.sf_aud.sfMusic_play(music) 
end

--- Stop a music object.
function M.stop_music(music)
    M.sf_aud.sfMusic_stop(music)
end

return M
