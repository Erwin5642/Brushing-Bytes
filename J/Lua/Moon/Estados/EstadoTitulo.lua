-- Define o estado tiitulo como uma classe filha do estado base
EstadoTitulo = Class {
    __includes = EstadoBase
}

function EstadoTitulo:init()
    -- sem necessidade de mudanças
end

-- Muda de estado caso o usuário aperte enter ou espaço
function EstadoTitulo:update(dt)
    if love.keyboard.wasPressed('enter') or love.keyboard.wasPressed('space') then
        gMaquinaEstados:change('countdown')
    end
end

-- Mostra o titulo do jogo e uma mensagem para o usuário
function EstadoTitulo:render()
    love.graphics.printf('Moon Light', 0, 64, gLARGURA_JANELA, 'center')
    love.graphics.printf('Pressione enter para jogar', 0, 100, gLARGURA_JANELA, 'center')
end
