Linear = Class {
    __includes = ClasseBase
}

function Linear:init()
    self.dominante = 'y'
    self.independente = 'x'
    self.m = 1
end

function Linear:renderF(x, y)
    if self.dominante == 'x' then
        love.graphics.line(-((math.sqrt(4 * self.m * self.m * gRAIO_FUNCAO * gRAIO_FUNCAO + 1) - 2 * self.m * x + 1) /
                               (2 * self.m)),
            -((math.sqrt(4 * self.m * self.m * gRAIO_FUNCAO * gRAIO_FUNCAO + 1) - 2 * self.m * self.m * y + 1) /
                (2 * self.m * self.m)),
            (math.sqrt(4 * self.m * self.m * gRAIO_FUNCAO * gRAIO_FUNCAO + 1) + 2 * self.m * x - 1) / (2 * self.m),
            (math.sqrt(4 * self.m * self.m * gRAIO_FUNCAO * gRAIO_FUNCAO + 1) + 2 * self.m * self.m * y - 1) /
                (2 * self.m * self.m))
    else
        love.graphics.line(
            -((math.sqrt(4 * self.m * self.m * gRAIO_FUNCAO * gRAIO_FUNCAO + 1) - 2 * self.m * self.m * x + 1) /
                (2 * self.m * self.m)),
            -((math.sqrt(4 * self.m * self.m * gRAIO_FUNCAO * gRAIO_FUNCAO + 1) - 2 * self.m * y + 1) / (2 * self.m)),
            (math.sqrt(4 * self.m * self.m * gRAIO_FUNCAO * gRAIO_FUNCAO + 1) + 2 * self.m * self.m * x - 1) /
                (2 * self.m * self.m),
            (math.sqrt(4 * self.m * self.m * gRAIO_FUNCAO * gRAIO_FUNCAO + 1) + 2 * self.m * y - 1) / (2 * self.m))
    end
end

function Linear:renderE()
    love.graphics.rectangle('fill', 0, gALTURA_TELA - 50, gLARGURA_TELA, 50)
    love.graphics.setColor(0, 0, 0, 1)
    love.graphics.printf(self.dominante .. ' = ' .. tostring(-self.m) .. self.independente, 0, gALTURA_TELA - 45,
        gLARGURA_TELA, 'center')
end
