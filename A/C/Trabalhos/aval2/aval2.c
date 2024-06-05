#include <stdio.h>
#include <stdlib.h>
#include "./gfx/gfx.h"

const int MAXELEM = 10;

//  Struct para lista simplesmente encadeada sem no cabeca
typedef struct no
{
	int valor;
	struct no *prox;
} listaSimp;

typedef struct noc
{
    int valor;
    struct noc *ant;
    struct noc *prox;
} listaDup;

typedef struct nof
{
    int valor;
    struct nof *prox;
} fila;

typedef struct nop
{
    int valor;
    struct nop *prox;
} pilha;

//  Funcao para inserir elementos em lista simplesmente encadeada sem no cabeca
void insereListaSimp(listaSimp **inicio, int val)
{
	listaSimp *p = malloc(sizeof(listaSimp));
    listaSimp *it;
    it = (*inicio);
    if((it == NULL) || (it->valor >= val))
    {
        p->valor = val;
        p->prox = (*inicio);
        (*inicio) = p;
    }
    else
    {
        while((it->prox != NULL) && (it->prox->valor < val))
            it = it->prox;
        p->valor = val;
        p->prox = it->prox;
        it->prox = p;
    }
}

//  Funcao de busca de um elemento em lista simplesmente encadeada sem no cabeca
//  Retorna 1 caso o elemento for encontrado e 0 caso o elemento nao existir na lista
int buscaListaSimp(listaSimp **inicio, int val)
{
    listaSimp *p = NULL;
    p = (*inicio);
    while(p != NULL)
    {
        if(p->valor == val)
            return 1;
        p = p->prox;
    }
    return 0;
}

//  Funcao para remover um elemento de uma lista simplesmente encadeada
void removeListaSimp(listaSimp **inicio, int val)
{
    listaSimp *ant = NULL;
    listaSimp *p = NULL;
    p = (*inicio);
    while(p != NULL)
    {
        if(p->valor == val)
        {
            if(p == (*inicio))
                (**inicio) = *p->prox;
            else
                ant->prox = p->prox;
            free(p);
            return;
        }
        ant = p;
        p = p->prox;
    }
}

//  Funcao para desalocar uma lista simplesmente encadeada
void desalocaListaSimp(listaSimp **inicio)
{
    listaSimp *aux;
    if(inicio != NULL)
    {
        while((*inicio) != NULL)
        {
            aux = (*inicio)->prox;
            free(*inicio);
            (*inicio) = aux;
        }
    }
    (*inicio) = NULL;
}

//  Funcao para insercao em uma lista circular simplesmente encadeada 
void insereListaCirc(listaSimp **inicio, int val)
{
    listaSimp *p = malloc(sizeof(listaSimp));
    listaSimp *it;
    it = (*inicio);
    if((inicio == NULL) || ((*inicio)->valor >= val))
    {
        p->valor = val;
        p->prox = (*inicio);
        (*inicio) = p;
    }
    else
    {
        while(((it->prox != NULL)) && (it->prox->valor < val))
            it = it->prox;
        p->valor = val;
        p->prox = it->prox;
        it->prox = p;
    }
}


//  Funcao de busca em uma lista circular simplesmente encadeada
int buscaListaCirc(listaSimp **inicio, int val)
{
    listaSimp *p;
    p = (*inicio);
    if((*inicio)->valor == val)
        return 1;
    else if((*inicio)->prox != NULL)
    {
        p = p->prox;
        while(p->prox != inicio)
        {
            if(p->valor == val)
                return 1;
            p = p->prox;
        }
    }
    return 0;
}


//  Funcao para remover um elemento de uma lista circular simplesmente encadeada
void removeListaCirc()
{

}


//  Funcao para desalocar uma lista circular simplesmente encadeada
void desalocaListaCirc(listaSimp **inicio)
{
    listaSimp *aux;
    if(inicio != NULL)
    {
        while((*inicio) != NULL)
        {
            aux = (*inicio)->prox;
            free(*inicio);
            (*inicio) = aux;
        }
    }
    (*inicio) = NULL;
}

