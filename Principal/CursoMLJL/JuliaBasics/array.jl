#Vetores 
coluna = [1, 4, 2, 3]
typeof(coluna)

#Acessando valores no vetor
#Julia utiliza acesso de indices a partir do 1 e não do 0
coluna[1] = 5
println(coluna[1])

#Tamanho dos vetores 
length(coluna)

#Soma dos elementos
sum(coluna)

#Ordenar vetores de forma não destrutiva
sort(coluna; rev = true) #Adicionar a flag rev = true troca a ordem para descrescente
sort(coluna)

println(coluna) #Observe que não ocorrem mudanças no array em si

#Ordenar vetores de forma destrutiva 
#Em Julia toda função que possui ! após o seu nome faz alterações reais nas variaveis
sort!(coluna; rev = true) #Adicionar a flag rev = true troca a ordem para descrescente
println(coluna)
sort!(coluna)
println(coluna)

#Adicionar elementos no vetor no ultimo indice
push!(coluna, 5)

#Remover elementos no vetor no ultimo indice
pop!(coluna)
println(coluna)

#Matrizes 
matriz = Float32[4.0 1.2 3.1; 1.3 2.0 9.1; 3.2 0 4.1]
typeof(matriz)

#Acessando elementos na matriz
println(matriz[1, 3])

#Importante notar que em Julia os elemetnos são armazenados primeiro em uma coluna e só depois avançam para outra
#Portanto é possível acessar o mesmo indice anterior apenas contando o de coluna em coluna o numero de elementos
println(matriz[7])

#Array com tipos de dados diferentes, nesse caso o tipo do vetor será Any
multi_types = [1, 1.0, π, 1//4, 'a', "Julia", [7 8 9]]

exit()