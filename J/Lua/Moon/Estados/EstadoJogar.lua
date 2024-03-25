EstadoJogar = Class {
    __includes = EstadoBase
}

VELOCIADE_OSBTACULO = 60
LARGURA_OBSTACULO = 100
ALTURA_OBSTACULO = 255

ALTURA_LUA = 16
LARGURA_LUA = 16

function EstadoJogar:init()
    self.lua = Lua()
    self.paresObstaculos = {}
    self.timer = 0
    self.score = 0

    self.ultimoY = -ALTURA_OBSTACULO + math.random(80) + 20
end

function EstadoJogar:atualizar(dt)
    if love.keyboard.wasPressed('return') then
        gStateMachine:mudar('pausa')
    end

    self.timer = self.timer + dt

    if self.timer > 2 then
        local y = math.max(-ALTURA_OBSTACULO + 10,
            math.min(self.ultimoY + math.random(-20, 20), gALTURA_TELA - 90 - ALTURA_OBSTACULO))
        self.ultimoY = y

        table.insert(self.paresObstaculos, ParObstaculo(y))
        self.timer = 0
    end

    for k, par in pairs(self.paresObstaculos) do
        if not par.scored then
            if par.x + LARGURA_OBSTACULO < self.lua.x then
                self.score = self.score + 1
                par.scored = true
            end
        end
        par:update(dt)
    end

    for k, par in pairs(self.paresObstaculos) do
        if par.remova then
            table.remove(self.paresObstaculos, k)
        end
    end

    for k, par in pairs(self.paresObstaculos) do
        for l, obstaculo in pairs(par.obstaculos) do
            if self.lua:colide(obstaculo) then
                gStateMachine:mudar('pontos', {score = self.score})
            end
        end
    end

    self.lua:update(dt)

    if self.lua.y > gALTURA_TELA - 15 then
       
        gStateMachine:mudar('pontos', {
            score = self.score
        })
    end
end

function EstadoJogar:renderizar()
    for k, par in pairs(self.paresObstaculos) do
        par:render()
    end

    love.graphics.printf('Pontos: ' .. tostring(self.score), 8, 8, gLARGURA_TELA)
    self.lua:render()
end

function EstadoJogar:entrar()
    gScrolling = true
end

function EstadoJogar:sair()
    gScrolling = false
end
