/*
Listas implementadas:
-Lista Sequencial
    -Array de tamanho fixo
    -Array de tamanho dinâmico

Funções Implementadas:
-Array fixo
    -Alocar array
    -Desalocar array
    -Imprimir
    -Inserir chave
        -No lugar de uma chave
        -Num índice
    -Buscar chave
-Array dinamico
    -Alocar array
    -Desalocar array
    -Realocar array com novo tamanho
    -Imprimir array
    -Inserir chave
        -No inicio deslocando para direita
        -No fim deslocando para esquerda
        -No lugar de uma chave
        -Num índice
    -Buscar chave
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Array de tamanho fixo
typedef struct Array
{
    int *V;
    unsigned n;
} Array;

// Operações gerais em array:
void createArray(Array *A, unsigned size)
{
    int i;
    A->n = size;
    A->V = malloc(sizeof(int) * size);
    memset(A->V, 0, sizeof(int) * A->n);
}

void deleteArray(Array *A)
{
    A->n = 0;
    free(A->V);
    A->V = NULL;
}

void printArray(Array A)
{
    int i;
    printf("[");
    for (i = 0; i < A.n; i++)
    {
        printf(" %d ", A.V[i]);
    }
    printf("]\n");
}

int searchKeyArray(Array A, int key)
{
    int i;
    for (i = 0; i < A.n; i++)
    {
        if (key == A.V[i])
        {
            return i;
        }
    }
    return -1;
}

int insertKeyAtIndexArray(Array *A, int index, int key)
{
    if ((index > 0) && (index < A->n))
    {  
        A->V[index] = key;
        return 1;
    }
    return 0;
}

int insertKeyAtKeyArray(Array *A, int key)
{
    int index = searchKeyArray(*A, key);
    if(index > 0){
        A->V[index] = key;
        return 1;
    }
    return 0;
}

//Operações em Array Dinâmico
