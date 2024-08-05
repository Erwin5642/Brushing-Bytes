using Plots, CSV

<<<<<<< HEAD
data = CSV.File("/home/joao/Brushing-Bytes/J/JL/housingdata.csv")

x = data.size
y = data.price
=======
x = [i for i in 0:0.1:10]
f(x) = -100 * x + 3
y = f.(x)
>>>>>>> refs/remotes/origin/main

cost(bias, weight) = (1 / (2 * length(x))) * sum((x * weight .+ bias - y).^2)

p_cost = plot3d(bias, weight,  cost, xlabel = "Vies", ylabel = "Peso", st = :surface, title = "Minimização da função de custo", legend = false, marker = 2)
scatter!([2], [-1], cost.([2], [-1]))

function h(bias, weight)
    return x * weight .+ bias
end

function partialDerivativeBias(bias, weight) 
    (1 / length(x)) * sum(x * weight .+ bias - y)
end

function partialDerivativeWeight(bias, weight)
    (1 / length(x)) * sum((x * weight .+ bias - y).*x)
end

bias = range(-500, 500, length = 40)
weight = range(-100, 100, length = 40)

p_cost = plot3d(bias, weight, cost, xlabel = "Vies", ylabel = "Peso", st = :surface, title = "Minimização da função de custo", legend = false, marker = 2)
scatter!([3], [-100], cost.([3], [-100]))

bias = 0.0
weight = 0.0
alpha1 = 1
alpha2 = 0.09

for i in 1:100
    scatter!([bias], [weight], cost.([bias], [weight]), legend = false)
    bias -= alpha1 * partialDerivativeBias(bias, weight)
    weight -= alpha2 * partialDerivativeWeight(bias, weight)
    println("(vies = $bias, peso = $weight")
end every 1

bias
weight
y
x

plot!(x, h(bias, weight), xlims = (1000, 1500))

partialDerivativeBias(bias, weight)
partialDerivativeWeight(bias, weight)
