#include <stdio.h>
#include <time.h>

typedef struct
{
    double matrizExtendida[10][11];
    unsigned short nVariaveis;
    unsigned short nConstantes;
    double vetorSolucao[10];
} SistemaLinear;

double absValue(double x)
{
    return x >= 0 ? x : -x;
}

void copiaVetor(double vetorDest[10], double vetorSrc[10], unsigned short n)
{
    while (n--)
    {
        vetorDest[n] = vetorSrc[n];
    }
}

double maxAbsVetor(double vetor[10], unsigned short n)
{
    double absMaior = absValue(vetor[0]), absVetor;
    while (n-- >= 1)
    {
        absVetor = absValue(vetor[n]);
        absMaior = (absMaior < absVetor) ? absVetor : absMaior;
    }
    return absMaior;
}

double calculaDKR(double solucaoAtual[10], double dk, unsigned short n)
{
    return dk / maxAbsVetor(solucaoAtual, n);
}

double calculaDK(double solucaoAtual[10], double solucaoAnterior[10], unsigned short n)
{
    double solucaoAux[10];
    unsigned short m = n;
    while (m--)
    {
        solucaoAux[m] = solucaoAtual[m] - solucaoAnterior[m];
    }
    return maxAbsVetor(solucaoAux, n);
}

void trocaLinha(double linha1[10], double linha2[10], unsigned short n)
{
    double linhaAux;
    while (n--)
    {
        linhaAux = linha1[n];
        linha1[n] = linha2[n];
        linha2[n] = linhaAux;
    }
}

int convergeSistema(SistemaLinear Axb){
    int j, i, m = Axb.nVariaveis, n = Axb.nConstantes, somaLinha;
    for(i = 0; i < n; i++){
        somaLinha = 0;
        for(j = 0; j < n; j++){
            if(j != i){
                somaLinha += Axb.matrizExtendida[i][j]; 
            }
        }
    }
}

int gaussSeidel(SistemaLinear *Axb, double erro){
    if(!convergeSistema(*Axb)){
        return 0;
    }
    while(){

    }
}

int main()
{
    FILE *sistemasArq = fopen("sistemas.txt", "r");
    SistemaLinear Axb;
    clock_t t;
    double tempo, erro, resultadoEsperado[10];
    unsigned short i, j;
    while (fscanf(sistemasArq, "%hu", &Axb.nVariaveis) != EOF)
    {
        Axb.nConstantes = Axb.nVariaveis;
        for (i = 0; i < Axb.nVariaveis; i++)
        {
            for (j = 0; j < Axb.nVariaveis; j++)
            {
                fscanf(sistemasArq, "%lf", &Axb.matrizCoeficientes[i][j]);
            }
        }
        for (i = 0; i < Axb.nConstantes; i++)
        {
            fscanf(sistemasArq, "%lf", &Axb.vetorConstantes[i]);
        }
        for (i = 0; i < Axb.nVariaveis; i++)
        {
            fscanf(sistemasArq, "%lf", &Axb.vetorSolucao[i]);
        }
        for (i = 0; i < Axb.nVariaveis; i++)
        {
            fscanf(sistemasArq, "%lf", &resultadoEsperado[i]);
        }
        fscanf(sistemasArq, "%lf", &erro);

        t = clock();

        if (metodoGaussSeidel(&Axb, erro))
        {

            t = clock() - t;
            tempo = ((double)t) / CLOCKS_PER_SEC;

            printf("O resultado encontrado foi: ");
            for (i = 0; i < Axb.nVariaveis; i++)
            {
                printf("%lf ", Axb.vetorSolucao[i]);
            }
            printf("\nO resultado esperado era: ");
            for (i = 0; i < Axb.nVariaveis; i++)
            {
                printf("%lf ", resultadoEsperado[i]);
            }
            printf("\n\nO algoritmo levou %lf segundos\n----------------------\n\n", tempo);
        }
        else
        {
            printf("O sistema não pode convergir!\n\n");
        }
    }

    fclose(sistemasArq);
    return 0;
}