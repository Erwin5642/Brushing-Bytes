#Uma função que recebe outra função como argumento é uma função de alta ordem
#Uma função anonima é uma função que não possui um nome, sendo útil para substituir funções normais no processo anterior

nomes = ["Marcos"
        "Henrique"
        "João"]

#Hash table
map(length, nomes)

#O exemplo a seguir descreve uma função que recebe como argumento x e que aplica x * "Carlos" para cada elemento de nomes
# Funcionando como uma função sem nome e usada localmente
map(x -> x * " Carlos", nomes)

