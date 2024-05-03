## Funções são módulos que permitem reutilizar código e quebrar programas em coleções menores

##Em Julia, uma função é um objeto que mapeia uma tupla de valores argumentos para um valor de retorno

#Criando uma função e armazenando ela na memória
function fatorial(n)
    fn = 1
    fnn = 0
    while n > 1
        fn += fnn
        fnn = fn - fnn
        n -= 1
    end
    return fn
end

#Chamada das Funções (a função é compilada apenas quando ela é chamada, compilando apenas os métodos utilizados)
fatorial(1)
fatorial(2)
fatorial(3)
fatorial(4)
fatorial(5)
fatorial(6)

#Também é possivel declarar uma função de forma matemática
f(a, b) = 3 * a - b^2