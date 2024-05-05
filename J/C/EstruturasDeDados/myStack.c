/*
Pilhas implementadas:
-Pilha
	-Baseada em Array
	-Baseada em Lista Encadeada

Funções Implementadas:
-Desalocar Pilha
-Imprimir Pilha
-Inserir chave (Push)
-Remover chave (Pop)
-Retornar topo (Peek)
-Verificar se está cheia (isFull)
-Verificar se está vazia (isEmpty)
*/

#include "myList.c"
#include "myArray.c"

//Pilha baseada em uma array 
typedef struct ArrayStack{
    Array A;
    int topo;
}ArrayStack;

//Operações gerais de stack em array
void createArrayStack(ArrayStack *S, unsigned capacity){
    S->topo = -1;
    S->A.n = capacity;
    S->A.V = malloc(sizeof(int) * capacity);
}

void linkArrayStack(ArrayStack *S, Array *A){
    S->topo = -1;
    S->A = *A;
}

void deleteArrayStack(ArrayStack *S){
    S->topo = -1;
    S->A.n = 0;
    free(S->A.V);
    S->A.V = NULL; 
}

void printArrayStack(ArrayStack S){
    int i;
    if(S.topo > -1){
        for (i = S.topo; i > -1; i--)
        {
            printf("%d\n", S.A.V[i]);
        }
    }
}

int isEmptyArrayStack(ArrayStack S){
    return S.topo == -1;
}

int isFullArrayStack(ArrayStack S){
    return S.topo == (S.A.n - 1);
}

int pushArrayStack(ArrayStack *S, int key){
    if(!isFullArrayStack(*S)){
        S->topo++;
        return  1;
    }
    return 0;
}

int popArrayStack(ArrayStack *S){
    if(!isEmptyArrayStack(*S)){
        S->topo--;
        return 1;
    }
    return 0;
}

int peekArrayStack(ArrayStack S){
    if(!isEmptyArrayStack(S)){
        return S.topo;
    }
    return 0;
}