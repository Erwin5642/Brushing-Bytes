#include <stdio.h>
#include <time.h>

typedef struct{
    double matrizCoeficientes[10][10];
    unsigned short nVariaveis;
    double vetorConstantes[10];
    unsigned short nConstantes;
    double vetorSolucao[10];
}SistemaLinear;

double absValue(double x){
    return x >= 0 ? x : -x;
}

void copiaVetor(double vetorDest[10], double vetorSrc[10], unsigned short n){
    while(n--){
        vetorDest[n] = vetorSrc[n];
    }
}

double maxAbsVetor(double vetor[10], unsigned short n){
    double absMaior = 0, absVetor;
    while(n--){
        absMaior = absValue(absMaior);
        absVetor = absValue(vetor[n]);
        absMaior =  (absMaior < absVetor) ? absVetor : absMaior; 
    }
    return absMaior;
}

double calculaDKR(double solucaoAtual[10], double dk, unsigned short n){
    return dk/maxAbsVetor(solucaoAtual, n);
}

double calculaDK(double solucaoAtual[10], double solucaoAnterior[10], unsigned short n){
    double solucaoAux[10];
    unsigned short m = n;
    while(m--){
        solucaoAux[m] = solucaoAtual[m] - solucaoAnterior[m];
    }
    return maxAbsVetor(solucaoAux, n);
}

void calculaMatrizCG(SistemaLinear Axb, SistemaLinear *Cxg){
    unsigned i, j;
    for(i = 0; i < Axb.nVariaveis; i++){
        for(j = 0; j < Axb.nConstantes; j++){
            Cxg->matrizCoeficientes[i][j] = (i == j) ? 0 : -Axb.matrizCoeficientes[i][j] * (1/Axb.matrizCoeficientes[i][i]);
        }
        Cxg->vetorConstantes[i] = Axb.vetorConstantes[i] * (1/Axb.matrizCoeficientes[i][i]);
    }
}

void transformacaoLinear(SistemaLinear *Axb, SistemaLinear Cxg){
    unsigned short i, j;
    for(i = 0; i < Cxg.nVariaveis; i++){
        Axb->vetorSolucao[i] = 0;
        for(j = 0; j < Cxg.nVariaveis; j++){
            Axb->vetorSolucao[i] += Cxg.matrizCoeficientes[i][j] * Cxg.vetorSolucao[j]; 
        }
    }
}

void somaVetor(double vetorDest[10], double vetorSrc[10], unsigned short n){
    while(n--){
        vetorDest[n] += vetorSrc[n];
    }
}

void mostrarVetor(double vetor[10], unsigned short n){
    unsigned short i;
    for(i = 0; i < n; i++){
        printf("%lf ", vetor[i]);
    }
    printf("\n");
}

void metodoGaussSeidel(SistemaLinear *Axb, double erro){
    SistemaLinear Cxg;   
    double dk, dkr; 
    int p = 1;
    Cxg.nVariaveis = Cxg.nConstantes = Axb->nVariaveis;

    calculaMatrizCG(*Axb, &Cxg);
    printf("Passo 0:\n");
    mostrarVetor(Axb->vetorSolucao, Cxg.nVariaveis);
    do{
        copiaVetor(Cxg.vetorSolucao, Axb->vetorSolucao, Cxg.nVariaveis);
        transformacaoLinear(Axb, Cxg);
        somaVetor(Axb->vetorSolucao, Cxg.vetorConstantes, Cxg.nVariaveis);
        printf("Passo %d:\n", p);
        mostrarVetor(Axb->vetorSolucao, Cxg.nVariaveis);
        p++;

        dk = calculaDK(Axb->vetorSolucao, Cxg.vetorSolucao, Cxg.nVariaveis);
        dkr = calculaDKR(Axb->vetorSolucao, dk, Cxg.nVariaveis);
        }while(dkr > erro);
}

int main(){
    FILE *sistemasArq = fopen("sistemas.txt", "r");
    SistemaLinear Axb;
    clock_t t;
    double tempo, erro, resultadoEsperado[10];
    unsigned short i, j;
    while(fscanf(sistemasArq, "%hu", &Axb.nVariaveis) != EOF){
        Axb.nConstantes = Axb.nVariaveis;
        for(i = 0; i < Axb.nVariaveis; i++){
            for(j = 0; j < Axb.nVariaveis; j++){
                fscanf(sistemasArq, "%lf", &Axb.matrizCoeficientes[i][j]);
            }
        }
        for(i = 0; i < Axb.nConstantes; i++){
            fscanf(sistemasArq, "%lf", &Axb.vetorConstantes[i]);
        }
        for(i = 0; i < Axb.nVariaveis; i++){
            fscanf(sistemasArq, "%lf", &Axb.vetorSolucao[i]);
        }
        for(i = 0; i < Axb.nVariaveis; i++){
            fscanf(sistemasArq, "%lf", &resultadoEsperado[i]);
        }
        fscanf(sistemasArq, "%lf", &erro);

        t = clock();

        metodoGaussSeidel(&Axb, erro);

        t = clock() - t;
        tempo = ((double)t) / CLOCKS_PER_SEC;

        printf("O resultado encontrado foi: ");
        for(i = 0; i < Axb.nVariaveis; i++){
            printf("%lf ", Axb.vetorSolucao[i]);
        }
        printf("\nO resultado esperado era: ");
        for(i = 0; i < Axb.nVariaveis; i++){
            printf("%lf ", resultadoEsperado[i]);
        }
        printf("\n\nO algoritmo levou %lf segundos\n----------------------\n\n", tempo);
    }

    fclose(sistemasArq);
    return 0;
}