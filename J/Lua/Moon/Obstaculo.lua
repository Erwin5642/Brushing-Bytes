Obstaculo = Class {}

local imagem = love.graphics.newImage('Imagens/Predio.png')

function Obstaculo:init(y, orientacao)
    self.x = gLARGURA_TELA
    self.y = y

    self.width = LARGURA_OBSTACULO
    self.height = ALTURA_OBSTACULO

    self.orientacao = orientacao
end

function Obstaculo:render()
    love.graphics.draw(imagem, self.x, 
        (self.orientation == 'top' and self.y + ALTURA_OBSTACULO or self.y), 
        0, 1, self.orientation == 'top' and -1 or 1)
end
