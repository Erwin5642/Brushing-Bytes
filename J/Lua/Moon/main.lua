Class = require 'class'
require 'Lua'
require 'Obstaculo'
require 'ParObstaculo'
require 'MaquinaEstados'
require 'Estados/Base'
require 'Estados/Pausa'
require 'Estados/Titulo'
require 'Estados/Jogando'
require 'Estados/Score'
require 'Estados/Countdown'

-- Define o tamanho da janela do jogo
gALTURA_JANELA = 600
gLARGURA_JANELA = 800

local background = love.graphics.newImage('Imagens/Background-2.jpg')
local VELOCIDADE_BACKGROUND = 60
local loop_scroll = 0

function love.load()
    love.window.setMode(gLARGURA_JANELA, gALTURA_JANELA, {
        resizable = false,
        fullscreen = false
    })
    love.window.setTitle('Moon Light')
end

function love.keypreessed(key)
    if key == 'escape' then
        love.event.quit()
    end
end

function love.update(dt)
    -- Atualiza a posição do background
    loop_scroll = (loop_scroll + VELOCIDADE_BACKGROUND * dt) % background:getWidth()
end

function love.draw()
    -- Desenha o background uma vez e então desenha uma segunda vez onde a primeira imagem acaba
    love.graphics.draw(background, -loop_scroll, 0, 0, 1, gALTURA_JANELA / background:getHeight())
    love.graphics.draw(background, -loop_scroll + background:getWidth(), 0, 0, 1,
        gALTURA_JANELA / background:getHeight())
end
