-- Uma maquina de estados serve para definir os estados em que o jogo esta 
-- chamando funções certas apenas quando necessário e em espaços especificos
-- melhorando a leitura do código, salvando memória e facilitando o encontro de bugs
MaquinaEstados = Class {}

-- Objetivo: incializa uma maquina de estados
function MaquinaEstados:init(estados)
    -- Define as funções da maquina de estados
    self.vazio = {
        render = function()
        end,
        update = function()
        end,
        enter = function()
        end,
        exit = function()
        end
    }
    self.estados = estados or {}
    self.atual = self.empty
end
-- Muda de um estado para outro
function MaquinaEstados:change(nomeEstado, parametros)
    -- Verifica se o estado existe
    assert(self.estados[nomeEstado])
    -- Sai do estado atual através da função exit defina na classe desse estado
    self.atual:exit()
    -- Muda o estado atual para o estado no indice do nome do estado na tabela
    self.atual = self.estados[nomeEstado]()
    -- Entra no novo estado seguindo a função enter do próprio estado
    self.atual:enter(parametros)
end
-- Chama a função de atualiar definida no dado estado
function MaquinaEstados:update(dt)
    self.atual:update(dt)
end
-- Chama a função de renderizar definida no dado estado
function MaquinaEstados:render()
    self.atual:render()
end
