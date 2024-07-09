#=Comentarios em Julia podem ser feito com "#" para cometários de uma linha 
ou "#= =#" para comentarios de varias linhas=#

#A função println pode ser usada para escrever informações no terminal 
println("Hello world")

#Além disso, para sair do REPL é possível utilizar a função exit()
exit()

julia> plot(reshape(x, (61, 1)), reshape(y, (61, 1)), lw = 3, seriestype = :scatter, label = "", title = "Simple Linear Regression", xlabel = "x", ylabel= "y");

julia> plot!((x) -> b[1] + W[1] * x, -3, 3, label="Custom model", lw=2);