/*
Listas impLLmentadas:
-Lista sequencial
	-Tamanho fixo
	-Dinâmica
-Lista Encadeada
	-Simples
	-Dupla
	-Circular

Funções Implementadas:
-Iniciar lista vazia
-Desalocar lista
-Imprimir lista
-Inserir chave
-Remover chave
-Buscar chave
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct Array
{
	int *L;
	int n;
}Array;

// Lista Encadeada Simples
typedef struct LinkedList
{
	int chave;
	struct LinkedList *prox;
} LinkedList;

// Operações na Lista Encadeada Simples
void createEmptyLinkedList(LinkedList **LL){
	(*LL) = NULL;
}

void deleteLinkedList(LinkedList **LL)
{
	LinkedList *aux;
	if (LL != NULL)
	{
		while ((*LL) != NULL)
		{
			aux = (*LL)->prox;
			free(*LL);
			(*LL) = aux;
		}
	}
}

void printLinkedList(LinkedList *LL)
{
	LinkedList *aux = LL;
	while (aux != NULL)
	{
		printf("[%d]->", aux->chave);
		aux = aux->prox;
	}
	printf("[NULL]\n");
}

void insertKeyLinkedList(LinkedList **LL, int chave)
{
	LinkedList *aux;
	if (LL != NULL)
	{
		aux = malloc(sizeof(LinkedList));
		aux->chave = chave;
		aux->prox = (*LL);
		(*LL) = aux;
	}
}

void removeKeyLinkedList(LinkedList **LL, int chave)
{
	LinkedList *aux;
	if (LL != NULL)
	{
		while ((*LL) != NULL)
		{
			if ((*LL)->chave == chave)
			{
				aux = (*LL)->prox;
				free(*LL);
				(*LL) = aux;
				return;
			}
			LL = &(*LL)->prox;
		}
	}
}

LinkedList *searchKeyLinkedList(LinkedList *LL, int chave)
{
	LinkedList *aux = LL;
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
typedef struct DoublyLinkedList
{
	int chave;
	struct DoublyLinkedList *prox;
	struct DoublyLinkedList *ant;
} DoublyLinkedList;

// Operações com Lista Encadeada Dupla
void createEmptyDoublyLinkedList(DoublyLinkedList **DLL){
	(*DLL) = NULL;
}

void deleteDoublyLinkedList(DoublyLinkedList **DLL)
{
	DoublyLinkedList *aux;
	if (DLL != NULL)
	{
		while ((*DLL) != NULL)
		{
			aux = (*DLL)->prox;
			free(*DLL);
			(*DLL) = aux;
		}
	}
}

void printDoublyLinkedList(DoublyLinkedList *DLL)
{
	DoublyLinkedList *aux = DLL;
	while (aux != NULL)
	{
		printf("<-[%d]->", aux->chave);
		aux = aux->prox;
	}
	printf("[NULL]\n");
}

void insertKeyDoublyLinkedList(DoublyLinkedList **DLL, int chave)
{
	DoublyLinkedList *aux;
	if (DLL != NULL)
	{
		aux = malloc(sizeof(DoublyLinkedList));
		aux->chave = chave;
		aux->ant = NULL;
		aux->prox = (*DLL);
		if (*DLL != NULL)
		{
			(*DLL)->ant = aux;
		}
		(*DLL) = aux;
	}
}

void removeKeyDoublyLinkedList(DoublyLinkedList **DLL, int chave)
{
	DoublyLinkedList *aux;
	if (DLL != NULL)
	{
		while ((*DLL) != NULL)
		{
			if ((*DLL)->chave == chave)
			{
				aux = (*DLL)->prox;
				if (aux != NULL)
				{
					aux->ant = (*DLL)->ant;
				}
				free(*DLL);
				(*DLL) = aux;
				return;
			}
			DLL = &(*DLL)->prox;
		}
	}
}

DoublyLinkedList *searchKeyDoublyLinkedList(DoublyLinkedList *DLL, int chave)
{
	DoublyLinkedList *aux = DLL;
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
void createEmptyCircularLinkedList(DoublyLinkedList **CLL){
	(*CLL) = NULL;
}

void deleteCircularLinkedList(DoublyLinkedList **CLL)
{
	DoublyLinkedList *aux, *ultimo = (*CLL)->ant;
	if (CLL != NULL)
	{
		while ((*CLL) != NULL)
		{
			if (ultimo != (*CLL))
			{
				aux = (*CLL)->prox;
			}
			else
			{
				aux = NULL;
			}
			free(*CLL);
			(*CLL) = aux;
		}
	}
}

void insertKeyLinkedListCircular(DoublyLinkedList **CLL, int chave)
{
	DoublyLinkedList *aux;
	if (CLL != NULL)
	{
		aux = malloc(sizeof(DoublyLinkedList));
		aux->chave = chave;
		if ((*CLL) == NULL)
		{
			aux->prox = aux;
			aux->ant = aux;
		}
		else
		{
			aux->prox = (*CLL);
			aux->ant = (*CLL)->ant;
			(*CLL)->ant->prox = aux;
			(*CLL)->ant = aux;
		}
		(*CLL) = aux;
	}
}

void removeKeyLinkedListCircular(DoublyLinkedList **CLL, int chave)
{
	DoublyLinkedList *aux;
	if ((CLL != NULL) && ((*CLL) != NULL))
	{
		aux = (*CLL)->prox;
		if ((aux == (*CLL)) && (aux->chave == chave))
		{
			free(*CLL);
			(*CLL) = NULL;
			return;
		}
		while (aux != (*CLL))
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