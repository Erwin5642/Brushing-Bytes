#Dicionarios (hash maps)

funcionario = Dict("nome" => :Marcos, :idade => 27, 3500.5 => :salario)
#Dicionarios são semelhantes a namedTuples, entretanto são mais versáteis pois são mutáveis
#As variaveis que possuem : na frente são consideradas do tipo Symbol
#Para mais informações veja: //https:docs.julialang.org/en/v1/manual/metaprogramming/

funcionario["nome"]
funcionario[:idade]
funcionario[3500.5]

#alterando valores do dicionário
funcionario["nome"] = "Carlos"

#Adcionar um novo par chave-elemento
funcionario[:email] = "email@email.com"

#Removendo um par chave-elemento
pop!(funcionario, :email)