abstract type Figura end

struct Triangulo <: Figura
    altura::Float64
    base::Float64
end

struct Retangulo <: Figura
    altura::Float64
    largura::Float64
end

struct Circulo <: Figura
    raio::Float64
end

area(a::Triangulo) = 0.5 * a.base * a.altura
area(a::Circulo) = pi * a.raio^2
area(a::Retangulo) = a.altura * a.largura
