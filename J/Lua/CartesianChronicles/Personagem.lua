Personagem = Class{}

function Personagem:init(x, y, r)
    self.x = x
    self.y = y
    self.r = r
end

function Personagem:update(dt)
    
end

function Personagem:render()
    love.graphics.setColor(1, 1, 1)
    love.graphics.circle('fill', self.x, self.y, self.r)
end
