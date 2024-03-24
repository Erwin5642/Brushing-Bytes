Obstaculo = Class{}

local OBSTACULO_IMAGEM = love.graphics.newImage('Predio.png')
local VELOCIDADE_OBSTACULO = -60

function Obstaculo:init()
    self.x = LARGURA_JANELA
    self.y = math.random(ALTURA_JANELA / 4, ALTURA_JANELA - 50)
    self.width = OBSTACULO_IMAGEM:getWidth()
end

function Obstaculo:update(dt)
    self.x = self.x + VELOCIDADE_OBSTACULO * dt
end

function Obstaculo:render()
    love.graphics.draw(OBSTACULO_IMAGEM, self.x, self.y, 0, LARGURA_JANELA/OBSTACULO_IMAGEM:getWidth(), ALTURA_JANELA/OBSTACULO_IMAGEM:getHeight())
end