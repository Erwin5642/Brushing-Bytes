using CSV, GLM, Plots, TypedTables

data = CSV.File("/home/joao/Brushing-Bytes/J/JL/housingdata.csv")

x = data.size

y = round.(Int, data.price / 1000)

t = Table(x = x, y = y)

gr(size = (600, 600))

p_scatter = scatter(x, y, xlabel = "Metros Quadrados", ylabel = "Preço", legend = false, markercolor = :red)

ordinary_least_square = lm(@formula(y ~ x), t)

plot!(x, predict(ordinary_least_square), color = :green, linewidth = 3)

newX = Table(x = [1250])
newY = predict(ordinary_least_square, newX)
newX.x
scatter!(newX.x, newY)

## Machine learning approach
x = [i for i = 1:12]
y = [i for i = 4:3:37]

epochs = 0

gr(size = (600, 600))

p_scatter = scatter(x, y, title = "Mercado imobiliario de Portland ($epochs)", xlabel = "Metros Quadrados", ylabel = "Preço", legend = false, markercolor = :red)

bias = 0.0 #y-intercept
weight = 0.0 #slope

h(x) = weight * x .+ bias #hypothesis


h(1)

# Função de custo de Andrew Ng
n = length(x)
y_prediction = h(x)

function cost(x, y)
    (1 / ( 2 * n )) * sum((y_prediction - y).^2)
end

J = cost(x, y)

# Historico dos valores da funcao de custo
J_history = []

push!(J_history, J)

# Treinamento - Algortimo de descida do gradiente / batch
function partialDerivativeBias(x, y) 
    (1 / n) * sum(y_prediction - y)
end

function partialDerivativeWeight(x, y)
    (1 / n) * sum((y_prediction - y).*x)
end

# Hiperparametro - Razão de aprendizado
α0 = 0.01
α1 = 0.01

bias = 0.0
weight = 0.0
for i = 1:1000

y_prediction = h(x)

# Treinamento Iterativo
bias_temp = partialDerivativeBias(x, y)
weight_temp = partialDerivativeWeight(x, y)

bias -= α0 * bias_temp
weight -= α1 * weight_temp

end

bias 
weight 

weight = 3.0731459
bias = 0.3839735

plot!(x, h(x), color = :blue, linewidth = 3)

plot!(x, h(x), color = :blue, alpha = 0.5, title = "Mercado imobiliario de Portland ($epochs)")

J = cost(x, y)

push!(J_history, J)

epochs += 1
epochs
# Fim do treinamento

gr(size = (600, 600))

p_line = plot(1:epochs, J_history, xlabel = "Epocas", ylabel = "Custo", title = "Curva de Aprendizado", legend = false, color = :blue)

newX_ml = [1250]
h(newX_ml)

