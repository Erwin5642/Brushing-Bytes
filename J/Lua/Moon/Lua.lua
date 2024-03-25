Lua = Class{}

local VELOCIDADE_GRAVIDADE = 30

--Objetivo: construtor da classe Lua
function Lua:init()
    --Linka a imagem do jogador com a sua classe
    self.imagem = love.graphics.newImage('Imagens/Lua-1.png')
    --Coloca o jogador no meio da janela 
    self.x = gLARGURA_TELA/2 - 8
    self.y = gALTURA_TELA/2 - 8  
    self.dy = 0
end

--Objetivo: implementa a movimentação do jogador
function Lua:update(dt)
    --Altera a velocidade do jogador na medida em que o tempo passa e atualiza a sua posição
    self.dy = self.dy + VELOCIDADE_GRAVIDADE * dt

    if love.keyboard.wasPressed('space') then
        self.dy = -10
    end

    self.y = self.y + self.dy    
end

--Objetivo: passa os parametros para desenhar o jogador na tela
function Lua:render()
    --Desenha o jogador na tela
    love.graphics.draw(self.imagem, self.x, self.y)
end
