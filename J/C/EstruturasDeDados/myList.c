#include <stdlib.h>
//ista
//Operações: read - O(n), insert - O(1), delete - O(1)
typedef struct L{
    int chave;
    ListaEncadeada *prox;
}ListaEncadeada;

void inicializarLista(ListaEncadeada lista){
    lista.chave = 0;
    lista.prox = NULL;
}

void encerrarLista(ListaEncadeada lista){
    if(lista.prox != NULL){
        encerrarLista(*lista.prox);
        free(lista.prox);
    }
}

void inserirLista(ListaEncadeada lista, int x){
    
}

void deletarLista(ListaEncadeada lista, int x){

}

int lerLista(ListaEncadeada lista, int indice){

}


typedef struct LD{

}ListaDupla;
