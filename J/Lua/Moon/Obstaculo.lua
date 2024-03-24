Obstaculo = Class{}

local imagem = love.graphics.newImage('Imagens/Predio.png')

function Obstaculo:init(y, orientacao)
    self.x = gLARGURA_JANELA
    self.y = y
    self.orientacao = orientacao
    self.scored = false
end

function Obstaculo:update(dt)

end

function Obstaculo:render()
    love.graphics.draw(imagem, self.x, self.y, 0, 1, self.orientacao == 'top' and -1 or 1)
end