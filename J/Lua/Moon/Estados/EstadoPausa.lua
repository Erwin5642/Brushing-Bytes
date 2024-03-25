EstadoPausa = Class{__includes = EstadoBase}

function EstadoPausa:atualizar(dt)
    if love.keyboard.wasPressed('return') then
        gStateMachine:mudar('jogar')
    end
end 

function EstadoPausa:renderizar()
    love.graphics.printf('Jogo pausado', 0, 120, gLARGURA_TELA, 'center')
end
