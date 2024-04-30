#Estrutura condicional if...else

x, y = 1, 2
x, y = y, x
x = y

# Tasks 
# É possível atribuir uma função a outra assim como uma variável

task1() = println("$x < $y")
task2() = println("$x > $y")
task3() = println("$x == $y")

#Ifs else
if x > y
    task1()
elseif x < y
    task2()
else 
    task3()
end


