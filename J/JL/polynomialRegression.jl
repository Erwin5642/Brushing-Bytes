using Plots
 
x = [i for i in 1:100]
f(x) = x^4 + x^2 + rand()
y = f.(x)

function h(param, k)  
    t = []
    for j in x
        s = 0
        for i = 0:k
            s += param[i + 1] * j ^ i
        end
        push!(t, s)
    end
    return t 
end

function cost(param, k)
    return (1 / (2 * length(x))) * sum((h(param, k) - y).^2)
end

function descent(param, k)
    for p in 0:k
        param[p + 1] -= alpha[p + 1] * (1 / length(x)) * sum((h(param, k) - y) .* (x.^p))
    end
end

k = 4
alpha = [0.001 / 10^i for i = 0:k] 
param = [0.0 for i in 0:k]
h(param, k)
cost(param, k)
p = scatter(x, y, legend = false)

    descent(param, k)

    p = plot!(x, h(param, k), legend = false)

param
p

