#include <stdio.h>
#include <time.h>

void escalarLinha(double escalar, double linha[10], int n)
{
    while (n--)
    {
        linha[n - 1] *= escalar;
    }
}

void somaLinha(double *linha1, double *linha2, int n)
{
    while (n--)
    {
        linha1[n - 1] += linha2[n - 1];
    }
}

void trocaLinha(double *linhaDest, double *linhaSrc, int n)
{
    double linhaAux[10];
    while (n--)
    {
        linhaAux[n - 1] = linhaDest[n - 1];
        linhaDest[n - 1] = linhaSrc[n - 1];
        linhaSrc[n - 1] = linhaAux[n - 1];
    }
}

double determinante(double matriz[3][3], unsigned short n)
{
    unsigned short i, j = 0;
    double det = 1;
    for (j = 0; j < n; j++)
    {
        for (i = j + 1; i < n; i++)
        {
            if (matriz[i][j])
            {
                escalarLinha(-matriz[i][j] / matriz[j][j], matriz[j] + j, n - j);
                somaLinha(matriz[i] + j, matriz[j] + j, n - j);
                escalarLinha(-matriz[j][j] / matriz[i][j], matriz[j] + j, n - j);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        det *= matriz[i][i];
    }
    return det;
}

int main()
{
    double matriz[3][3], tempo, det;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            matriz[i][j] = (i + 1) * (j + 1) * 3 % 4;
        }
    }
    clock_t t = clock();
    det = determinante(matriz, 3);
    t = clock() - t;
    tempo = ((double)t)/CLOCKS_PER_SEC;
    printf("%lf\n\n%lf\n", det, tempo);
    return 0;
}