/*  
    Trabalho de Linguagens Formais e Automatos
    Aluno: Arthur Kenji Murakami
    Série: 2º Ano
    Data: 23/05/2024
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define TRAVOU '-'

//  Funcao para limpara a tela do terminal
void clear_screen()
{
#ifdef __unix__
    system("clear");
#elif defined(_WIN32) || defined(WIN32)
    #define OS_Windows
    system("cls");
#endif
}

//  Funcao para a entrada de uma string
void gets(char *str, int t, int *tamW){
    fgets(str,t,stdin);  //   coloca \n e \0 no fim stdin Ã© entrada padrao (teclado)
    *tamW=strlen(str)-1;
    str[*tamW]='\0';
}

//  Funcao para separar cada elemento de tamanho 1 caracter de acordo com o separador.
void split (char *Q, char *str, char sep, int *tam)
{
    int i,j=0;
    for(i=0;i<*tam;i++)
        if (str[i]!=sep)    //  se nao encontrou o separador
            Q[j++]=str[i];
    *tam = j;   //  guarda o tamanho dos elementos

}

//  Funcao para verificar se um simbolo pertence a um conjunto de estados, e se pertence, retorna a posicao
int pertence(char *Str, char c, int tam)
{
    int i;
    for(i=0; i<tam; i++) {
        if(Str[i]==c) {
            return i;
        }
    }
    return -1;
}

//  Funcao para verificar se um conjunto de estados pertence a outro conjunto de estados
int pertFim(char *Q, char *F, int tamQ, int tamF)
{
    int i, resp;
    for(i=0; i<tamF; i++) {
        resp = pertence(Q, F[i], tamQ);
        if(resp==-1) {
            return -1;
        }
    }
    return 1;
}

//  Funcao para verificar para qual estado o automato vai ir de acordo com determinado simbolo de uma palavra
char delta(char q, char c, char *Q, char *A, int tamQ, int tamA,char mDelta[10][10], int *falha)
{
    for(int i = 0; i < tamQ; i++)
        if(Q[i] == q)
            for(int j=0; j<tamA; j++)
                if (A[j]==c)
                    return mDelta[i][j];
    *falha=1;
    //  Retorna falha caso o simbolo nao possui estado
    return TRAVOU;
}

int main()
{
    //  Variaveis para armazenamento do automato
    char W[20], Q[10], A[10], qo, F[10], q, mDelta[10][10], c, str[30];
    //  Variaveis para armazenamento doi tamanho do conjunto dos estados
    int tamQ, tamF, tamA, tamW;
    //  Variaveis para contagem
    int i, j, p=0;
    //  Variaveis para o menu
    int falha=0, pal=1, pg=2, pert=0, inicio=-1, mat=-1;

    do {
        clear_screen();
        printf("Automato\n");

        //  Atribuicao de valores para as variaveis do menu
        falha=0;
        pert=-1;
        inicio=-1;
        mat=-1;

        //  Leitura do conjunto de estados
        printf("\nEntre com o conjunto de Estados, separados por vigulas: ");
        gets(str,30,&tamQ);
        fflush(stdin);
        split(Q, str, ',', &tamQ);

        //  Leitura do alfabeto
        printf("\nEntre os simbolos do alfabeto, separados por virgulas: ");
        gets(str,30,&tamA);
        fflush(stdin);
        split(A,str, ',', &tamA);

        //  Leitura do estado inicial
        do {
            printf("\nEntre com o estado inicial: ");
            scanf(" %c%*[^\n]", &qo);
            fflush(stdin);
            setbuf(stdin,NULL);
            inicio = pertence(Q, qo, tamQ);
            //  Se a funcao pertence retornar -1, repete o processo de input do estado inicial
            if(inicio==-1) {
                printf("\nEste estado nao pertence ao conjunto de estados!\n");
            }
        } while(inicio==-1);

        //  Leitura dos estados finais
        do {
            printf("\nEntre os estados de F, separados por virgulas: ");
            gets(str,30,&tamF);
            fflush(stdin);
            setbuf(stdin,NULL);
            split(F,str,',',&tamF);
            pert = pertFim(Q, F, tamQ, tamF);
            //  Se a funcao pertFim retornar -1, repete o processo de input dos estados f
            if(pert==-1) {
                printf("\nUm ou mais estados finais nao existem no conjunto de estados\n");
            }
        } while(pert==-1);

        //  Leitura da matriz Delta
        for (i=0; i<tamQ; i++)
        {
            for(j=0;j<tamA;j++){
                do {
                    mat=-1;
                    printf("\ndelta(%c, %c) = ",Q[i],A[j]);
                    scanf(" %c%*[^\n]",&mDelta[i][j]);      //  espaco em " %c%*[^n]" faz a leitura do buffer com '\n' e ignora
                    fflush(stdin);
                    mat=pertence(Q, mDelta[i][j], tamQ);
                    // Se o input de transicao for '-', sai do laco de repeticao
                    if(mDelta[i][j]=='-') mat=1;
                    //  Se o input de transicao nao pertencer ao conjunto de estados, repete o input de transicao
                    if(mat==-1) {
                        printf("\nO elemento [%c] nao esta conjunto de estados\n", mDelta[i][j]);
                    }
                } while(mat==-1);
                
            }
        }
        getchar();

        //  Leitura da palavra e verificacao dos estados em relacao a palavra
        do {
            falha=0;
            printf("\nEntre com a palavra a ser verificada: ");
            gets(W,30,&tamW);
            fflush(stdin);
            printf("\nPalavra: %s\n",W);
            //  Atribui o primeiro estado no estado inicial
            q=qo;
            //  Atribui a primeira letra da palavra
            c=W[p++];
            printf("\nSequencia de estados: ");
            printf("%c", q);

            //  Verifica se o proximo estado enquanto nao for o fim da palavra
            while (c!='\0') {
                q=delta(q, c, Q, A, tamQ, tamA, mDelta, &falha);
                if(falha==1)
                {
                    printf("\nO automato travou\n");
                    break;
                }
                c=W[p++];
                printf(" -> %c",q);
            }
            //  Atribui valor 0 para a variavel de contagem da palavra
            p=0;
            //  Retorna printa se a palavra eh conhecida ou nao pelo automato
            if ((pertence(F, q, tamF)==-1) || falha==1)
                printf("\nPalavra nao reconhecida\n");
            else
                printf("\nPalavra reconhecida\n");

            //  Menu de escolha para insercao de uma nova palavra
            printf("\nDeseja inserir uma nova palavra?\n[1] - Sim\n[2] - Nao\nDigite uma opcao: ");
            scanf("%d", &pal);
            fflush(stdin);
            getchar();
        } while(pal==1);
        //  Menu de escolha para encerrar o programa ou informar outro automato
        clear_screen();
        printf("Deseja encerrar o programa?\n[1] - Sim\n[2] - Não, desejo inserir outro automato\nDigite uma opcao: ");
        scanf("%d", &pg);
        fflush(stdin);
        getchar();
    } while(pg==2);
    printf("\nEncerrando o programa...\n");
    return 0;
}
