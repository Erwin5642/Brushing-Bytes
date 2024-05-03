#Packages podem ser encontrados em https://juliahub.com/ui/Packages

# pwd() mostra o diretório atual do REPL
# cd("diretório") abre um diretório existente
# Para entrar no package manager é necessário clicar na tecla "]" dentro do REPL
# Escrever "activate ." no terminal indicará ao package manager que o seu projeto está no diretório atual 
# Para adicionar um package para um projeto, utilize "add "PakcageName""
# Após instalar um package pressione backspace para voltar ao REPL
# Além disso, dois arquivos serão criados no diretório do projeto
# Project.toml: Contém todos os packages instalados no projeto
# Manifest.toml: Contém todas as dependências utilizadas pelos packages para funcionar

# Demo:
# Antes de usar o código a seguir instale o package Plots

# Defina o ambiente de trabalho para:
using Pkg
repo
#atribua a repo o caminho para o diretório "/Brushing-Bytes/Principal/CursoMLJL/JuliaBasics/Packages"
Pkg.activate(repo)
cd(repo)
pwd()
Pkg.status()

#Após isso, utilize o package
using Plots

f(x) = x^4 - x^2 + 2x - 8 #Observe que a função pode ser declarada como uma função matemática em Julia
plot(f) #Isso deve gerar uma nova aba com a função

#Scatter plot (plota pontos no gráfico) 
using Random

x = randn(500)
y = randn(500)

scatter(x, y; 
    legend = false,
    alpha = 0.5,
    aspect_ratio = 1
) #Isso gera um gráfico com pontos aleatórios