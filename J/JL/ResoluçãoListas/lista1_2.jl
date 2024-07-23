function distancia(p1::Tuple{Float64, Float64}, p2::Tuple{Float64, Float64})::Real
    return sqrt((p1[1] - p2[1])^2 + (p1[2] - p2[2])^2)
end

ss = split(readline())
p1 = parse(Float64, ss[1]), parse(Float64, ss[2])

ss = split(readline())
p2 = parse(Float64, ss[1]), parse(Float64, ss[2])

println(distancia(p1, p2))
