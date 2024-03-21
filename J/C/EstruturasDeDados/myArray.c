#include <stdlib.h>
// Vetor
// Operações: read - O(1), insert - O(n), delete - (n)
typedef struct V
{
    int *v;

    int n;
} Vetor;

void inicializarVetor(Vetor vetor)
{
    vetor.v = malloc(sizeof(int));
    vetor.v[0] = 0;
    vetor.n = 0;
}

void inserirVetor(Vetor vetor, int x)
{
    int i, j;
    vetor.n++;
    vetor.v = realloc(vetor.v, sizeof(int) * vetor.n);
    for (i = 0; i < vetor.n; i++)
    {
        if (vetor.n - 1 == i)
        {
            vetor.v[i] = x;
        }
        if (vetor.v[i] >= x)
        {
            for (j = vetor.n - 1; j > i; j--)
            {
                vetor.v[j] = vetor.v[j - 1];
            }
            vetor.v[i] = x;
            i = vetor.n;
        }
    }
}

void deletarVetor(Vetor vetor, int x)
{
    int i, j;
    for (i = 0; i < vetor.n; i++)
    {
        if (vetor.v[i] == x)
        {
            while (i < vetor.n - 1)
            {
                vetor.v[i] = vetor.v[i + 1];
                i++;
            }
            vetor.v[i] = 0;
            vetor.n--;
            vetor.v = realloc(vetor.v, sizeof(int) * vetor.n);
        }
    }
}

void encerrarVetor(Vetor vetor)
{
    free(vetor.v);
}
