-- Define o estado score como uma classe filha do estado base
EstadoScore = Class {
    __includes = EstadoBase
}

-- Define a pontuação de acordo com o pontos conseguidos de estado jogar
function EstadoScore:enter(parametros)
    self.score = parametros.score
end

-- Volta para o estado jogar se a tecla enter ou espaco for apertada 
-- volta para o titulo se return for apertado
function EstadoScore:update(dt)
    if love.keyboard.wasPressed('enter') or love.keyboard.wasPressed('space') then
        gMaquinaEstados:change('countdown')
    elseif love.keyboard.wasPressed('return') then
        gMaquinaEstados:change('titulo')
    end
end

-- Mostra a pontuação obtida e uma mensagem
function EstadoScore:render()
    love.graphics.printf('Voce perdeu!', 0, 64, gLARGURA_JANELA, 'center')
    love.graphics.printf('Pontuacao: ' .. tostring(self.score), 0, 100, gLARGURA_JANELA, 'center')
    love.graphics.printf('Pressione enter para jogar novamente ou pressione return para voltar ao titulo', 0, 160,
        gLARGURA_JANELA, 'center')
end
