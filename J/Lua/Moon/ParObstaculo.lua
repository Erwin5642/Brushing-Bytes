ParObstaculo = Class{}

-- Distancia entre os obstaculos
local GAP = 200

function ParObstaculo:init(y)
    self.scored = false

    self.x = gLARGURA_TELA + 32

    self.y = y

    self.obstaculos = {
        ['upper'] = Obstaculo('top', self.y),
        ['lower'] = Obstaculo('bottom', self.y + ALTURA_OBSTACULO + GAP)
    }

    self.remova = false
end

function ParObstaculo:update(dt)
    if self.x > -LARGURA_OBSTACULO then
        self.x = self.x - VELOCIADE_OSBTACULO * dt
        self.obstaculos['lower'].x = self.x
        self.obstaculos['upper'].x = self.x
    else
        self.remova = true
    end
end

function ParObstaculo:render()
    for l, obstaculo in pairs(self.obstaculos) do
        obstaculo:render()
    end
end