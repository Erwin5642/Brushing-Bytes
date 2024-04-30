#Estruturas de Repetição

#Contadores 
i = 1

#While...end
while i <= 10 
    println(i)
    i += 1
end

#For...end
#1:10 descreve um intervalo, que inclui o número de inicio (1) e número de término (10)
#Além disso, a variavel j é local ao for...end, sendo excluido após a repetição
for j = 1:10 
    println(j)
end

for k = 50:-5:0 #Nesse casso, além do intervalo, o -5 indica o passo em que o loop avança
    println(k)
end


#Loop sobre um array
array = [10, 20, 30, 40, 50]

for element in array
    println(element)
end

#Loop sobre uma string 
nome = "Henrique"

for element in nome
    println(element)
end

#Loop sobre um dicionario
Funcionario = Dict(:nome => "Marcos", :idade => 30, :salario => 4200, :email => "marcos32@gmail.com")

for elem in Funcionario
    println(elem)
end

for (key, value) in Funcionario
    println("$key: $value")
end