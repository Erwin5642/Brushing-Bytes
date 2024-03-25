EstadoTempo = Class{__includes = EstadoBase}

CICLOS_TEMPORIZADOR = 0.75

function EstadoTempo:init()
    self.total = 3
    self.timer = 0
end

function EstadoTempo:atualizar(dt)
    self.timer = self.timer + dt

    if self.timer > CICLOS_TEMPORIZADOR then
        self.timer = self.timer % CICLOS_TEMPORIZADOR
        self.total = self.total - 1

        if self.total == 0 then
           gStateMachine:mudar('jogar') 
        end
    end
end

function EstadoTempo:renderizar()
    love.graphics.printf(tostring(self.total), 0, 120, gLARGURA_TELA, 'center')
end
