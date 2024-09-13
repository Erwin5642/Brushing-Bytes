################################################################################
# ML > Aprendizado Supervisionado > Rede Neural
################################################################################

# pacotes

using Flux, Images, MLDatasets, Plots

using Flux: crossentropy, onecold, onehotbatch, params, train!

using Random, Statistics, LinearAlgebra

# numeros aleatórios

Random.seed!(1)

# dados de treinamento

X_train_raw, y_train_raw = MLDatasets.MNIST(:train)[:]

X_test_raw, y_test_raw = MLDatasets.MNIST(:test)[:]

# visualização da entrada do treinamento

X_train_raw

index = 1

img = X_train_raw[:, :, index]

colorview(Gray, img')

# visualização dos rótulos do treinamento

y_train_raw

y_train_raw[index]

# visualização da entrada do conjunto de teste

X_test_raw

img = X_test_raw[:, :, index]

colorview(Gray, img')

# visualização dos rótulos do conjunto de testes

y_test_raw

y_test_raw[index]

################################################################################
# Pré-Processamento dos dados
################################################################################


# diminuindo as dimenções do problema

X_train = Flux.flatten(X_train_raw)

X_test = Flux.flatten(X_test_raw)

# transformando o vetor de rótulos em uma matriz como coordenadas

y_train = onehotbatch(y_train_raw, 0:9)

y_test = onehotbatch(y_test_raw, 0:9)

# definindo a arquitetura modelo

model = Chain(
    Dense(28 * 28, 32, relu),
    Dense(32, 10),
    softmax
)

# definindo função de custo

loss(x, y) = crossentropy(model(x), y)

# visualizando os parametros

ps = params(model)

# selecionando o otimizador

learning_rate = Float32(0.01)


# Estimação adaptativa de momento
opt = ADAM(learning_rate)

# trainando o modelo

loss_history = []

epochs = 500

for epoch in 1:epochs
    # trainamento
    train!(loss, ps, [(X_train, y_train)], opt)
    # histórico do erro
    train_loss = loss(X_train, y_train)
    push!(loss_history, train_loss)
    println("Epoch = $epoch : Training Loss = $train_loss")
end

# previsões com os dados

y_hat_raw = model(X_test)

y_hat = onecold(y_hat_raw) .- 1

y = y_test_raw

mean(y_hat .== y)

#mostrando os resultados

check = [y_hat[i] == y[i] for i in 1:length(y)]

index = collect(1:length(y))

check_display = [index y_hat y check]

vscodedisplay(check_display)

# visualiando um exemplo de erro do modelo

misclass_index = 9

img = X_test_raw[:, :, misclass_index]

colorview(Gray, img')

y[misclass_index]

y_hat[misclass_index]

# curva de aprendizado

gr(size = (600, 600))

p_l_curve = plot(1:epochs, loss_history,
    xlabel = "Epochs",
    ylabel = "Loss",
    title = "Learning Curve",
    legend = false,
    color = :blue,
    linewidth = 2
)


# salvando o modelo 
struct MyModel
           net
       end

Flux.@layer MyModel

MyModel() = MyModel(Chain(Dense(10 => 5, relu), Dense(5 =>2)));

model = MyModel()
MyModel(Chain(Dense(28 * 28 => 32, relu), Dense(32 => 10), softmax)) 

model_state = Flux.state(model);

using JLD2

jldsave("mymodel.jld2"; model_state)