EstadoJogar = Class{__includes = EstadoBase}

function EstadoJogar:init()
    
end

function EstadoJogar:atualizar(dt)
    if love.keyboard.wasPressed('return') then
        gStateMachine:mudar('pausa')
    end
end

function EstadoJogar:renderizar()
    
end

function EstadoJogar:entrar()
    gScrolling = true
end

function EstadoJogar:sair()
    gScrolling = false
end