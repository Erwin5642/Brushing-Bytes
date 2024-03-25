EstadoTitulo = Class{__includes = EstadoBase}

function EstadoTitulo:atualizar(dt)
    if love.keyboard.wasPressed('return') or love.keyboard.wasPressed('space') then
        gStateMachine:mudar('tempo')
    end
end

function EstadoTitulo:renderizar()
    love.graphics.printf('Moon Light', 0, 60, gLARGURA_TELA, 'center')    
    love.graphics.printf('Pressione enter ou espaço para jogar!', 0, 100, gLARGURA_TELA, 'center')
end