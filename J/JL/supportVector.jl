using Plots, Random, LinearAlgebra, JuMP, Ipopt

n = 100
x = randn(100, 2)
w = [0.3; 0.7]
b = -0.5
y = [dot(w, x[i,:]) + b > 0 ? 1 : -1 for i in 1:n]


I = findall(y .== 1)
scatter(x[I,1], x[I,2], c = :blue, m = :square, legend = false)
I = findall(y .== -1)
scatter!(x[I,1], x[I,2], c = :red, m = :circle, legend = false)

using JuMP, Ipopt

modelo = Model(optimizer_with_attributes(Ipopt.Optmizer, "print_level" => 0))

@variable(model, w[1:2])
@variable(model, b)

@objective(model, Min, dot(w, w)/2)

@constraint(model, [i = 1:n], y[i] * (dot(w, x[i, :]) + b) >= 1)

optmize!(model)

w, b = value.(w), value(b)

plot!(x -> -(w[1] * x + b) / w[2], 0, 1, c = :magenta, lw = 2)