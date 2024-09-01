using CSV

data = CSV.File("J/JL/wolfspider.csv")

x = data.feature
y_temp = data.class

y = []
for i in y_temp
    if i == "absent"
        push!(y, 0)
    else
        push!(y, 1)
    end
end

theta_0 = 0.0
theta_1 = 1.0

z(x) = theta_0 .+ theta_1 * x 

function hipotese(x)
    return 1 ./ (1 .+ exp.(-z(x)))
end

y_prev = hipotese(x)

function custo()
    return (-1/m) * sum(y .* log.(y_prev) + (1 .- y) .* log.(1 .- y_prev)) 
end

function dp_theta_0()
    return sum(y_prev - y)
end

function dp_theta_1()
    return sum((y_prev - y) .* x) 
end

alpha = 0.01

for epoch in 1:1000
    theta_0 -= alpha * dp_theta_0()
    theta_1 -= alpha * dp_theta_1()
    y_prev = hipotese(x)
    plot!(0:1.2, hipotese)
end

theta_0 -= alpha * dp_theta_0()
theta_1 -= alpha * dp_theta_1()

using Plots

k = scatter(x, y)
k
