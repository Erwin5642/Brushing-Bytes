Class = require 'class'
require 'Jogador'
require 'Bola'
require 'conf'

VELOCIDADE = 200

function love.load()
    JEsq = Jogador(10, 30, 5, 20)
    JDir = Jogador(LARGURA_JANELA - 10, ALTURA_JANELA - 30, 5, 20)
    B = Bola(LARGURA_JANELA/2 - 2, ALTURA_JANELA / 2 - 2, 4, 4)

    GameState = 'star'
end

function love.update(dt)
    function love.keypressed(key)
        if key == 'scape' then
            love.event.quit()
        end

        if key == 'space' then
            if GameState == 'start' then
                GameState = 'play'
            else
                GameState = 'start'
                B:reset()
            end
        end
    end

    if love.keyboard.isDown('w') then
        JEsq = -VELOCIDADE
    elseif love.keyboard.isDown('s') then
        JEsq = VELOCIDADE
    else
        JEsq = 0
    end

    if love.keyboard.isDown('up') then
        JEsq = -VELOCIDADE
    elseif love.keyboard.isDown('down') then
        JEsq = VELOCIDADE
    else
        JEsq = 0
    end

    if GameState == 'play' then
        B:update(dt)
    end
    JEsq:update(dt)
    JDir:update(dt)
end

function love.draw()
    JEsq:render()
    JDir:render()
    B:render()
end