function max(x::Vector{Int64})::Int64 
    maior = x[1]
    for i in x
        if i > maior
            maior = i
        end
    end
    return maior
end

function min(x::Vector{Int64})::Int64 
    menor = x[1]
    for i in x
        if i < menor
            menor = i
        end
    end
    return menor
end

vetor = [parse(Int64, ss) for ss in split(readline())]
maior = max(vetor)
menor = min(vetor)

println("O maior valor no vetor é $maior e o menor valor é $menor")