//  Funcao para inicalizar lista simplesmente encadeada
void initListaDup(listaDup **inicio)
{
    listaDup *head = malloc(sizeof(listaDup));
    head->prox = NULL;
    head->ant = NULL;
    (*inicio) = head;
}

//  Funcao para insercao de um elemento em uma lista duplamente encadeada
void insereListaDupla(listaDup **inicio, int val)
{
    listaDup *p = malloc(sizeof(listaDup));

    if((*inicio)->prox == NULL)
    {
	    p->valor = val;
	    p->prox = NULL;
        p->ant = (*inicio);
	    (*inicio)->prox = p;
    }
    else
    {
        p->valor = val;
        p->prox = (*inicio)->prox;
        p->ant = (*inicio);
        (*inicio)->prox->ant = p;
        (*inicio)->prox = p;
    }
}

//  Funcao para busca de um elemento em uma lista duplamente encadeada 
int buscaListaDupla(listaDup **inicio, int val)
{
    listaDup *p;
    p = (*inicio);
    if((*inicio)->valor == val)
        return 1;
    else if((*inicio)->prox != NULL)
    {
        while(p != NULL)
        {
            if(p->valor == val)
                return 1;
            p = p->prox;
        }
    }
    return 0;
}

//  Funcao para remocao de um elemento de uma lista duplamente encadeada
void removeListaDupla(listaDup **inicio, int val)
{
    listaDup *p;
    p = (*inicio);
    while(p != NULL)
    {
        if((p->valor == val) && (p->prox!=NULL))
        {
            p->ant->prox = p->prox;
            p->prox->ant = p->ant;
            free(p);
            return;
        }
        p=p->prox;
    }
}

//  Funcao para desalocar uma lista duplamente encadeada
void desalocaListaDupla(listaDup **inicio)
{
    listaDup *aux;
    if(inicio != NULL)
    {
        while((*inicio) != NULL)
        {
            aux = (*inicio)->prox;
            free(*inicio);
            (*inicio) = aux;
        }
    }
    (*inicio) = NULL;
}

//  Funcao para insercao de um elemento na fila
void insereFila(fila **inicio, int val)
{
    fila *p = malloc(sizeof(fila));
    fila *it;
    it = (*inicio);
    if((it == NULL))
    {
        p->valor = val;
        p->prox = (*inicio);
        (*inicio) = p;
    }
    else
    {
        while((it->prox != NULL))
            it = it->prox;
        p->valor = val;
        p->prox = it->prox;
        it->prox = p;
    }
}

//  Funcao para a remocao do primeiro elemento da fila
void removeFila(fila **inicio)
{
    fila *aux;
    if((inicio != NULL) && ((*inicio)->prox != NULL))
    {
        aux = (*inicio)->prox;
        free(*inicio);
        (*inicio) = aux;
    }
    else if(inicio != NULL)
    {
        free(*inicio);
        (*inicio) = NULL;
    }
}

//  Funcao para desalocar uma fila
void desalocaFila(fila **inicio)
{
    fila *aux;
    if(inicio != NULL)
    {
        while((*inicio) != NULL)
        {
            aux = (*inicio)->prox;
            free(*inicio);
            (*inicio) = aux;
        }
    }
    (*inicio) = NULL;
}

//  Funcao para insercao de um elemento na pilha
void inserePilha(pilha **inicio, int val)
{
    pilha *p = malloc(sizeof(pilha));
    pilha *it;
    it = (*inicio);
    if((it == NULL))
    {
        p->valor = val;
        p->prox = NULL;
        (*inicio) = p;
    }
    else
    {
        while((it->prox != NULL))
            it = it->prox;
        p->valor = val;
        p->prox = it->prox;
        it->prox = p;
    }
}

//  Funcao para remocao do elemento do topo da pilha
void removePilha(pilha **inicio)
{
    pilha *aux;
    pilha *it;
    it = (*inicio);
    if((inicio != NULL) && ((*inicio)->prox == NULL))
    {
        free(inicio);
        inicio = NULL;
    }
    else if((inicio != NULL) && ((*inicio)->prox != NULL))
    {
        while(it->prox != NULL)
        {
            aux = it;
            it = it->prox;
        }
        aux->prox = NULL;
        free(it);
        it = NULL;
    }
}

