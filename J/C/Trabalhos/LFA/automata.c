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

int split (char *fonte, char *destino, char token)
{
    int i, j, tam;
    for(i = 0, tam = 0, j = 0; *fonte != '\0'; i++, tam++){
        if(fonte[i] != token){
            destino[j] = fonte[i];
            j++;
        }
    }
    destino[tam] = '\0';
    return tam;
}

char transicao(char q, char c, char *estados, char *alfabeto, char **delta){
    char *i, *j;
    if(( i = strchr(estados, q)) && (j = strchr(alfabeto, c)){
        
    }
    return TRAVOU;
}

int read(char *str, int t){
     fgets(str,t,stdin); 
     return strlen(str);
}

int main()
{
    char input[30], alfabeto[11], estados[11], finais[11], delta[11][11], q0;
    int novaPalavra = 0, novoAutomato = 0, naoTravou = 1, qtdEstados, qtdSimbolos, qtdFinais, i, j, k;
    do{
        printf("Criando novo automato");

        printf("\nEntre com o conjunto de Estados, separados por vigulas: ");
        read(input, 30);
        qtdEstados = split(input, estados, ',');
        printf("\nEntre os si­mbolos do alfabeto, separados por vi­gulas: ");
        read(input, 30);
        qtdSimbolos = split(input, alfabeto, ',');
        printf("\nEntre com o estado inicial: ");
        scanf("%c%*[^\n]", &q0);
        printf("\nEntre os estados de F, separados por vi­gulas: ");
        read(input, 30);
        qtdFinais = split(input, finais, ',');
        
        printf("\nLeitura da Funcao Delta:");
        for(i = 0; i < qtdEstados; i++){
            for(j = 0; j < qtdSimbolos; j++){
                printf("\ndelta(%c, %c) = ", estados[i], alfabeto[j]);
	            scanf(" %c%*[^\n]",&delta[i][j]);
            }
        }

        do{
            printf("\nEntre com a palavra a ser verificada:");
            read(input, 30);
            k = 0;
            printf("\nSequencia de Estados: \n");
            while((input[k] != '\0')&&(naoTravou)){
                q0 = transicao(q0, input[k], estados, alfabeto, delta);
                if(q0 == TRAVOU){
                    printf("Travou!\n");
                    naoTravou = 0;
                }
                else{
                    printf("%c\n", q0);
                }
                k++;
            }
            if((naoTravou) && (strchr(finais, q0))){
                printf("Palavra nao aceita\n");
            }
            else{
                printf("Palavra aceita\n");
            }

            printf("\nDeseja inserir uma nova palavra?\n0 - Nao\n1 - Sim\n");
            scanf("%d", &novaPalavra);
        }while(novaPalavra);

        printf("\nDeseja inserir um novo automato?\n0 - Nao\n1 - Sim\n");
        scanf("%d", &novoAutomato);
    }while(novoAutomato);

    return 0;
}


