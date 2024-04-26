// Grafo
#include <stdio.h>
#include <stdlib.h>

struct ListaEncadeada
{
    struct Grafo *g;
    struct ListaEncadeada *prox;
};

struct Grafo
{
    int chave;
    struct ListaEncadeada *arestas;
};

void inserirVertice(struct ListaEncadeada **grafos, int chave)
{
    struct ListaEncadeada *p = malloc(sizeof(struct ListaEncadeada));
    p->g = malloc(sizeof(struct Grafo));
    p->prox = *grafos;
    p->g->chave = chave;
    p->g->arestas = NULL;
    *grafos = p;
}

void removerVertice(struct ListaEncadeada **grafos, int chave)
{
    struct ListaEncadeada *aux1, *aux2;
    if (grafos != NULL)
    {
        while ((*grafos) != NULL)
        {
            if ((*grafos)->g->chave != chave)
            {
                grafos = &(*grafos)->prox;
            }
            else
            {
                while ((*grafos)->g->arestas != NULL)
                {
                    aux2 = (*grafos)->g->arestas->prox;
                    free((*grafos)->g->arestas);
                    (*grafos)->g->arestas = aux2;
                }
                aux1 = (*grafos)->prox;
                free((*grafos)->g);
                free(*grafos);
                (*grafos) = aux1;
            }
        }
    }
}

void inserirAresta(struct ListaEncadeada **grafos, int chaveOrig, int chaveDest)
{
    struct ListaEncadeada **aux1 = grafos, *aux2;
    if (aux1 != NULL)
    {
        while ((*aux1) != NULL)
        {
            if ((*aux1)->g->chave != chaveOrig)
            {
                aux1 = &(*aux1)->prox;
            }
            else
            {
                while (*(grafos) != NULL)
                {
                    if ((*grafos)->g->chave != chaveDest)
                    {
                        grafos = &(*grafos)->prox;
                    }
                    else
                    {
                        aux2 = malloc(sizeof(struct ListaEncadeada));
                        aux2->g = (*grafos)->g;
                        aux2->prox = (*aux1)->g->arestas;
                        (*aux1)->g->arestas = aux2;
                        return;
                    }
                }
            }
        }
    }
}

void desalocar(struct ListaEncadeada **grafos)
{
    struct ListaEncadeada *aux1, *aux2;
    printf("Desalocando...\n");
    if (grafos != NULL)
    {
        while ((*grafos) != NULL)
        {
            while ((*grafos)->g->arestas != NULL)
            {
                aux2 = (*grafos)->g->arestas->prox;
                free((*grafos)->g->arestas);
                (*grafos)->g->arestas = aux2;
            }
            aux1 = (*grafos)->prox;
            free((*grafos)->g);
            free((*grafos));
            (*grafos) = aux1;
        }
    }
}

void imprimirVertices(struct ListaEncadeada *grafos)
{
    struct ListaEncadeada *p = grafos;
    printf("\nVertices do Grafo\n");
    while (p != NULL)
    {
        printf("[%i] ", p->g->chave);
        p = p->prox;
    }
    printf("\n");
}

void imprimirArestar(struct ListaEncadeada *grafos)
{
    struct ListaEncadeada *p = grafos, *k;
    while (p != NULL)
    {
        printf("Arestas a partir de [%i]\n", p->g->chave);
        k = p->g->arestas;
        while (k != NULL)
        {
            printf("   [%i]\n", k->g->chave);
            k = k->prox;
        }
        p = p->prox;
        printf("\n");
    }
}

int main()
{
    struct ListaEncadeada *G = NULL;
    inserirVertice(&G, 4);
    inserirVertice(&G, 3);
    inserirVertice(&G, 2);
    inserirVertice(&G, 1);
    imprimirVertices(G);
    inserirAresta(&G, 1, 2);
    inserirAresta(&G, 2, 3);
    inserirAresta(&G, 3, 4);
    inserirAresta(&G, 4, 1);
    imprimirArestar(G);
    desalocar(&G);
    imprimirVertices(G);
    return 0;
}
