Lua = Class {}

local GRAVITY_ACCELERATION = 20

function Lua:init()
    self.image = love.graphics.newImage('Lua-1.png')
    self.width = self.image:getWidth()
    self.height = self.image:getHeight()
    
    self.dy = 0
    self.x = LARGURA_JANELA / 2 - (self.width / 2)
    self.y = ALTURA_JANELA / 2 - (self.width / 2)    
end

function Lua:render()
    love.graphics.draw(self.image, self.x, self.y)
end

function Lua:update(dt)
    self.dy = self.dy + GRAVITY_ACCELERATION * dt
    self.y = self.y + self.dy

    if love.keyboard.wasPressed('space') then
        self.dy = -5
    end
end
