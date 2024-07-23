mutable struct R³
    x::Float64
    y::Float64
    z::Float64
end

import Base: +, *
+(u::R³, v::R³) = return R³(u.x + v.x, u.y + v.y, u.z + v.z)
*(λ::Real, v::R³) = return R³(v.x * λ, v.y * λ, v.z * λ)
*(v::R³, λ::Real) = return R³(v.x * λ, v.y * λ, v.z * λ)

a = R³(0.8, -3.7, 5.3)
b = R³(-2.0, 1.0, 7.2)

