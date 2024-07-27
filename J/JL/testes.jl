using Plots
x = [ rand() for i = 1:10]

y = []
for i = 1:10 
    push!(y, x[i] * rand())
end

x = [i for i = 1:10]
y = [i for i = 2:11]

for i = 1:10
    println((x[i], y[i]))
end

scatter(x, y)

bias = 0.02
peso = 0.01
h(x) = bias + peso * x

plot!(x, h)
