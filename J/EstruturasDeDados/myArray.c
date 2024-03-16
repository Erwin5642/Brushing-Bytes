#include <stdlib.h>
//Vetor
//Operações: read - O(1), insert - O(n), delete - (n)
typedef struct V{
    int *v;

    int n;
}Vetor;


void inicializarVetor(Vetor vetor){
    vetor.v = malloc(sizeof(int));
    vetor.v[0] = 0;
    vetor.n = 0;
}

void inserirVetor(Vetor vetor, int x){
    int i;
    vetor.n++;
    vetor.v = realloc(vetor.v, sizeof(int) * vetor.n);

}

void encerrarVetor(Vetor vetor){
    free(vetor.v);
}
