--Chama todos as classes usadas no programa
Class = require 'class'
require 'Lua'
require 'Obstaculo'
require 'ParObstaculo'
require 'MaquinaEstados'
require 'Estados/Base'
require 'Estados/Pausa'
require 'Estados/Titulo'
require 'Estados/Jogando'
require 'Estados/Score'
require 'Estados/Countdown'

-- Define o tamanho da janela do jogo
gALTURA_JANELA = 600
gLARGURA_JANELA = 800
--Define as variaveis usadas para representar o background
local background = love.graphics.newImage('Imagens/Background-2.jpg')
local VELOCIDADE_BACKGROUND = 60
local loop_scroll = 0

--Objetivo: incialia certas variaveis para o funcionamento do código
function love.load()
    math.randomseed(os.time())
    love.window.setMode(gLARGURA_JANELA, gALTURA_JANELA, {
        resizable = false,
        fullscreen = false
    })
    love.window.setTitle('Moon Light')
    --Cria uma table vazia para armazenar teclas pressionadas pelo usuário
    love.keyboard.keysPressed = {}
    lua = Lua()
    predio = Obstaculo(100, 'top')
end

--Objetivo: realizar alguma ação declarada no escopo da função sempre que uma tecla for acionada
function love.keypressed(key)
    --Sempre que uma dada tecla é apertada, adciona um índice para ela na table
    love.keyboard.keysPressed[key] = true
    --Caso o usuário aperte esc encerra o app
    if key == 'escape' then
        love.event.quit()
    end
end

--Objetivo: verifica se uma dada tecla foi verificada
function love.keyboard.wasPressed(key)
    --Retorna verdadeiro se a tecla no indice key foi apertada
    if love.keyboard.keysPressed[key] then
        return true
    else
        return false
    end
end

--Objetivo: atualiza certas variaveis do programa a cada frame 
function love.update(dt)
    -- Atualiza a posição do background
    loop_scroll = (loop_scroll + VELOCIDADE_BACKGROUND * dt) % background:getWidth()
    lua:update(dt)

    --Apaga as teclas que acabaram de serem apertadas
    love.keyboard.keysPressed = {}
end

--Objetivo: desenha imagens na tela
function love.draw()
    -- Desenha o background uma vez e então desenha uma segunda vez onde a primeira imagem acaba
    love.graphics.draw(background, -loop_scroll, 0, 0, 1, gALTURA_JANELA / background:getHeight())
    love.graphics.draw(background, -loop_scroll + background:getWidth(), 0, 0, 1,
        gALTURA_JANELA / background:getHeight())
    predio:render()
end
