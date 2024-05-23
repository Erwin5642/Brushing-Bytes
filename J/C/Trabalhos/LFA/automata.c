#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char TRAVOU = '-';
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
    scanf("%s", str.S);
    while (getchar() != '\n')
        ;
    return strlen(str.S);
}

unsigned split(string src, string dest, char token)
{
    unsigned i, j;
    for (i = 0, j = 0; (i < dest.tamS) && (src.S[i]) && (src.S[i] != '\n'); i++)
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

char readChar()
{
    char c = getchar();
    while (getchar() != '\n')
        ;
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
    int novoAutomato, novaPalavra, finaisCorreto, inicialCorreto;
    unsigned i, j, k;

    do
    {
        printf("Criando novo automato\n");
        relacionaString(&input, w, MAX_INPUT);
        relacionaString(&alfabeto, a, MAX_SET);
        relacionaString(&estados, q, MAX_SET);
        relacionaString(&estadosFinais, f, MAX_SET);

        printf("Entre com o conjunto de estados, separados por virgulas:\n");
        readString(input);
        estados.tamS = split(input, estados, ',');

        printf("Entre com os simbolos do alfabeto, separados por virgulas:\n");
        readString(input);
        alfabeto.tamS = split(input, alfabeto, ',');

        relacionaString(&temp, &estadoInicial, 1);
        do
        {
            printf("Entre com o estado inicial:\n");
            estadoInicial = readChar();
            inicialCorreto = verificaSubconjunto(temp, estados);
            if (!inicialCorreto)
            {
                printf("[ERRO] O estado informados é invalido, por favor tente novamente\n");
            }
        } while (!inicialCorreto);

        do
        {
            printf("Entre com os estados finais, separados por virgula:\n");
            readString(input);
            estadosFinais.tamS = split(input, estadosFinais, ',');
            finaisCorreto = verificaSubconjunto(estadosFinais, estados);
            if (!finaisCorreto)
            {
                printf("[ERRO] Pelo menos um dos estados informados é invalido, por favor tente novamente\n");
            }

        } while (!finaisCorreto);
        printf("Entre com os dados da função de programa:\n");
        for (i = 0; i < estados.tamS; i++)
        {
            for (j = 0; j < alfabeto.tamS; j++)
            {
                printf("delta(%c, %c) = ", estados.S[i], alfabeto.S[j]);
                funcaoPrograma[i][j] = readChar();        
                relacionaString(&temp, &funcaoPrograma[i][j], 1);
                if(!verificaSubconjunto(temp, estados)){
                    funcaoPrograma[i][j] = '-';
                }     
            }
        }

        relacionaString(&temp, &proxq, 1);
        do
        {
            printf("Entre com a palavra a ser verificada:\n");
            input.tamS = readString(input);

            printf("Sequencia de estados:\n");
            proxq = estadoInicial;
            printf("%c\n", estadoInicial);
            for (k = 0; (k < input.tamS) && (input.S[k]); k++)
            {
                proxq = transita(proxq, input.S[k], estados, alfabeto, funcaoPrograma);
                if (proxq == TRAVOU)
                {
                    printf("%c\nO automato travou!\n", TRAVOU);
                    k = input.tamS;
                }
                else
                {
                    printf("%c\n", proxq);
                }
            }
            if (verificaSubconjunto(temp, estadosFinais))
            {
                printf("Palavra foi aceita\n");
            }
            else
            {
                printf("Palavra nao foi aceita\n");
            }

            printf("\nDeseja insesir uma nova palavra?\n0 - Nao\n1 - Sim\n");
            scanf("%d", &novaPalavra);
        } while (novaPalavra);

        printf("\nDeseja começar um novo automato ou encerrar o programa?\n0 - Encerrar programa\n1 - Novo automato\n");
        scanf("%d", &novoAutomato);
    } while (novoAutomato);

    return 0;
}