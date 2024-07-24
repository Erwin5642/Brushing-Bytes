using Plots

x::Array{Int32,1} = [i for i = 1:20]
f(x) = (x^2 * cos(x) - x) / 10
y::Array{Float32,1} = f.(x)

peso::Float32 = 0.0
vies::Float32 = 0.0

function h(x::Vector, peso, vies)
    return peso * x .+ vies
end

function mean_squared_error(x, y, peso, vies)
    return (1 / length(y)) * sum((h(x, peso, vies) - y) .^ 2)
end

function mean_absolute_error(x, y, peso, vies)
    return (1 / length(y)) * sum(abs.(h(x, peso, vies) - y))
end

function mean_absolute_percentage_error(x, y, peso, vies)
    return (1 / length(y)) * sum(abs.((h(x, peso, vies) - y) ./ y))
end

function mean_squared_logarithmic_error(x, y, peso, vies)
    return (1 / length(y) * sum((log10.(h(x, peso, vies)) - log10.(y)) .^ 2))
end

MSE = mean_squared_error(x, y, peso, vies)

MAE = mean_absolute_error(x, y, peso, vies)

MAPE = mean_absolute_percentage_error(x, y, peso, vies)

MSLE = mean_squared_logarithmic_error(x, y, peso, vies)

function gradientMSE(x, y, peso, vies)
    return ((2 / length(y)) * sum((h(x, peso, vies) - y)), (2 / length(y)) * sum((h(x, peso, vies) - y) .* x))
end

function gradientMAE(x, y, peso, vies)
    return ((1 / length(y)) * sum((h(x, peso, vies) - y) ./ (abs.(h(x, peso, vies) - y))), (1 / length(y)) * sum(((h(x, peso, vies) - y) .* x) ./ (abs.(h(x, peso, vies) - y))))
end

function gradientMAPE(x, y, peso, vies)
    return ((1 / length(y)) * sum((h(x, peso, vies) - y) ./ ((y) .^ 2 .* (abs.(h(x, peso, vies) ./ y)))), (1 / length(y)) * sum((x .* (h(x, peso, vies) - y)) ./ ((y) .^ 2 .* (abs.(h(x, peso, vies) ./ y)))))
end

function gradientMSLE(x, y, peso, vies)
    return ((1 / length(y)) * sum((2 * log10.(h(x, peso, vies) + 2 * log10.(y))) ./ (ln(10) * h(x, peso, vies))), (1 / length(y)) * sum(x .* (2 * log10.(h(x, peso, vies) + 2 * log10.(y))) ./ (ln(10) * h(x, peso, vies))))
end

alpha1 = 0.09
alpha2 = 0.001
scatter(x, y, color=:green)
# Treinamentos
# Metodo da média dos quadrados
vies = 0.0
peso = 0.0
j_history = []

push!(j_history, mean_squared_error(x, y, peso, vies))
plot!(x, h(x, peso, vies), color=:red, title = "Quadrados", legend = false)
res = gradientMSE(x, y, peso, vies)
vies -= alpha1 * res[1]
peso -= alpha2 * res[2]

plot!(x, h(x, peso, vies), color=:blue, title = "Quadrados", legend = false)
plot(1:10, j_history, xlabel = "Epocas", title = "Curva de aprendizado - Quadrados", legend = false, color = :blue)

# Método do erro absoluto
scatter(x, y, color=:green)
vies = 0.0
peso = 0.0

j_history = []

push!(j_history, mean_absolute_error(x, y, peso, vies))
    plot!(x, h(x, peso, vies), color=:red, title = "Absoluto", legend = false)
    res = gradientMAE(x, y, peso, vies)
    vies -= alpha1 * res[1]
    peso -= alpha2 * res[2]


    plot!(x, h(x, peso, vies), color=:blue, title = "Absoluto", legend = false)
    plot(1:6, j_history, xlabel = "Epocas", title = "Curva de aprendizado - Quadrados", legend = false, color = :blue)

# Método do erro absoluto percentual
scatter(x, y, color=:green)
vies = 0.0
peso = 1.0
for i in 1:10
    plot!(x, h(x, peso, vies), color=:red, title = "Absoluto percentual", legend = false)
    res = gradientMAPE(x, y, peso, vies)
    vies -= alpha1 * res[1]
    peso -= alpha2 * res[2]
end
plot!(x, h(x, peso, vies), color=:blue, title = "Absoluto percentual", legend = false)

# Metodo para erro logaritmico quadrado 
scatter(x, y, color=:green)
vies = 0.0
peso = 1.0
for i in 1:10
    plot!(x, h(x, peso, vies), color=:red, title = "Quadrados logaritmicos", legend = false)
    res = gradientMAPE(x, y, peso, vies)
    vies -= alpha1 * res[1]
    peso -= alpha2 * res[2]
end
plot!(x, h(x, peso, vies), color=:blue, title = "Quadrados logaritmicos", legend = false)
