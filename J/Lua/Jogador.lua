Jogador = Class{}

function Jogador:init(x, y, largura, altura)
    self.x = x
    self.y = y
    self.largura = largura
    self.altura = altura

    self.dy = 0
end

function Jogador:update(dt)
    if self.dy < 0 then
        self.y = math.max(0, self.y + self.dy * dt)
    else
        self.y = math.min(ALTURA_JANELA - self.altura, self.y + self.dy * dt)
    end
end

function Jogador:render()
    love.graphics.rectangle('fill', self.x, self.y, self.largura, self.altura)
end
