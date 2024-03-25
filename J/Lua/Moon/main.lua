Class = require 'class'

require 'MaquinaEstado'
require 'Estados/EstadoBase'
require 'Estados/EstadoTempo'
require 'Estados/EstadoJogar'
require 'Estados/EstadoPausa'
require 'Estados/EstadoPontos'
require 'Estados/EstadoTitulo'

require 'Lua'
require 'Obstaculo'
require 'ParObstaculo'

gLARGURA_TELA = 800
gALTURA_TELA = 600

local imagemFundo = love.graphics.newImage('Imagens/Background-2.jpg')
local VELOCIDADE_FUNDO = 60
local posicaoFundo = 0

gScrolling = true

function love.load()

    math.randomseed(os.time())

    love.window.setTitle('Moon Light')
    love.window.setMode(gLARGURA_TELA, gALTURA_TELA, {
        fullscreen = false,
        resizable = false
    })

    gStateMachine = MaquinaEstado {
        ['titulo'] = function()
            return EstadoTitulo()
        end,
        ['tempo'] = function()
            return EstadoTempo()
        end,
        ['jogar'] = function()
            return EstadoJogar()
        end,
        ['pausa'] = function()
            return EstadoPausa()
        end,
        ['pontos'] = function()
            return EstadoPontos()
        end
    }

    gStateMachine:mudar('titulo')

    love.keyboard.keysPressed = {}
end

function love.keypressed(key)
    love.keyboard.keysPressed[key] = true

    if key == 'escape' then
        love.event.quit()
    end
end

function love.keyboard.wasPressed(key)
    return love.keyboard.keysPressed[key]
end

function love.update(dt)
    if gScrolling then
        posicaoFundo = (posicaoFundo + VELOCIDADE_FUNDO * dt) % imagemFundo:getWidth()
    end

    gStateMachine:atualizar(dt)
    love.keyboard.keysPressed = {}
end

function love.draw()
    love.graphics.draw(imagemFundo, -posicaoFundo, 0, 0, 1, gALTURA_TELA / imagemFundo:getHeight())
    love.graphics.draw(imagemFundo, -posicaoFundo + imagemFundo:getWidth(), 0, 0, 1,
        gALTURA_TELA / imagemFundo:getHeight())
    gStateMachine:renderizar()
end