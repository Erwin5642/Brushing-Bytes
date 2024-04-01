Class = require 'class'

require 'Personagem'
require 'Classes/ClasseBase'
require 'Classes/ClasseBase'
require 'Classes/Linear'
require 'Classes/Constante'

require 'Jogador'
require 'Inimigo'

gALTURA_TELA = 600
gLARGURA_TELA = 800
gRAIO_PERSONAGEM = 40
gRAIO_FUNCAO = 160

function love.load()
    love.window.setTitle('Cartesian Chronicles')
    love.window.setMode(gLARGURA_TELA, gALTURA_TELA, {
        fullscreen = false,
        resizable = false
    })
    fx = Personagem(gLARGURA_TELA / 2, gALTURA_TELA / 2, gRAIO_PERSONAGEM, {
        ['linear'] = function()
            return Linear()
        end,
        ['constante'] = function()
            return Constante()
        end
    })

    fx:define('constante')

end

function love.keypressed(key)
    if key == 'escape' then
        love.event.quit()
    end
end

function love.update(dt)

end

function love.draw()
    fx:render()
end
