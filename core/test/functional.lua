-- Functional test
local sf = require "core.multimedia.sfml"

-- create the main Window
local video_mode = sf.create_video_mode(400,400,32)
local video_settings = sf.create_context_settings(24, 8, 2)
local app = sf.create_window(video_mode,"Functional test", 6, context_settings)

-- load fonts
local font = sf.create_font(_PATH_TEST .. "arial.ttf")

if font == nil then
    print "Error loading font, exiting..."
    os.exit(-1)
end
local texts ={}
local texts_index = 1
local texts_len = 10
for i=1,texts_len do
    texts[i] = sf.create_text()
    texts[i]:set_font (font)
    texts[i]:set_size (20)
end
local text = sf.create_text()
text:set_font(font)
text:set_size(20)
local txt = "Jade Framework"
text:set_content(txt)
text:set_position(10, 270)
text:set_color(sf.create_color(0,255,0,255))
-- Load a sprite to display
local image = sf.create_texture(_PATH_TEST .. "jade.png", sf.create_color(255,255,255,255))
if image == nil then
    print "Error loading image, exiting..."
    os.exit(-1)
end
local sprite = sf.create_sprite(image)
sprite:set_texture(image)
--sprite:resize(400, 400)
sprite:set_color(sf.create_color(255,255,255,255))

-- Load a music to play
local music = sf.create_music(_PATH_TEST .. "sound.wav")
if music == nil then
    print "Music loading failed, exiting..."
    os.exit(-1)
end
music:play()

local event = sf.create_event()
local black = sf.create_color(0,0,0,255)
--while sf.sfRenderWindow_IsOpened(app) do
running = true
while running do
    --print "working"

    -- Event treatment
    while app:get_event(event) ~= 0 do
        if event[0].type == sf.sfEvtClosed then
            app:close()
            print "Exiting..."
            running = false
        elseif event[0].type == sf.sfEvtTextEntered then
            if event[0].text.unicode == 13 and txt ~= "" then
                texts[texts_index]:set_content(txt)
                texts[texts_index]:set_color(sf.create_color(255,255,255,255))
                txt=""
                texts_index = (texts_index) % texts_len +1
            elseif event[0].text.unicode == 13 then
                txt=""
            elseif event[0].text.unicode == 8 then
                txt = string.sub(txt,1,string.len(txt)-1)
            elseif event[0].text.unicode < 128 then
                txt = txt..string.char(event[0].text.unicode)
            end
            text:set_content(txt)

        end
    end

    -- Graphical display
    app:clear(black)


    app:draw(sprite)
    app:draw(text)
    for i=1,texts_len do
        texts[i]:set_position(10,i*20)
        app:draw(texts[i])
    end
    app:display()

    -- Sleep
    sf.sleep(0.02)
end

