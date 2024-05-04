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

//Pilha baseada em uma array de tamanho fixo
typedef struct ArrayStack{
    Array S;
    int topo;
}ArrayStack;

void createEmptyArrayStack(ArrayStack *S, int *vetor, int size){
    if(size > 0){
        S->topo = -1;
        S->S.n = size;
        S->S.L = vetor;
    }
}