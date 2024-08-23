function minMax(v::Vector{Int})
    menor = v[1]
    maior = v[1]
    for elem in v
        if elem < menor
            menor = elem
        end
        if elem > maior
            maior = elem
        end
    end
    return (menor, maior)
end