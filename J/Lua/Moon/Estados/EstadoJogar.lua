-- Define o estado de jogar como filha da classe base
EstadoJogar = Class {
    __includes = EstadoBase
}

VELOCIDADE_OBSTACULO = 60
LARGURA_OBSTACULO = 100
ALTURA_OBSTACULO = 255

LARGURA_LUA = 15
ALTURA_LUA = 15

function EstadoJogar:init()
    self.lua = Lua()
    self.paresObstaculos = {}
    self.timer = 0
    self.score = 0

    self.ultimoY = -ALTURA_OBSTACULO + math.random(80) + 20
end

function EstadoJogar:update(dt)
    --Cria um novo ostaculo a cada ciclo do timer
    if self.timer > 2 then
        --Modifica o ultimo y para não colocar os obstaculos tão longe
        local y = math.max(-ALTURA_OBSTACULO + 10, math.min(self.ultimoY + math.random(-20, 20), ALTURA_OBSTACULO / 3))
        --Insere os valores do novo obstaculo
        table.insert(self.paresObstaculos, {
            scored = false,
            obstaculos = {
                Obstaculo('top', y),
                Obstaculo('bottom', y + ALTURA_OBSTACULO + 90)
            }
        })

        self.timer = 0
    end
    --Passe por cada um dos pares de osbtaculos na table com cada par 
    for k, par in pairs(self.paresObstaculos) do
        --Incialize a remoção como falsa
       local remova = false
       
       for l, obstaculo in pairs(par.obstaculos) do
        --Para cada obstaculo verifique em par se o obstaculo já foi passado
            if not par.scored then 
                --Sim verifica se ele pode ser marcado como um ponto e marque ele
                if obstaculo.x + LARGURA_OBSTACULO < self.lua.x then
                    self.score = self.score + 1
                    pair.scored = true
                end
            end
            --Se o obtáculo ainda está na tela atualize a sua posição
            if obstaculo.x > -72 then
                obstaculo.x = obstaculo.x - VELOCIDADE_OBSTACULO *dt
            else
                remova = true
            end
       end
       --Se o obstaculo foi assinalado para remoção então tire ele da table
       if remove then
        table.remove(self.paresObstaculos, k)
       end
    end
    --Atualiza o tempo em jogo
    self.timer = self.timer + dt
    
    --Se o jogador apertar enter pausa o jogo
    if love.keyboard.wasPressed('enter') then 
        gMaquinaEstados:change('pausa')
    end
    --Se o jogador apertar return volta para o titulo
    if love.keyboard.wasPressed('return') then
        gMaquinaEstados:change('titulo')
    end 
    
    --Implementação da colisão comparando a posição do jogador com cada obstaculo na tela
    for k, pair in pairs(self.paresObstaculos) do
        for l, obstaculo in pairs(par.obstaculos) do
            if (self.lua.x + 2) + (LARGURA_LUA - 4) >= obstaculo.x and self.lua.x + 2 <= obstaculo.x + LARGURA_OBSTACULO then
                if(self.lua.y + 2) + (ALTURA_LUA - 4) >= obstaculo.x and self.lua.y + 2 <= obstaculo.y + ALTURA_OBSTACULO then
                    gMaquinaEstados:change('score', {
                        score = self.score
                    })
                end
            end  
        end
    end

    --Reseta se o jogador bater no chão
    if self.lua.y > ALTURA_JANELA - 15 then
        gMaquinaEstados:change('score', {
            score = self.score
        })
    end

    self.lua:update(dt)
end

function EstadoJogar:render()
    --renderiza cada um dos obstaculos
    for k, par in pairs(self.paresObstaculos) do
    for k, obstaculo in pairs(par.obstaculos) do
        obstaculo:render()
    end
    end

    --Mostra a pontuação atual
    love.graphics.printf('Pontuacao' .. tostring(self.score), 8, 8)

    --Renderiza o jogador
    self.lua:render()
end

function EstadoJogar:enter()
    --Chamado quando o estado transita
    gScrolling = true
end

function EstadoJogar:exit()
    gScrolling = false
end
