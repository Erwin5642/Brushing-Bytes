EstadoPausa = Class{__includes = EstadoBase}

function EstadoPausa:init()
    self.velocidadeLuaHolder = 0
    self.velocidadeObsHolder = 0
end

function EstadoPausa:enter(parametros)
    self.velocidadeLuaHolder = parametros.lua.dy
    parametros.lua.dy = 0
    self.velocidadeObsHolder = VELOCIDADE_OBSTACULO
    VELOCIDADE_OBSTACULO = 0
end

function EstadoPausa:update(dt)
    if love.keyboard.wasPressed('enter') then
        gMaquinaEstados:change('jogar')
    end
end

function EstadoPausa:exit()
    parametros.lua.dy = self.velocidadeLuaHolder 
    VELOCIDADE_OBSTACULO = self.velocidadeObsHolder       
end
