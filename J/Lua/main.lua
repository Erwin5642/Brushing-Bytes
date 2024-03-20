--Funcionamento das classes
Class = require 'class'
require 'Jogador'
require 'Bola'
require 'conf'

Jogador_Velocidade = 200
--Inicializado no começo da aplicação
function love.load()
    --Define um seed de números aleatórios
    math.randomseed(os.time())

    --Incializa os atributos dos dois jogadores e da bola
    J1 = Jogador(10, 30, 5, 20)
    J2 = Jogador(LARGURA_JANELA - 10, ALTURA_JANELA - 30, 5, 20)
    Bola = Bola(LARGURA_JANELA / 2 - 2, ALTURA_JANELA / 2 - 2, 4, 4)

    --variaveis da pontuação
    pontuacaoJ1 = 0
    pontuacaoJ2 = 0
    jogadorSaque = 1
    JogadorVencedor = 0

    -- Estados de jogo:
    -- 1. 'comeco' 
    -- 2. 'saque' 
    -- 3. 'jogar' 
    -- 4. 'fim de jogo' 
    gameState = 'comeco'
end

--Atualiza a cada frame do jogo
function love.update(dt)
    if gameState == 'saque' then
        Bola.dy = math.random(-50, 50)
        if jogadorSaque == 1 then
            Bola.dx = math.random(140, 200)
        else
            Bola.dx = -math.random(140, 200)
        end
    elseif gameState == 'jogar' then

        --Colisão da bola com o jogador 1
        if Bola:collides(J1) then

            Bola.dx = -Bola.dx * 1.03
            Bola.x = J1.x + 5

            if Bola.dy < 0 then
                Bola.dy = -math.random(10, 150)
            else
                Bola.dy = math.random(10, 150)
            end
        end

        --Colisão da bola com o jogador 2
        if Bola:collides(J2) then

            Bola.dx = -Bola.dx * 1.03
            Bola.x = J2.x - 4

            -- keep velocity going in the same direction, but randomize it
            if Bola.dy < 0 then
                Bola.dy = -math.random(10, 150)
            else
                Bola.dy = math.random(10, 150)
            end
        end

        --Inversão da direção da bola no contato com o teto
        if Bola.y <= 0 then
            Bola.y = 0
            Bola.dy = -Bola.dy
        end

        --Inversão da direção da bola no contato com o chão
        if Bola.y >= ALTURA_JANELA - 4 then
            Bola.y = ALTURA_JANELA - 4
            Bola.dy = -Bola.dy
        end

        --Atualiza a pontuação do jogador 2 caso a bola atinga o limite esquerdo
        if Bola.x < 0 then
            jogadorSaque = 1
            pontuacaoJ2 = pontuacaoJ2 + 1

            --Determina se o jogo acabou e muda o estado de jogo
            if pontuacaoJ2 == 10 then
                JogadorVencedor = 2
                gameState = 'fim de jogo'
            else
                gameState = 'saque'
                --Reseta a bola
                Bola:reset()
            end
        end

        --Atualiza a pontuação do jogador 2 caso a bola atinga o limite direito
        if Bola.x > LARGURA_JANELA then
            jogadorSaque = 2
            pontuacaoJ1 = pontuacaoJ1 + 1

            if pontuacaoJ1 == 10 then
                JogadorVencedor = 1
                gameState = 'fim de jogo'
            else
                gameState = 'saque'
                Bola:reset()
            end
        end
    end

    --Movimento vertical do jogador 1
    if love.keyboard.isDown('w') then
        J1.dy = -Jogador_Velocidade
    elseif love.keyboard.isDown('s') then
        J1.dy = Jogador_Velocidade
    else
        J1.dy = 0
    end

    --Movimento vertical do jogador 2
    if love.keyboard.isDown('up') then
        J2.dy = -Jogador_Velocidade
    elseif love.keyboard.isDown('down') then
        J2.dy = Jogador_Velocidade
    else
        J2.dy = 0
    end

    --Atualiza a posição da bola quando em meio a um jogo
    if gameState == 'jogar' then
        Bola:update(dt)
    end

    --Atualiza a posição dos jogadores com base nos inputs
    J1:update(dt)
    J2:update(dt)
end

function love.keypressed(key)
    if key == 'escape' then
        --Se esc for pressionada sai da aplicação
        love.event.quit()
    elseif key == 'enter' or key == 'return' then
        if gameState == 'comeco' then
            --Se estiver no começo vai para o saque
            gameState = 'saque'
        elseif gameState == 'saque' then
            --Se confirmar o saque começará o jogo 
            gameState = 'jogar'
        elseif gameState == 'fim de jogo' then
            gameState = 'saque'
            --Se a rodada acabou começa um novo saque
            Bola:reset()

            -- Reseta a pontuação
            pontuacaoJ1 = 0
            pontuacaoJ2 = 0

            -- O jogador perdedor começa sacando
            if JogadorVencedor == 1 then
                jogadorSaque = 2
            else
                jogadorSaque = 1
            end
        end
    end
end

--Desenha na tela os objetos do jogo e textos
function love.draw()
    if gameState == 'comeco' then
        -- Mensagens do inicio
        love.graphics.printf('Bem vindo ao Pong!', 0, 10, LARGURA_JANELA, 'center')
        love.graphics.printf('Pressione enter para começar!', 0, 20, LARGURA_JANELA, 'center')
    elseif gameState == 'saque' then
        -- Mensagens no saque
        love.graphics.printf('jogador ' .. tostring(jogadorSaque) .. "' saca!", 
            0, 10, LARGURA_JANELA, 'center')
        love.graphics.printf('Pressione Enter para sacar!', 0, 20, LARGURA_JANELA, 'center')
    elseif gameState == 'jogar' then
        -- Sem mensagens ao jogar
    elseif gameState == 'fim de jogo' then
        -- Mensagens pós jogo
        love.graphics.printf('Jogador ' .. tostring(JogadorVencedor) .. ' ganhou!',
            0, 10, LARGURA_JANELA, 'center')
        love.graphics.printf('Pressione Enter para recomeçar!', 0, 30, LARGURA_JANELA, 'center')
    end

    --Mostra a pontuação
    disjogarScore()
    --Desenha os jogadores e a bola
    J1:render()
    J2:render()
    Bola:render()

    --Mostra o fps
    disjogarFPS()

end

function disjogarScore()
    love.graphics.print(tostring(pontuacaoJ1), LARGURA_JANELA / 2 - 50,
        ALTURA_JANELA / 3)
    love.graphics.print(tostring(pontuacaoJ2), LARGURA_JANELA / 2 + 30,
        ALTURA_JANELA / 3)
end

function disjogarFPS()
    love.graphics.setColor(0, 255/255, 0, 255/255)
    love.graphics.print('FPS: ' .. tostring(love.timer.getFPS()), 10, 10)
    love.graphics.setColor(255, 255, 255, 255)
end
