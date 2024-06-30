#include <stdio.h>
#include <time.h>

void escalarLinha(double escalar, double linha[10], int n)
{
    while (n--)
    {
        linha[n] *= escalar;
    }
}

void somaLinha(double linhaDest[10], double linhaSrc[10], int n)
{
    while (n--)
    {
        linhaDest[n] += linhaSrc[n];
    }
}

void trocaLinha(double linha1[10], double linha2[10], int n)
{
    double linhaAux;
    while (n--)
    {
        linhaAux = linha1[n];
        linha1[n] = linha2[n];
        linha2[n] = linhaAux;
    }
}

double determinante(double matriz[10][10], unsigned short n)
{
    unsigned short i, j = 0;
    double det = 1, cm;
    for (j = 0; j < n; j++)
    {
        if (!matriz[j][j])
        {
            for(i = j + 1; i < n && !matriz[i][j]; i++){
            }
            if(i < n && matriz[i][j]){
                trocaLinha(matriz[i], matriz[j], n);
                det *= -1;
            }
        }
        for (i = j + 1; i < n; i++)
        {
            if (matriz[i][j])
            {
                cm = matriz[i][j] / matriz[j][j];
                escalarLinha(-cm, matriz[j] + j, n - j);
                somaLinha(matriz[i] + j, matriz[j] + j, n - j);
                escalarLinha(-1 / cm, matriz[j] + j, n - j);
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
    double matriz[10][10], tempo, det, resultadoEsperado;
    unsigned i, j, n;
    clock_t t;
    FILE *matrizes;
    matrizes = fopen("testes.txt", "r");
    while(fscanf(matrizes, "%u", &n) != EOF){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                fscanf(matrizes, "%lf", &matriz[i][j]);
            }
        }
        fscanf(matrizes, "%lf", &resultadoEsperado);
        t = clock();
        det = determinante(matriz, n);
        t = clock() - t;
        tempo = ((double)t) / CLOCKS_PER_SEC;
        det == resultadoEsperado ? printf("---------VVVV--------\n") : printf("---------XXXX--------\n");
        printf("O resultado encontrado foi %lf e o resultado esperado era %lf\n\n", det, resultadoEsperado);
        printf("O algoritmo levou %lf segundos\n", tempo);
    }
    fclose(matrizes);
    return 0;
}