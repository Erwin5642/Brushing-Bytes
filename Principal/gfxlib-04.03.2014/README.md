### Instalação da biblioteca gfx:

Para instalar a bliblioteca gfx, siga os seguintes passos:

0) Caso não tenha gcc instalado, instale o gcc e o make através do seguinte comando:

sudo apt-get install gcc make

1) Instalar as bibliotecas básicas da SDL que são usadas pela minha gfx. As bibliotecas que você precisa instalar nesse passo são as seis seguintes:

libsdl1.2debian e libsdl1.2-dev
libsdl-ttf2.0-0 e libsdl-ttf2.0-dev
libsdl-gfx1.2 e libsdl-gfx1.2-dev

Para instalar essas bibliotecas, digite o seguinte comando: 

sudo apt-get install libsdl1.2debian libsdl1.2-dev libsdl-ttf2.0-0 libsdl-ttf2.0-dev libsdl-gfx1.2 libsdl-gfx1.2-dev

2) Baixar e descompactar a biblioteca gfx em um diretório do seu usuário no Linux. Para ver se a gfx está funcional, entre no diretório gfx a partir de onde instalou a biblioteca e digite o comando "make clean" e depois "make". Não pode ocorrer erro. Depois disso, volte para o diretório onde se encontra o programa exemplo.c e digite novamente "make clean" e depois "make". Se não houve erro, execute o programa "exemplo", que abrirá uma janela com uma elipse azul e um texto.

### Uso da biblioteca

O código do programa exemplo.c pode ser usado como base para desenvolver outros programas que usam a biblioteca gfx. Para criar uma janela basta chamar o procedimento gfx_init, cujos parâmetros são: largura e altura da janela em pixels e uma string que contém o texto a ser exibido no título da janela. O procedimento gfx_quit fecha a janela aberta. O protótipo dos procedimentos/funções estão listados e comentados no arquivo localizado em gfx/gfx.h. É importante ressaltar que as operações de desenho/escrita na janela tornam-se visíveis apenas após invocar o procedimento gfx_paint. 

Para compilar um programa usando a gfx é necessário passar ao compilador gcc informações da biblioteca (localização do cabeçalho, biblioteca criada), o que torna a linha de comando do gcc um tanto grande. Para facilitar o processo é utilizado o utilitário make, que realiza o processo através das instruções contidas no arquivo Makefile. O arquivo Makefile contido no mesmo diretório do programa exemplo.c pode ser usado como exemplo e a compilação de novos programas pode ser realizada apenas mudando o rótulo do programa (linha que contém ":" ao final) e o nome do(s) arquivo(s) .c do novo programa na linha de comando de compilação.