Personagem = Class{}

function Personagem:init(x, y, r)
    self.x = x
    self.y = y
    self.r = r
    self.m = -1
end

function Personagem:update(dt)
    
end

function Personagem:render()
    love.graphics.setColor(1, 1, 1)
    love.graphics.circle('fill', self.x, self.y, self.r)
    love.graphics.line(-((math.sqrt(4 * self.m * self.m * gRAIO_FUNCAO * gRAIO_FUNCAO + 1) - 2 * self.m * self.m * self.x + 1)/(2 * self.m * self.m)), 
        -((math.sqrt(4 * self.m * self.m * gRAIO_FUNCAO * gRAIO_FUNCAO + 1) - 2 * self.m * self.y + 1)/(2 * self.m)), 
        (math.sqrt(4 * self.m * self.m * gRAIO_FUNCAO * gRAIO_FUNCAO + 1) + 2 * self.m * self.m * self.x - 1)/(2 * self.m * self.m),
        (math.sqrt(4 * self.m * self.m * gRAIO_FUNCAO * gRAIO_FUNCAO + 1) + 2 * self.m * self.y - 1)/(2 * self.m)
    ) 
end
