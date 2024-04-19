#include <stdio.h>
#include <stdlib.h>

typedef struct ListaEncadeada
{
    int chave;
    struct ListaEncadeada *prox;
} ListaEncadeada;

void insere(ListaEncadeada **inicio, int val)
{
    ListaEncadeada *p = malloc(sizeof(ListaEncadeada));
    p->chave = val;
    p->prox = *inicio;
    *inicio = p;
}

ListaEncadeada *buscaVal(ListaEncadeada *inicio, int val)
{
    if (inicio != NULL)
    {
        printf("\nNumero atual %d\n", inicio->chave);
        if (val == inicio->chave)
        {
            return inicio;
        }
        return buscaVal(inicio->prox, val);
    }
    return NULL;
}

void remover(ListaEncadeada **inicio, int val)
{
    ListaEncadeada *p, *aux;
    p = buscaVal(*inicio, val);
    if (p != NULL)
    {
        aux = p->prox;
        printf("\nRemovido o numero %d\n", p->chave);
        free(p);
        p = aux;
    }
}

void desalocarLista(ListaEncadeada *inicio)
{
    if (inicio != NULL)
    {
        if (inicio->prox != NULL)
        {
            desalocarLista(inicio->prox);
        }
        printf("\nLiberado o numero %d\n", inicio->chave);
        free(inicio);
    }
}

int main()
{
    ListaEncadeada *L = NULL;
    ListaEncadeada *p;

    insere(&L, 4);
    insere(&L, 3);
    insere(&L, 2);
    insere(&L, 1);
    insere(&L, 0);

    p = L;
    while (p != NULL)
    {
        printf("[%i]->", p->chave);
        p = p->prox;
    }

    printf("\n");

    remover(&L, 2);
    printf("\nSaiu\n");
    p = L;
    while (p != NULL)
    {
        printf("\nEntrou\n");
        printf("[%i]->", p->chave);
        p = p->prox;
    }

    desalocarLista(L);

    return 0;
}