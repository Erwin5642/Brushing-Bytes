import Base.+

function +(v::Vector{T}, λ::T) where T <: Number
    ret = T[]
    for elem in v
        push!(ret, elem + λ)
    end
    return ret
end

