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

void clear_screen()
{
#ifdef __unix__
    system("clear");
#elif defined(_WIN32) || defined(WIN32)
   #define OS_Windows
   #include <windows.h>
   system("cls");
#endif
}

void gets(char *str, int t, int *tamW){
    fgets(str,t,stdin);  //   coloca \n e \0 no fim stdin Ã© entrada padrao (teclado)
    *tamW=strlen(str)-1;
    str[*tamW]='\0';
}

//  Separa cada elemento de tamanho 1 caracter de acordo com o separador.
void split (char *Q, char *str, char sep, int *tam)
{
    int i,j=0;
    for(i=0;i<*tam;i++)
        if (str[i]!=sep)    //  se nao encontrou o separador
            Q[j++]=str[i];
    *tam = j;   //  guarda o tamanho dos elementos

}

//  Verifica se um simbolo pertence a um conjunto de estados e retorna a posicao
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

//  Verifica se um conjunto de estados pertence a outro conjunto de estados
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

//  Verifica para qual estado o automato vai ir em relacao ao simbolo de uma palavra
char delta(char q, char c, char *Q, char *A, int tamQ, int tamA,char mDelta[10][10], int *falha)
{
    for(int i = 0; i < tamQ; i++)
        if(Q[i] == q)
            for(int j=0; j<tamA; j++)
                if (A[j]==c)
                    return mDelta[i][j];
    *falha=1;
    return TRAVOU;
}

int main()
{
    char W[20], Q[10], A[10], qo, F[10], q, mDelta[10][10], c, str[30];
    int tamQ, tamF, tamA, tamW, i, j, p=0, falha=0, pal=1, pg=2, pert=0, inicio=-1, mat=-1;

    do {
        clear_screen();
        printf("Automato\n");
        falha=0;
        pert=-1;
        inicio=-1;
        mat=-1;

        //  Leitura do conjunto de estados
        printf("\nEntre com o conjunto de Estados, separados por vigulas: ");
        gets(str,30,&tamQ);
        fflush(stdin);
        split(Q, str, ',', &tamQ);

        //Leitura do alfabeto
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
                    if(mDelta[i][j]=='-') mat=1;
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
            q=qo;
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
            p=0;
            if ((pertence(F, q, tamF)==-1) || falha==1)      // Retorna se a palavra eh conhecida ou nao
                printf("\nPalavra nao reconhecida\n");
            else
                printf("\nPalavra reconhecida\n");

            //  Menu para para insercao de uma nova palavra
            printf("\nDeseja inserir uma nova palavra?\n[1] - Sim\n[2] - Nao\nDigite uma opcao: ");
            scanf("%d", &pal);
            fflush(stdin);
            getchar();
        } while(pal==1);
        //  Menu para encerrar o programa ou informar outro automato
        clear_screen();
        printf("Deseja encerrar o programa?\n[1] - Sim\n[2] - Não, desejo inserir outro automato\nDigite uma opcao: ");
        scanf("%d", &pg);
        fflush(stdin);
        getchar();
    } while(pg==2);
    printf("\nEncerrando o programa...\n");
    return 0;
}
