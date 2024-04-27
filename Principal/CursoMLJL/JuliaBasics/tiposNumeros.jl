#Documentação sobre o comportamento e tipos de numeros
#https://docs.julialang.org/en/v1/base/numbers/ 

#A função typeof permite descobrir o tipo de uma variavel ou valor
typeof(2)
typeof(-1.0)

x = 2.31221212412
typeof(x)

#É possivel declarar uma variavel para certo tipo usando ::
y::Float64 = 1.2
y = y + false

#Frações
frac::Rational = 1//2
frac + 1//10

#Irracionais
pi 
typeof(pi) #Irrational(π)

#Arredondamento
round(pi; digits = 5)

#Undescores são ignoradas 
100000000 == 100_000_000

sqrt(21)
div(15, 4)

exit()