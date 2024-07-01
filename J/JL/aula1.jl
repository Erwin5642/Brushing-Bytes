

println("Hello World!")


# Comentários de uma linha

#= 
    Comentários
    com várias
    linhas
=#

x::Int8 = 1
y = 1
typeof(x)
typeof(y)
a = [1, 2, 3, 4]
b = a
b[1] = 7
b
a

nome = "Carlos"
idade = 23
println("O meu nome é $nome, eu tenho $idade anos.")

s1 = "Hello"
s2 = "World"
s1 * s2
"$s1 $s2"

abstract type Number end
abstract type Real          <: Number end
abstract type AbstractFloat <: Real end
abstract type Integer       <: Real end
abstract type Signed        <: Integer end
abstract type Unsigned      <: Integer end

primitive type Float16 <: AbstractFloat 16 end
primitive type Float32 <: AbstractFloat 32 end
primitive type Float64 <: AbstractFloat 64 end

primitive type Bool <: Integer 8 end
primitive type Char <: AbstractChar 32 end

primitive type Int8    <: Signed   8 end
primitive type UInt8   <: Unsigned 8 end
primitive type Int16   <: Signed   16 end
primitive type UInt16  <: Unsigned 16 end
primitive type Int32   <: Signed   32 end
primitive type UInt32  <: Unsigned 32 end
primitive type Int64   <: Signed   64 end
primitive type UInt64  <: Unsigned 64 end
primitive type Int128  <: Signed   128 end
primitive type UInt128 <: Unsigned 128 end

struct Foo
    bar
    baz::Int
    qux::Float64
end

mutable struct Bar
    baz
    biz::Int
    nill::Complex
    qux::Float64
end

constantes = (π, ℯ)

numeros = Dict("Marcos" => "(67) 99422-1241", "Pablo" => "(67) 99231-5542", "Maria" => "(67) 99857-2341")
numeros["Henrique"] = "(67) 92331-4892"

fibonacci = [1, 1, 2, 3, 5, 8, 13]
setofallset = []
setofallset = [42, "Russel", setofallset]
a = [1 2 3; 4 4 2]

n = 0
while n < 10
    println(n)
    n += 1
end

n = 0
while n < length(fibonacci)
    println(fibonacci)
    n += 1
end

for n in 10:1 
    println()
end

m, n = 3, 3
matriz = zeros(3, 3)
for i in 1:m
    for j in 1:n
        matriz[i, j] = i + j
    end
end


x = 3
y = 4
if x < y 
    println("$y é maior que $x")
elseif x > y 
    println("$y é menor que $x")
else 
    println("$y é igual a $x")
end
        


