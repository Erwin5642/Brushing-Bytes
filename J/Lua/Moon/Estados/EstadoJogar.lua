EstadoJogar = Class{__includes = EstadoBase}


function EstadoJogar:init()
    self.lua = Lua()
    self.paresObstaculos = {}
    self.timer = 0
    self.score = 0
end

function EstadoJogar:atualizar(dt)
    if love.keyboard.wasPressed('return') then
        gStateMachine:mudar('pausa')
    end
    self.lua:update(dt)
end

function EstadoJogar:renderizar()    
    self.lua:render()
end

function EstadoJogar:entrar()
    gScrolling = true
end

function EstadoJogar:sair()
    gScrolling = false
end