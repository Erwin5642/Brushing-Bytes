using Plots, Random, LinearAlgebra, JuMP, Ipopt

n = 100
x = randn(100, 2)
w_s = [0.3; 0.7]
b_s = -0.5
y = [dot(w_s, x[i,:]) + b_s > 0 ? 1 : -1 for i in 1:n]


I = findall(y .== 1)
scatter(x[I,1], x[I,2], c = :blue, m = :square, legend = false)
I = findall(y .== -1)
scatter!(x[I,1], x[I,2], c = :red, m = :circle, legend = false)

model = Model(optimizer_with_attributes(Ipopt.Optimizer, "print_level" => 0))

@variable(model, w[1:2])
@variable(model, b)

@objective(model, Min, dot(w, w)/2)

@constraint(model, [i = 1:n], y[i] * (dot(w, x[i, :]) + b) >= 1)

optimize!(model)

w, b = value.(w), value(b)

plot!(x -> -(w[1] * x + b) / w[2], -5, 5, c = :magenta, lw = 2)


y = [dot(w_s, x[i,:]) + b_s > randn() * 0.1 ? 1 : -1 for i in 1:n]

I = findall(y .== 1)
scatter(x[I,1], x[I,2], c = :blue, m = :square, legend = false)
I = findall(y .== -1)
scatter!(x[I,1], x[I,2], c = :red, m = :circle, legend = false)

model = Model(optimizer_with_attributes(Ipopt.Optimizer, "print_level" => 0))
C = 1.0
@variable(model, w[1:2])
@variable(model, b)
@variable(model, z[1:n] >= 0)

@objective(model, Min, dot(w, w)/2 + C * sum(z))

@constraint(model, [i = 1:n], y[i] * (dot(w, x[i, :]) + b) >= 1 - z[i])

optimize!(model)

w, b, z = value.(w), value(b), value.(z)
I = findall(z .> 1e-6)
scatter!(x[I, 1], x[I, 2], c = :green)
plot!(x -> -(w[1] * x + b) / w[2], -5, 5, c = :magenta, lw = 2)


fx = [x x[:, 1].^2 + x[:,2].^2]

f(x) = [x[1], x[2], x[1]^2 + x[2]^2]
p = 3
y = [dot(w_s, x[i,:]) + b_s > x[i] * 0.1 ? 1 : -1 for i in 1:n]

I = findall(y .== 1)
scatter(fx[I,1], fx[I,2], fx[I, 3], c = :blue, m = :square, legend = false)
I = findall(y .== -1)
scatter!(fx[I,1], fx[I,2], fx[I, 3], c = :red, m = :circle, legend = false)

model = Model(optimizer_with_attributes(Ipopt.Optimizer, "print_level" => 0))

@variable(model, w[1:p])
@variable(model, b)

@objective(model, Min, dot(w, w)/2)

@constraint(model, [i = 1:n], y[i] * (dot(w, f(x[i, :])) + b) >= 1)

optimize!(model)

w, b = value.(w), value(b)

x1g = range(extrema(x[:,1])..., length = 100)
x2g = range(extrema(x[:,2])..., length = 100)
contour!(x1g, x2g, (x1, x2) -> dot(w, f([x1; x2])) + b, levels = [0,0])
plot!(x -> -(w[1] * x + b) / w[2], -5, 5, c = :magenta, lw = 2)

