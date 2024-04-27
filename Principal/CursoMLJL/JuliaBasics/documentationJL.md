### Documentação
A documentação geral da linguagem pode ser encontrada em:
https://docs.julialang.org/

### Instalando Julia REPL
O REPL ou Read-Eval-Print-Loop é um software que permite ao usuário trabalhar com Julia de forma iterativa. Excetuando instruções na lingaguem Julia 
de forma dinâmica através de um terminal.

-Link para o download 
https://julialang.org/downloads/

Após instalado o REPL pode ser acessado através de um atalho ou digitando "julia" no terminal.
Outra forma de trabalhar com  Julia é instalar a extensão para Julia no VSCode. Escrever os 
programas em arquivos .jl e utiliar os seguintes comandos para usar o REPL.
cntrl + enter: executa uma dada linha e mantem o cursor estático 
shift + enter: executa uma dada linha e avança o cursor para a próxima linha
alt + enter: executa o arquivo inteiro

#Vantagens entre os tipos Array, NamedTuple, Dict
Tuplas são eficientes para armazenar e retornar dados, mas são pouco flexíveis por serem imutáveis.
Dificultando seu uso para conjuntos de dados muito grandes.
Arrays oferecem um equilibrio entre eficiência e flexibilidade, podendo ser usados de forma geral.
Mas para conjuntos de dados muito grandes, se menos eficiente em retornar valores.
Dicionários oferecem uma boa solução para conjuntos de dados grandes, permitindo acesso imediato a qualquer 
dado. Entretanto, possuem um maior custo na memória, sendo menos eficiente que as outras opções para conjuntos pequenos. 
