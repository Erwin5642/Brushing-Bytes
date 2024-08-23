function vectorize(m::Matrix{Int})
    result = Int[]
    for elem in m
        push!(result, elem)
    end
    return result
end