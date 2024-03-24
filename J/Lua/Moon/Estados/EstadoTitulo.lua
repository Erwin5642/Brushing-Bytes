--Define o estado tiitulo como uma classe filha do estado base
EstadoTitulo = Class{__includes = EstadoBase}

function EstadoTitulo:init()
    --sem necessidade de mudanças
end

function EstadoTitulo:update(dt)
    if love.keyboard.wasPressed('enter') or love.keyboard.wasPressed('space') then
        gMaquinaEstados:change('countdown')
    end
end

function EstadoTitulo:render()
    love.graphics.printf('Moon Light', 0, 64, gLARGURA_JANELA, 'center')
    love.graphics.printf('Pressione enter para jogar', 0, 100, gLARGURA_JANELA, 'center')
end
