# Regressão logística e problemas de classificação

# Curva logistica ou sigmóide
using Plots, CSV

################################# Workflow Regressão logistica ###########################################
# Preparo dos dados

data = CSV.File("/home/joao/Brushing-Bytes/J/JL/wolfspider.csv")

x = data.feature
y_temp = data.class

y = []

for str in y_temp
    if str == "present"
        push!(y, 1)
    else
        push!(y, 0)
    end
end

p_data = scatter(x, y, color = :blue, legend = false)

# Inicialização dos parametros
theta0 = 0.0
theta1 = 1.0

theta0_history = [0.0]
theta1_history = [1.0]


# Definição da hipótese
function f(x, bias, peso)
    return x * peso .+ bias
end

function hypothesis(x, bias, peso)
    return 1 ./ (1 .+ exp.(-f(x, bias, peso)))
end

plot!(x, hypothesis(x, theta0, theta1), color = :red)

# Definição da função de custo
function cost(y, y_h)
    return (-1 / length(y)) * sum(y .* log.(y_h) + (1 .- y) .* log.(1 .- y_h))  
end

# Historico do custo

y_hipotetico = hypothesis(x, theta0, theta1)

J_history = []

J = cost(y, y_hipotetico)

push!(J_history, J)

# Definição do algoritmo de descida do gradiente
function partialDetivative(x, y, y_h)
    return (sum(y_h - y), sum((y_h - y) .* x))
end 

# Definição dos hiperparametros
alpha = 0.01
epocas = 0

######################### Começo das iterações #############################
# descida

teste = [i for i = 0:0.1:1.2]
for i in 1:1000

    res = partialDetivative(x, y, y_hipotetico)

    # Atualização dos parametros
    theta0 -= alpha * res[1]
    theta1 -= alpha * res[2]
    
    push!(theta0_history, theta0)
    push!(theta1_history, theta1)
    
    # Calculo do custo 
    y_hipotetico = hypothesis(x, theta0, theta1)
    
    push!(J_history, cost(y, y_hipotetico))
    
    # Previsão
    epocas += 1
    plot!(teste, hypothesis(teste, theta0, theta1), color = :blue, title = "Epoca $epocas", alpha = 0.025)    
end
p_data

################## Fim da Iteração ###################

# Resultado do treinamento
plot(0:epocas, J_history, title = "Curva de Aprendizado", color = :green, xlabel = "Erro", ylabel = "Épocas")

plot(0:epocas, theta0_history, color = :green, xlabel = "Épocas", ylabel = "Vies")

plot(0:epocas, theta1_history, color = :green, xlabel = "Épocas", ylabel = "Peso")


################## Previsões ############################

newX = [0.1, 0.25, 0.5, 0.75, 1.0]
hypothesis(newX, theta0, theta1)

