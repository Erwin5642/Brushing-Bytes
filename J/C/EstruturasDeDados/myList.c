/*
Listas implementadas:
-Lista sequencial
	-Tamanho fixo
	-Dinâmica
-Lista Encadeada
	-Simples
	-Dupla
	-Circular

Funções Implementadas:
-Desalocar lista
-Imprimir lista
-Inserir chave
-Remover chave
-Buscar chave
*/
#include <stdlib.h>

typedef struct{
	int *L;
	int n;
}ListaSequencial;

//Lista Encadeada Simples
typedef struct{
	int chave;
	int *prox;
}ListaEncadeada;

//Operações na Lista Encadeada Simples
void desalocarListaEncadeada(ListaEncadeada **LE){
	ListaEncadeada *aux;
	if(LE != NULL){
		while((*LE) != NULL){
			aux = (*LE)->prox;
			free(*LE);
			(*LE) = aux;
		}
	}
}

void imprimirListaEncadeada(ListaEncadeada *LE, int chave){
	ListaEncadeada *aux = LE;
	while(aux != NULL){
		printf("[%d]->", aux->chave);
		aux = aux->prox;
	}
	printf("[NULL]\n");
}

void inserirChavevListaEncadeada(ListaEncadeada **LE, int chave){
	ListaEncadeada *aux;
	aux = malloc(sizeof(ListaEncadeada));
	aux->chave = chave;
	aux->prox = (*LE);
	(*LE) = aux;
}

void removerChaveListaEncadeada(ListaEncadeada **LE, int chave){
	ListaEncadeada *aux;
	if(LE != NULL){
		while((*LE) != NULL){
			if((*LE)->chave == chave){
				aux = (*LE)->prox;
				free(*LE);
				(*LE) = aux;
				return;
			}
			LE = &(*LE)->prox;
		}
	}
}

ListaEncadeada *buscarChaveListaEncadeada(ListaEncadeada *LE, int chave){
	ListaEncadeada *aux = LE;
	while (aux != NULL)
	{
		if(aux->chave == chave){
			return aux;
		}
		aux = aux->prox;
	}
	return NULL;
	
}

//Lista encadeada dupla
typedef struct{
	int chave;
	int *prox;
	int *ant;
}ListaEncadeadaDupla;

//Operações com Lista Encadeada Dupla
void desalocarListaEncadeadaDupla(ListaEncadeadaDupla **LED){
	ListaEncadeadaDupla *aux;
	if(LED != NULL){
		while((*LED) != NULL){
			aux = (*LED)->prox;
			free(*LED);
			(*LED) = aux;
		}
	}
}

void imprimirListaEncadeadaDupla(ListaEncadeadaDupla *LED, int chave){
	ListaEncadeadaDupla *aux = LED;
	while(aux != NULL){
		printf("<-[%d]->", aux->chave);
		aux = aux->prox;
	}
	printf("[NULL]\n");
}

void inserirChavevListaEncadeadaDupla(ListaEncadeadaDupla **LED, int chave){
	ListaEncadeadaDupla *aux;
	aux = malloc(sizeof(ListaEncadeadaDupla));
	aux->chave = chave;
	aux->ant = NULL;
	aux->prox = (*LED);
	if(*LED != NULL){
		(*LED)->ant = aux;
	}
	(*LED) = aux;
}
 
void removerChaveListaEncadeadaDupla(ListaEncadeadaDupla **LED, int chave){
	ListaEncadeadaDupla *aux;
	if(LED != NULL){
		while((*LED) != NULL){
			if((*LED)->chave == chave){
				aux = (*LED)->prox;
				if(aux != NULL){
					aux->ant = (*LED)->ant;
				}
				free(*LED);
				(*LED) = aux;
				return;
			}
			LED = &(*LED)->prox;
		}
	}
}

ListaEncadeadaDupla *buscarChaveListaEncadeadaDupla(ListaEncadeada *LED, int chave){
	ListaEncadeadaDupla *aux = LED;
	while (aux != NULL)
	{
		if(aux->chave == chave){
			return aux;
		}
		aux = aux->prox;
	}
	return NULL;	
}


//Operações numa lista encadeada circular
void desalocarListaEncadeadaCircular(ListaEncadeadaDupla **LEC){
	ListaEncadeadaDupla *aux, *ultimo = (*LEC)->ant;
	if(LEC != NULL){
		while((*LEC) != NULL){
            if(ultimo != (*LEC)){
                aux = (*LEC)->prox;
            }
            else{
                aux = NULL;
            }
			free(*LEC);
			(*LEC) = aux;
		}
	}
}


void inserirChaveListaEncadeadaCircular(ListaEncadeadaDupla **LEC, int chave){
    ListaEncadeadaDupla *aux = malloc(sizeof(ListaEncadeadaDupla));
    ListaEncadeadaDupla *auxMais2 = aux;
    aux->chave = chave;
    if((*LEC) == NULL){
        aux->prox = aux;
        aux->ant = aux;
    }
    else{
        aux->prox = (*LEC);
        aux->ant = (*LEC)->ant;
        (*LEC)->ant->prox = aux;
        (*LEC)->ant = aux;
    }
    (*LEC) = aux;
}