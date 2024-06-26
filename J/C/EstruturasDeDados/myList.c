/*
Listas implementadas:
-Lista Encadeada
	-Simples
	-Dupla
	-Circular

Funções Implementadas:
-Iniciar estrutura vazia
-Desalocar estrutura
-Imprimir estrutura
-Inserir chave
-Remover chave
-Buscar chave
*/
#include <stdlib.h>
#include <stdio.h>

// Lista Encadeada Simples
typedef struct LinkedList
{
	int chave;
	struct LinkedList *prox;
} LinkedList;

// Operações na Lista Encadeada Simples
void createLinkedList(LinkedList **LL){
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

LinkedList *mergeLinkedList(LinkedList **L1, LinkedList **L2){
	LinkedList *aux2, *aux1, *raiz = *L1;
	while((*L2) != NULL){
		if((*L1) != NULL){
			aux2 = (*L2)->prox;
			(*L2)->prox = (*L1)->prox;
			(*L1)->prox = (*L2);
			L1 = &(*L2)->prox;
			aux1 = aux2;
			L2 = &aux1;
      	}
		else{
			(*L1) = (*L2);
			return raiz;
		}
    }
	return raiz;
}

// Lista encadeada dupla
typedef struct DoublyLinkedList
{
	int chave;
	struct DoublyLinkedList *prox;
	struct DoublyLinkedList *ant;
} DoublyLinkedList;

// Operações com Lista Encadeada Dupla
void createDoublyLinkedList(DoublyLinkedList **DLL){
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

// Estrutura da lista circular é identica a estrutura da lista dupla

// Operações numa lista encadeada circular
void createCircularLinkedList(DoublyLinkedList **CLL){
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


int main(){
    LinkedList *A, *B, *R;

	createLinkedList(&A);
	createLinkedList(&B);
	createLinkedList(&R);

    insertKeyLinkedList(&A, 0);
    insertKeyLinkedList(&A, 5);
    insertKeyLinkedList(&A, 3);
    insertKeyLinkedList(&A, 2);
    insertKeyLinkedList(&A, 7);
    insertKeyLinkedList(&A, 12);

    insertKeyLinkedList(&B, 4);
    insertKeyLinkedList(&B, 15);
    insertKeyLinkedList(&B, 9);
    insertKeyLinkedList(&B, 10);
    insertKeyLinkedList(&B, 1);

    printLinkedList(A);
    printLinkedList(B);

    R = mergeLinkedList(&A, &B);
    
    printLinkedList(R);
    
    deleteLinkedList(&R);
    
    printLinkedList(R);

    return 0;
}