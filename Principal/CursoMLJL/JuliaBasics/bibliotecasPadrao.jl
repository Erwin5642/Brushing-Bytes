#Bibliotecas padrão da Linguagem Julia podem ser encontradas em https://docs.julialang.org

#Random Numbers Library: essa biblioteca oferece funções para gerar números aleatórios
rand(10) #Gera números entre 0 e 1 (o argumento da função é a quantidade de números gerados)

using Random #Incluir a biblioteca Random Numbers
Random.seed!(1) #Seta uma seed para gerar números de acordo

#examplo 2
#calcular a média de uma série de números aleatórios

Random.seed!(42)

data = randn(1000)

function avarage(x::Vector)
    sum(x) / length(x)
end

avarage(data)