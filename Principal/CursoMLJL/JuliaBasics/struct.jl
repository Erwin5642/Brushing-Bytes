## structs

#declarando structs (por definição strucs são imutaveis, mas é possivel criar um struct mutável como a seguir)

mutable struct Funcionario
    nome::String
    idade::Integer
    salario::Float32
end

#construtor
Programador = Funcionario("Marcos", 26, 3500.0)

#acessando campos
Programador.nome 

Programador.idade

Programador.salario

#mudando valores em um campo
Programador.idade = 27
