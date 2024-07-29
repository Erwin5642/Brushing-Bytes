using Plots

x = [i for i in 0:0.1:10]
f(x) = -1 * x + 2
y = f.(x)

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

bias = weight = range(-1000, 1000, length = 40)

p_cost = plot3d(bias, weight, cost, xlabel = "Vies", ylabel = "Peso", st = :surface, title = "Minimização da função de custo", legend = false, marker = 2)

bias = 0.0
weight = 0.0
alpha1 = 0.9
alpha2 = 0.0000008

@gif for i in 1:100
    global bias, weight, alpha1, alpha2
    scatter!([bias], [weight], cost.([bias], [weight]), legend = false)
    bias -= alpha1 * partialDerivativeBias(bias, weight)
    weight -= alpha2 * partialDerivativeWeight(bias, weight)
end

bias
weight

scatter(x, y)
plot!(x, h(bias, weight), xlims = (1000, 1500))

partialDerivativeBias(bias, weight)
partialDerivativeWeight(bias, weight)
