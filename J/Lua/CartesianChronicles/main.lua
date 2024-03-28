Class = require 'class'
require 'Personagem'
require 'Jogador'
require 'Inimigo'

gALTURA_TELA = 600
gLARGURA_TELA = 800
gRAIO_PERSONAGEM = 40
gRAIO_FUNCAO = 3

function love.load()
    love.window.setTitle('Cartesian Chronicles')
    love.window.setMode(gLARGURA_TELA, gALTURA_TELA, {fullscreen = false, resizable = false})
    fx = Personagem(gLARGURA_TELA / 2, gALTURA_TELA / 2, 100)
end

function love.keypressed(key)
    if key == 'scape' then
        love.event.quit()
    end
end

function love.update(dt)
    
end

function love.draw()
    fx:render()
end