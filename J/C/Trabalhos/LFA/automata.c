#include <stdio.h>
#include <string.h>

const short TRAVOU = 0;
const short NOT_ELEM = -1;
const unsigned MAX_INPUT = 30;
const unsigned MAX_SET = 10;

typedef enum
{
    false,
    true
} bool;

typedef struct
{
    char *S;
    unsigned tamS;
} string;

void relacionaString(string *dest, char *src, unsigned tam)
{
    dest->S = src;
    dest->tamS = tam;
}

int readString(string str)
{
    unsigned end;
    fgets(str.S, str.tamS, stdin);
    str.S[end = strlen(str.S) - 1] = '\0';
    return end;
}

unsigned split(string src, string dest, char token)
{
    unsigned i, j;
    for (i = 0, j = 0; (i < dest.tamS) && (src.S[i]); i++)
    {
        if (src.S[i] != token)
        {            
            dest.S[j] = src.S[i];
            j++;
        }
    }
    return j;
}

int indexElem(string set, char elem)
{
    unsigned i;
    for (i = 0; i < set.tamS; i++)
    {
        if (set.S[i] == elem)
        {
            return i;
        }
    }
    return NOT_ELEM;
}

char transita(char q, char c, string Q, string A, char D[MAX_SET][MAX_SET])
{
    int i, j;
    if (((i = indexElem(Q, q)) != NOT_ELEM) && ((j = indexElem(A, c)) != NOT_ELEM))
    {
        return D[i][j];
    }
    return TRAVOU;
}

void limpaEntrada()
{
    int c;
    while (((c = getchar()) != '\n') && (c != EOF))
        ;
}

int readChar()
{
    int c;
    while ((c = getchar()) < '!')
        ;
    limpaEntrada();
    return c;
}

bool verificaSubconjunto(string subset, string set)
{
    unsigned i;
    for (i = 0; i < subset.tamS; i++)
    {
        if (indexElem(set, subset.S[i]) == NOT_ELEM)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char w[MAX_INPUT], a[MAX_SET], q[MAX_SET], estadoInicial, f[MAX_SET], funcaoPrograma[MAX_SET][MAX_SET], proxq;
    string input, alfabeto, estados, estadosFinais, temp;
    int novoAutomato, novaPalavra, finaisCorreto;
    unsigned i, j, k;

    do
    {
        printf("Criando novo automato\n");
        relacionaString(&input, w, MAX_INPUT);
        relacionaString(&alfabeto, a, MAX_SET);
        relacionaString(&estados, q, MAX_SET);
        relacionaString(&estadosFinais, f, MAX_SET);

        printf("Entre com o conjunto de estados, separados por virgulas:\n");
        input.tamS = readString(input);
        estados.tamS = split(input, estados, ',');
        
        printf("Entre com os simbolos do alfabeto, separados por virgulas:\n");
        input.tamS = readString(input);
        alfabeto.tamS = split(input, alfabeto, ',');

        printf("Entre com o estado inicial:\n");
        estadoInicial = readChar();

        do
        {
            printf("Entre com os estados finais, separados por virgula:\n");
            input.tamS = readString(input);
            estadosFinais.tamS = split(input, estadosFinais, ',');
            finaisCorreto = verificaSubconjunto(estadosFinais, estados);
            if (!finaisCorreto)
            {
                printf("[ERRO] Pelo menos um dos estados informados é invalido, por favor tente novamente\n");
            }
        } while (!finaisCorreto);

        // printf("Entre com os dados da função de programa:\n");
        // for (i = 0; i < estados.tamS; i++)
        // {
        //     for (j = 0; j < alfabeto.tamS; j++)
        //     {
        //         printf("delta(%c, %c) = ", estados.S[i], alfabeto.S[j]);
        //         funcaoPrograma[i][j] = readChar();
        //     }
        // }

        do
        {
            printf("Entre com a palavra a ser verificada:\n");
            input.tamS = readString(input);

            printf("Sequencia de estados:\n");
            proxq = estadoInicial;
            for(k = 0; (k < input.tamS) && (input.S[k]); k++){
                if(proxq == TRAVOU){
                    k = input.tamS;
                    printf("O automato travou!\n");
                }
                else{
                    printf("%c\n", proxq);
                }
                proxq = transita(proxq, input.S[k], estados, alfabeto, funcaoPrograma);
            }
            temp.tamS = 1;
            temp.S = &proxq;
            if(verificaSubconjunto(temp, estadosFinais)){
                printf("Palavra foi aceita\n");
            }   
            else{
                printf("Palavra nao foi aceita\n");
            } 

            printf("\nDeseja insesir uma nova palavra?\n0 - Nao\n 1 - Sim\n");
            scanf("%d", &novaPalavra);
        } while (novaPalavra);
    
        printf("\nDeseja começar um novo automato ou encerrar o programa?\n0 - Encerrar\n 1 - Novo automato\n");
        scanf("%d", &novoAutomato);
    } while (novoAutomato);

    return 0;
}