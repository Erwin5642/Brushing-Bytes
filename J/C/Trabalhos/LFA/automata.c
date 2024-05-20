#include <stdio.h>
#include <string.h>

#ifdef __unix__
    #include <unistd.h>
    #include <stdlib.h>

#elif defined(_WIN32) || defined(WIN32)

   #define OS_Windows

   #include <windows.h>

#endif

#define TRAVOU 'x'

void split (char *fonte, char *destino, char sep, int *tam)
{
    int i,j=0;
    for(i=0;i<*tam;i++)
        if (str[i]!=sep) //se não encontrou o separador
            Q[j++]=str[i];
    *tam = j; //guarda o tamanho dos elementos
}

char delta(char q, char c){ //implementar

}

int read(char *str, int t){
     fgets(str,t,stdin); 
     return strlen(str);
}


int main()
{
    char input[30], alfabeto[10], estados[10], finais[10], q0;
    int novaPalavra = 0, novoAutomato = 0, qtdEstados, qtdSimbolos, qtdFinais, i, j, k;
    do{
        printf("Criando novo automato");

        printf("\nEntre com o conjunto de Estados, separados por vigulas: ");

        printf("\nEntre os si­mbolos do alfabeto, separados por vi­gulas: ");
    
        printf("\nEntre os estados de F, separados por vi­gulas: ");

        
        //Leitura da matriz Delta
        printf("\nLeitura da Funcao Delta:");
        for (i=0; i<tamQ; i++){
            for(j=0;j<tamA;j++){
               printf("\ndelta(%c, %c) = ",Q[i],A[j]);
                //mDelta[i][j]=fgetc(stdin);
	            scanf(" %c%*[^\n]",&mDelta[i][j]);
               //fflush(stdin);  // ver o equivalente para ignorar o enter
	        }
        }

        do{
            printf("\nEntre com a palavra a ser verificada:");

            printf("\nDeseja inserir uma nova palavra?\n0 - Nao\n1 - Sim\n");
            scanf("%d", &novaPalavra);
        }while(novaPalavra);

        printf("\nDeseja inserir um novo automato?\n0 - Nao\n1 - Sim\n");
        scanf("%d", &novoAutomato);
    }while(novoAutomato);
  
}


