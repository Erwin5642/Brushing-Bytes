#Caracteres são denotados por aspas simples e strings com aspas duplas
typeof('a')

typeof("string")

#\t insere uma tab e \n insere uma nova linha
println("Hello\tworld!\n")

#Concatenação é feita com *
s1 = "Hello "
s2 = "World!"

s1_s2 = s1 * s2

#Para imprimir uma variavel string utiliza-se $<nome_da_string>
println("$s1 world!")


#Julia tambem suporta unicode
👍 = true 
😒 = 3.14
👍 + 😒
#Para inserir um caracter unicode escreva \nome_do_caractere pressione tab
α = 1
β = 2
ϕ = 3
θ = 4
σ = 5

exit()