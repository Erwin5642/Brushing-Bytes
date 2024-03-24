ParObstaculo = Class{}

local GAP = 90

function ParesObstaculo:init(y)
    self.x = LARGURA_JANELA + 32
    self.y = y

    self.obstaculos = {
        ['upper'] = Obstaculo('top', self.y)
        ['lower'] = Obstaculo('bottom', self.y + ALTURA_OBSTACULO + GAP)
    }
    self.remove = false
end

function ParObstaculo:update(dt)


end