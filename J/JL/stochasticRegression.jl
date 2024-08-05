using Plots, CSV

data = CSV.File("/home/joao/Brushing-Bytes/J/JL/housingdata.csv")

x = data.size
y = data.price

function hypothesis(theta0, theta1, x)
    return theta1 * x + theta0
end

function hypothesis(theta0, theta1, x::Vector)
    return theta0 .+ x * theta1
end

function descentStochastic(theta0, theta1, x, y)
    return (y - hypothesis(theta0, theta1, x), (y - hypothesis(theta0, theta1, x)) * x)
end

function descentBatch(theta0, theta1, x, y)
    return (sum(hypothesis(theta0, theta1, x) - y), sum((hypothesis(theta0, theta1, x) - y) .* x))
end

alpha = 0.9
vies = 0.0
peso = 0.0


temp = descentBatch(vies, peso, x, y)
vies -= alpha * temp[1]
peso -= alpha * temp[2]

for epochs = 1:100
    temp = descentBatch(vies, peso, x, y)
    vies -= alpha * temp[1]
    peso -= alpha * temp[2]
end

vies
peso

alpha = 0.01
vies = 0.0
peso = 0.0

for epochs = 1:100
    for i in x, j in y 
        temp = descentStochastic(vies, peso, i, j)
        vies -= alpha * temp[1]
        peso -= alpha * temp[2]
    end
end

vies 
peso
