Class = require 'class'
require 'Lua'
require 'Obstaculo'
require 'ParObstaculo'

LARGURA_JANELA = 512
ALTURA_JANELA = 288

local backgroundScroll = 0
local VELOCIDADE_FUNDO = 60
local background = love.graphics.newImage('Background-2.jpg')

local spawnTimer = 0
local ParesObstaculo = {}

local ultimoY = -ALTURA_OBSTACULO + math.random(80) + 20

local lua = Lua()

function love.load()
    love.window.setTitle('Moonlight')
    love.window.setMode(LARGURA_JANELA, ALTURA_JANELA, {fullscreen = false, resizable = false})
    love.keyboard.keysPressed = {}
end 

function love.keypressed(key)
    love.keyboard.keysPressed[key] = true
    
    if key == 'escape' then 
        love.event.quit()
    end
end

function love.keyboard.wasPressed(key)
    if love.keyboard.keysPressed[key] then 
        return true
    else
        return false
    end
end

function love.update(dt)
    backgroundScroll = (backgroundScroll + VELOCIDADE_FUNDO * dt) % background:getWidth()
    lua:update(dt)

    spawnTimer = spawnTimer + dt
    if spawnTimer > 2 then 

        local y = math.max(-ALTURA_OBSTACULO + 10, math.min(ultimoY + math.random(-20, 20), ALTURA_JANELA - 90 - ALTURA_OBSTACULO))
        ultimoY = ultimoY

        table.insert(ParesObstaculo, ParObstaculo(y))
        spawnTimer = 0
    end

    for k, ParObstaculo in pairs(ParesObstaculo) do
        ParObstaculo:update(dt)

        if ParObstaculo.x < -ParObstaculo.width then 
            table.remove(ParObstaculosList, k)
        end
    end
    love.keyboard.keysPressed = {}
end

function love.draw()

    love.graphics.draw(background, -backgroundScroll, 0, 0, 1, ALTURA_JANELA/background:getHeight())
    love.graphics.draw(background, -backgroundScroll + background:getWidth(), 0, 0, 1, ALTURA_JANELA/background:getHeight())

    for k, ParObstaculo in pairs(ParesObstaculo) do
        ParObstaculo:render()
    end

    lua:render()

    displayFPS()
end

function displayFPS()
    love.graphics.setColor(0, 255/255, 0, 255/255)
    love.graphics.print('FPS: ' .. tostring(love.timer.getFPS()), 10, 10)
    love.graphics.setColor(255, 255, 255, 255)
end
