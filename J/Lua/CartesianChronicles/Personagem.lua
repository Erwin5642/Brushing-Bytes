Personagem = Class {}

gVELOCIDADE_PERSONAGEM = 200


function Personagem:init(x, y, r, classe)
    self.x = x
    self.y = y
    self.r = r
    self.vazia = {
        renderF = function()
        end,
        renderE = function()
        end
    }
    self.classe = classe or {}
    self.atual = self.vazia
end

function Personagem:define(nomeClasse)
    assert(self.classe[nomeClasse])
    self.atual = self.classe[nomeClasse]()
end

function Personagem:renderE()
    self.atual:renderE()
end

function Personagem:renderF(x, y)  
    self.atual:renderF(x, y)
end

function Personagem:render()
    love.graphics.setColor(1, 1, 1)
    love.graphics.circle('fill', self.x, self.y, self.r)
    self.atual:renderF(self.x, self.y)
end
