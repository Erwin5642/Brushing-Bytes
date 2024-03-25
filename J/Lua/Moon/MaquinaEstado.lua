MaquinaEstado = Class {}

function MaquinaEstado:init(estados)
    self.vazio = {
        renderizar = function()
        end,
        atualizar = function()
        end,
        entrar = function()
        end,
        sair = function()
        end
    }
    self.estados = estados or {}
    self.atual = self.vazio
end

function MaquinaEstado:mudar(nomeEstado, parametros)
    assert(self.estados[nomeEstado])
    self.atual:sair()
    self.atual = self.estados[nomeEstado]()
    self.atual:entrar(parametros)
end

function MaquinaEstado:atualizar(dt)
    self.atual:atualizar(dt)
end

function MaquinaEstado:renderizar()
    self.atual:renderizar()
end