//  Funcao para desalocar uma pilha
void desalocaPilha(pilha **inicio)
{
    pilha *aux;
    if(inicio != NULL)
    {
        while((*inicio) != NULL)
        {
            aux = (*inicio)->prox;
            free(*inicio);
            (*inicio) = aux;
        }
    }
    (*inicio) = NULL;
}

//  Funcao para ignorar o '\n' do scanf
void iflush() {
    int c;
    while(((c = getchar()) != EOF) && (c != '\n'))
        continue;
}

int main()
{
    listaSimp *L1 = NULL;
    listaSimp *p1;

    listaDup *L2 = NULL;
    listaDup *p2;

    listaSimp *L3 = NULL;
    listaSimp *p3;

    fila *queue = NULL;
    fila *pfila;

    pilha *pil = NULL;
    pilha *ppil;

    int n=4;
    char menu='0';

    //  TESTES LISTA SIMPLEMENTE ENCADEADA
    printf("Lista simplesmente encadeada\n");
    while(n)
    {
        insereListaSimp(&L1, n);
        n--;
    }
    insereListaSimp(&L1, 6);
    insereListaSimp(&L1, 5);
    p1=L1;
    while(p1!=NULL)
    {
        printf("[%d]->", p1->valor);
        p1=p1->prox;
    }
    printf("\n");

    //  TESTES LISTA DUPLAMENTE ENCADEADA
    printf("Lista duplamente encadeada\n");
    initListaDup(&L2);
    insereListaDupla(&L2, 7);
    insereListaDupla(&L2, 3);
    insereListaDupla(&L2, 2);
    insereListaDupla(&L2, 5);

    removeListaDupla(&L2, 5);
    p2=L2;
    n=4;
    while(n)
    {
        printf("[%d]-", p2->valor);
        p2=p2->prox;
        n--;
    }
    printf("\n");
    printf("Achou? %d\n", buscaListaDupla(&L2, 7));

    //  TESTES FILA
    printf("Fila\n");
    n=1;
    while(n<=5)
    {
        insereFila(&queue, n);
        n++;
    }
    removeFila(&queue);
    removeFila(&queue);
    //desalocaFila(&queue);
    pfila = queue;
    if(pfila!=NULL)
    {
        while(pfila!=NULL)
        {
            printf("<-[%d]", pfila->valor);
            pfila=pfila->prox;
        }
    }
    printf("\n");

    // //  Testes lista cirular
    // printf("Lista circular\n");
    // insereListaCirc(&L3, 1);
    // insereListaCirc(&L3, 5);
    // insereListaCirc(&L3, 2);
    // insereListaCirc(&L3, 3);
    // insereListaCirc(&L3, 1);
    // n=5;
    // p3=L3;
    // while(n)
    // {
    //     printf("[%d]->", p3->valor);
    //     n--;
    // }
    // printf("\n");

    //  Testes com pilha
    printf("Pilha\n");
    for(int i=0; i<10; i++)
    {
        inserePilha(&pil, i);    
    }
    removePilha(&pil);
    removePilha(&pil);
    ppil = pil;
    for(int i=0; i<8; i++)
    {
        printf("[%d]<-", ppil->valor);
        ppil = ppil->prox;
    }
    printf("\n");


    desalocaListaSimp(&L1);
    desalocaListaDupla(&L2);
    desalocaListaCirc(&L3);
    desalocaFila(&queue);
    desalocaPilha(&pil);

    // while(menu=='0'){
    //     printf("\nAlocacao Encadeada\n[1] - Lista simplesmente encadeada\n[2] - Lista circular simplesmente encadedada\n[3] - Lista duplamente encadeada\n[4] - Fila\n[5] - Pilha\n[6] - Terminar o programa\nDigite uma opcao: ");
    //     scanf("%c", &menu);
    //     switch(menu)
    //     {
    //         case '1':
    //             do {
    //                 printf("\nLista simplesmente encadeada\n[0] - Voltar para o menu anterior\n[1] - Busca\n[2] - Insercao\n[3] - Remocao\nDigite uma opcao: ");
    //                 scanf("%c", &menu);
    //                 iflush();
    //                 switch(menu)
    //                 {
    //                     case '0':   //  Menu
    //                         menu='0';
    //                         break;
    //                     case '1':   //  Busca
    //                         menu='1';
    //                         break;
    //                     case '2':   //  Insercao
    //                         menu='1';
    //                         break;
    //                     case '3':   //  Remocao
    //                         menu='1';
    //                         break;
    //                     default:
    //                         system("clear");
    //                         printf("\nOpcao invalida!");
    //                         menu='1';
    //                         break;
    //                 }
    //             } while(menu=='1');
    //             break;
    //         case '2':
    //             do {
    //                 printf("\nLista circular simplesmente encadeada\n[0] - Voltar para o menu anterior\n[1] - Busca\n[2] - Insercao\n[3] - Remocao\nDigite uma opcao: ");
    //                 scanf("%c", &menu);
    //                 iflush();
    //                 switch(menu)
    //                 {
    //                     case '0':   //  Menu
    //                         menu='0';
    //                         break;
    //                     case '1':   //  Busca
    //                         menu='2';
    //                         break;
    //                     case '2':   //  Insercao
    //                         menu='2';
    //                         break;
    //                     case '3':   //  Remocao
    //                         menu='2';
    //                         break;
    //                     default:
    //                         system("clear");
    //                         printf("\nOpcao invalida!");
    //                         menu='2';
    //                         break;
    //                 }
    //             } while(menu=='2');
    //             break;
    //         case '3':
    //             do {
    //                 printf("\nLista duplamente encadeada\n[0] - Voltar para o menu anterior\n[1] - Busca\n[2] - Insercao\n[3] - Remocao\nDigite uma opcao: ");
    //                 scanf("%c", &menu);
    //                 iflush();
    //                 switch(menu)
    //                 {
    //                     case '0':   //  Menu
    //                         menu='0';
    //                         break;
    //                     case '1':   //  Busca
    //                         menu='3';
    //                         break;
    //                     case '2':   //  Insercao
    //                         menu='3';
    //                         break;
    //                     case '3':   //  Remocao
    //                         menu='3';
    //                         break;
    //                     default:
    //                         system("clear");
    //                         printf("\nOpcao invalida!");
    //                         menu='3';
    //                         break;
    //                 }
    //             } while(menu=='3');
    //             break;
    //         case '4':
    //             do {
    //                 printf("\nFila\n[0] - Voltar para o menu anterior\n[1] - Insercao\n[2] - Remocao\nDigite uma opcao: ");
    //                 scanf("%c", &menu);
    //                 iflush();
    //                 switch(menu)
    //                 {
    //                     case '0':   //  Menu
    //                         menu='0';
    //                         break;
    //                     case '1':   //  Insercao
    //                         menu='4';
    //                         break;
    //                     case '2':   //  Remocao
    //                         menu='4';
    //                         break;
    //                     default:
    //                         system("clear");
    //                         printf("\nOpcao invalida!\n");
    //                         menu='4';
    //                         break;
    //                 }
    //             } while(menu=='4');
    //             break;
    //         case '5':
    //             do {
    //                 printf("\nPilha\n[0] - Voltar para o menu anterior\n[1] - Insercao\n[2] - Remocao\nDigite uma opcao: ");
    //                 scanf("%c", &menu);
    //                 iflush();
    //                 switch(menu)
    //                 {
    //                     case '0':   //  Menu
    //                         menu='0';
    //                         break;
    //                     case '1':   //  Insercao
    //                         menu='5';
    //                         break;
    //                     case '2':   //  Remocao
    //                         menu='5';
    //                         break;
    //                     default:
    //                         system("clear");
    //                         printf("\nOpcao invalida!");
    //                         menu='5';
    //                         break;
    //                 }
    //             } while(menu=='5');
    //             break;
    //         case '6':
    //             system("clear");
    //             printf("Encerrando o programa...\n");
    //             return 0;
    //         default:
    //             system("clear");
    //             printf("\nOpcao invalida!");
    //             menu='0';
    //             break;
    //     }
    // }
    return 0;
}