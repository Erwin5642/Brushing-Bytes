# function overloading 

function myTypeof(x::Int64)
    return "Int64"
end
#Essa função apenas funciona se os argumentos forem do tipo Int64

function myTypeof(x::Float64)
    return "Float64"
end
#Usando o mesmo nome da função anterior, agora a função também pode receber argumentos do tipo Float64
#Dessa forma, temos uma mesma função genérica mas com dois métodos diferentes
#Esse processo é chamado de function overloading

#Uma função genérica é uma função que pode possuir várias definições ou métodos
#Um método em Julia é um comportamento que uma função pode assumir
function myTypeof(x::Any)
    return "tipo não definido"
end

x = (2, 3)
myTypeof(x)

#Enquanto isso, Julia também permite multiple dispatch
function myGenericfunction(x)
    println("$x is type: ", myTypeof(x))
end

#veja que nesse caso a função recebe um valor x com um tipo não definido
#Isso significa que Julia em si determinará qual o método para ser utilizado

myGenericfunction(1)
myGenericfunction(2.5)
myGenericfunction((2, 3))

#Isso permite criar tipos novos, implementar métodos que trabalharão com esse tipo, e utiliar a função genérica 
struct Jogador
    pontos::Integer
end

function myTypeof(x::Jogador)
    return "Jogador"
end

p1 = Jogador(12)

myGenericfunction(p1)

#Note que myGenericfunction não precisou ser alterado para ser implementado o novo tipo

#Métodos 
#A função methods mostra a lista dos diferentes métodos disponíveis para uma certa função
methods(sqrt)
methods(+)
methods(map)
