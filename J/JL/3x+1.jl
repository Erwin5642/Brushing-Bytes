using Plots

f(x) = x % 2 == 0 ? x/2 : 3 * x + 1

x = 5
t = 0
t_history = []
x_history = []
fx_history = []
p = scatter([t], [x], [f(x)], legend = false)
while x != 1
    t += 1
    push!(t_history, t)
    push!(x_history, x)
    x = f(x)
    push!(fx_history, x)
end

p = plot!(x_history, t_history, fx_history, legend = false, st = :surface)
x
x_history
fx_history

p

