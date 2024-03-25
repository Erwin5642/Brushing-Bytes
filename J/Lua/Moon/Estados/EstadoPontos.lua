EstadoPontos = Class{__includes = EstadoBase}

function EstadoPontos:entrar(parametros)
    self.score = parametros.score
end

function EstadoPontos:atualizar(dt)
    if love.keyboard.wasPressed('space') then
        gStateMachine:mudar('jogar')
    end
    if love.keyboard.wasPressed('return') then
        gStateMachine:mudar('titulo')
    end
end

function EstadoPontos:renderizar()
    love.graphics.printf('Voce perdeu...', 0, 80, gLARGURA_TELA, 'center')
    love.graphics.printf('Sua pontuacao foi: ' .. tostring(self.score), 0, 100, gLARGURA_TELA, 'center')
    love.graphics.printf('Aperte espaço para jogar de novo ou enter para voltar ao inicio', 0, 120, gLARGURA_TELA, 'center')
end