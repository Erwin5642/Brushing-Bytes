Class = require 'class'
require 'Jogador'
require 'Bola'
require 'conf'

VELOCIDADE = 200

function love.load()
    math.randomseed(os.time())

    J1 = Jogador(10, 30, 5, 20)
    J2 = Jogador(LARGURA_JANELA - 10, ALTURA_JANELA - 30, 5, 20)
    B = Bola(LARGURA_JANELA / 2 - 2, ALTURA_JANELA / 2 - 2, 4, 4)

    GameState = 'start'
end

function love.update(dt)
    function love.keypressed(key)
        if key == 'escape' then
            love.event.quit()
        elseif key == 'space' then
            if GameState == 'start' then
                GameState = 'play'
            else
                GameState = 'start'
                B:reset()
            end
        end
    end

    if love.keyboard.isDown('w') then 
        J1.dy = -VELOCIDADE
    elseif love.keyboard.isDown('s') then 
        J1.dy = VELOCIDADE
    else
        J1.dy = 0
    end

    if love.keyboard.isDown('up') then 
        J2.dy = -VELOCIDADE
    elseif love.keyboard.isDown('down') then 
        J2.dy = VELOCIDADE
    else
        J2.dy = 0
    end

    if GameState == 'play' then
        B:update(dt)
    end 
    J1:update(dt)
    J2:update(dt)
end

function love.draw()
    J1:render()
    J2:render()
    B:render()
end