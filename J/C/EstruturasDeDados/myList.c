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
#include <stdio.h>

typedef struct
{
	int *L;
	int n;
} ListaSequencial;

// Lista Encadeada Simples
typedef struct ListaEncadeada
{
	int chave;
	struct ListaEncadeada *prox;
} ListaEncadeada;

// Operações na Lista Encadeada Simples
void desalocarListaEncadeada(ListaEncadeada **LE)
{
	ListaEncadeada *aux;
	if (LE != NULL)
	{
		while ((*LE) != NULL)
		{
			aux = (*LE)->prox;
			free(*LE);
			(*LE) = aux;
		}
	}
}

void imprimirListaEncadeada(ListaEncadeada *LE)
{
	ListaEncadeada *aux = LE;
	while (aux != NULL)
	{
		printf("[%d]->", aux->chave);
		aux = aux->prox;
	}
	printf("[NULL]\n");
}

void inserirChaveListaEncadeada(ListaEncadeada **LE, int chave)
{
	ListaEncadeada *aux;
	if (LE != NULL)
	{
		aux = malloc(sizeof(ListaEncadeada));
		aux->chave = chave;
		aux->prox = (*LE);
		(*LE) = aux;
	}
}

void removerChaveListaEncadeada(ListaEncadeada **LE, int chave)
{
	ListaEncadeada *aux;
	if (LE != NULL)
	{
		while ((*LE) != NULL)
		{
			if ((*LE)->chave == chave)
			{
				aux = (*LE)->prox;
				free(*LE);
				(*LE) = aux;
				return;
			}
			LE = &(*LE)->prox;
		}
	}
}

ListaEncadeada *buscarChaveListaEncadeada(ListaEncadeada *LE, int chave)
{
	ListaEncadeada *aux = LE;
	while (aux != NULL)
	{
		if (aux->chave == chave)
		{
			return aux;
		}
		aux = aux->prox;
	}
	return NULL;
}

// Lista encadeada dupla
typedef struct ListaEncadeadaDupla
{
	int chave;
	struct ListaEncadeadaDupla *prox;
	struct ListaEncadeadaDupla *ant;
} ListaEncadeadaDupla;

// Operações com Lista Encadeada Dupla
void desalocarListaEncadeadaDupla(ListaEncadeadaDupla **LED)
{
	ListaEncadeadaDupla *aux;
	if (LED != NULL)
	{
		while ((*LED) != NULL)
		{
			aux = (*LED)->prox;
			free(*LED);
			(*LED) = aux;
		}
	}
}

void imprimirListaEncadeadaDupla(ListaEncadeadaDupla *LED)
{
	ListaEncadeadaDupla *aux = LED;
	while (aux != NULL)
	{
		printf("<-[%d]->", aux->chave);
		aux = aux->prox;
	}
	printf("[NULL]\n");
}

void inserirChaveListaEncadeadaDupla(ListaEncadeadaDupla **LED, int chave)
{
	ListaEncadeadaDupla *aux;
	if (LED != NULL)
	{
		aux = malloc(sizeof(ListaEncadeadaDupla));
		aux->chave = chave;
		aux->ant = NULL;
		aux->prox = (*LED);
		if (*LED != NULL)
		{
			(*LED)->ant = aux;
		}
		(*LED) = aux;
	}
}

void removerChaveListaEncadeadaDupla(ListaEncadeadaDupla **LED, int chave)
{
	ListaEncadeadaDupla *aux;
	if (LED != NULL)
	{
		while ((*LED) != NULL)
		{
			if ((*LED)->chave == chave)
			{
				aux = (*LED)->prox;
				if (aux != NULL)
				{
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

ListaEncadeadaDupla *buscarChaveListaEncadeadaDupla(ListaEncadeadaDupla *LED, int chave)
{
	ListaEncadeadaDupla *aux = LED;
	while (aux != NULL)
	{
		if (aux->chave == chave)
		{
			return aux;
		}
		aux = aux->prox;
	}
	return NULL;
}

// Operações numa lista encadeada circular
void desalocarListaEncadeadaCircular(ListaEncadeadaDupla **LEC)
{
	ListaEncadeadaDupla *aux, *ultimo = (*LEC)->ant;
	if (LEC != NULL)
	{
		while ((*LEC) != NULL)
		{
			if (ultimo != (*LEC))
			{
				aux = (*LEC)->prox;
			}
			else
			{
				aux = NULL;
			}
			free(*LEC);
			(*LEC) = aux;
		}
	}
}

void inserirChaveListaEncadeadaCircular(ListaEncadeadaDupla **LEC, int chave)
{
	ListaEncadeadaDupla *aux;
	if (LEC != NULL)
	{
		aux = malloc(sizeof(ListaEncadeadaDupla));
		aux->chave = chave;
		if ((*LEC) == NULL)
		{
			aux->prox = aux;
			aux->ant = aux;
		}
		else
		{
			aux->prox = (*LEC);
			aux->ant = (*LEC)->ant;
			(*LEC)->ant->prox = aux;
			(*LEC)->ant = aux;
		}
		(*LEC) = aux;
	}
}

void removerChaveListaEncadeadaCircular(ListaEncadeadaDupla **LEC, int chave)
{
	ListaEncadeadaDupla *aux;
	if ((LEC != NULL) && ((*LEC) != NULL))
	{
		aux = (*LEC)->prox;
		if ((aux == (*LEC)) && (aux->chave == chave))
		{
			free(*LEC);
			(*LEC) = NULL;
			return;
		}
		while (aux != (*LEC))
		{
			if(aux->chave == chave){
				aux->ant->prox = aux->prox;
				aux->prox->ant = aux->ant;
				free(aux); 
				return;
			}
			if(aux->prox->chave == chave){
				aux->prox = aux->prox->prox;
				aux->prox->prox->ant = aux->prox->ant;
				free(aux->prox);
				return;
			}
			aux = aux->prox;
		}
	}
}