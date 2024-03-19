Bola = Class{}

function Bola:init(x, y, largura, altura)
    self.x = x
    self.y = y
    self.largura = largura
    self.altura = altura

    self.dx = math.random(2) == 1 and 100 or -100
    self.dy = math.random(-50, 50)
end 

function Bola:reset()
    self.x = LARGURA_JANELA / 2 - 2
    self.y = ALTURA_JANELA / 2 - 2 
end

function Bola:update(dt)
    
    
    self.x = self.x + self.dx * dt

    self.y = self.y + self.dy * dt
end

function Bola:render()
    love.graphics.rectangle('fill', self.x, self.y, self.largura, self.altura)
end