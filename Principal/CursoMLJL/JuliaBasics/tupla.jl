#Tuplas
x = 1
automata = ("a, b, c", "vivo", x, "morto")

typeof(automata)

#Acesso de elemento
println(automata[4])

 #Elementos de tuplas são imutaveis 
 automata[3] = 2 #error

 #Assim como a sua ordem
 sort(automata) #error

#O seu tamanho também não pode ser alterado
push!(automata) #error
pop!(automata) #error

#Entretanto é possível fazer uma destructure assignment
(alfabeto, estadoInicial, funcao, estadoFinal) = automata

#Desta forma é possível acessar elementos atraves do nome das variaveis ao inves de indices
println(alfabeto) 

#Named tuples   

#construindo uma named tuple
funcionario = (nome = "Marcos", idade = 27, salario = 3500.50)

typeof(funcionario)

#A partir disso é possível acessar um elemento através de um índice ou do nome de uma variável
println(funcionario[3])

println(funcionario.nome)
println(funcionario.idade)
println(funcionario.salario)

exit()