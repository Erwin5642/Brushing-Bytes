--Define o estado de countdown como uma classe filha do estado base
EstadoCountdown = Class{__includes = EstadoBase}

TEMPO_CONTADOR = 0.75
--Inicializa o contador para 3 tempos, e um outro temporizador em zero para registrar o tempo passado
function EstadoCountdown:init()
        self.contador = 3
        self.timer = 0
end
--Atualiza o timer de acordo com os frames passados, diminuindo o contador a cada loop concluido e muda de estado no fim
function EstadoCountdown:update(dt)
    self.timer = self.timer + dt

    if self.timer > TEMPO_CONTADOR then
        self.timer = self.timer % TEMPO_CONTADOR
        self.contador = self.contador - 1

        if self.contador == 0 then
            gMaquinaEstados:change('jogar')
        end
    end
end

function EstadoCountdown:render()
    love.graphics.printf(tostring(self.contador), 0, 120, gLARGURA_JANELA, 'center')
end