Constante = Class{__includes = ClasseBase}

function Constante:init()
    self.dominante = 'y'
end

function Constante:renderF(x, y)
    if self.dominante == 'x' then
        love.graphics.line(x, y - gRAIO_FUNCAO, x, y + gRAIO_FUNCAO)
    else
        love.graphics.line(x - gRAIO_FUNCAO, y, x + gRAIO_FUNCAO, y)
    end
end

function Constante:renderE()
    love.graphics.rectangle('fill', 0, gALTURA_TELA - 50, gLARGURA_TELA, 50)
    love.graphics.setColor(0, 0, 0, 1)
    love.graphics.printf(self.dominante .. ' = 1', 0, gALTURA_TELA - 45, gLARGURA_TELA, 'center')
end
