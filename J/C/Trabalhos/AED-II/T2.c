#include <stdlib.h>
#include <stdio.h>
#include "gfx.h"

const unsigned short g_X_NODE_SIZE = 75;
const unsigned short g_Y_NODE_SIZE = 50;
const unsigned short g_X_SCREEN_SIZE = 800;
const unsigned short g_Y_SCREEN_SIZE = 600;
static int g_X_NODE = g_X_NODE_SIZE;
static int g_Y_NODE = g_Y_NODE_SIZE;

// Lista Encadeada Simples
typedef struct LinkedList
{
    int valor;
    struct LinkedList *prox;
} LinkedList;

// Operações na Lista Encadeada Simples
void createLinkedList(LinkedList **LL)
{
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
        printf("[%d]->", aux->valor);
        aux = aux->prox;
    }
    printf("[NULL]\n");
}

void insertKeyLinkedListOrd(LinkedList **LL, int valor)
{
    LinkedList *aux;
    int stop = 1;
    if (LL != NULL)
    {
        while ((*LL) != NULL && stop)
        {
            if ((*LL)->valor < valor)
            {
                LL = &((*LL)->prox);
            }
            else{
                stop = 0;
            }
        }
        aux = malloc(sizeof(LinkedList));
        aux->valor = valor;
        aux->prox = (*LL);
        (*LL) = aux;
    }
}

int removeKeyLinkedList(LinkedList **LL, int valor)
{
    LinkedList *aux;
    if (LL != NULL)
    {
        while ((*LL) != NULL)
        {
            if ((*LL)->valor == valor)
            {
                aux = (*LL)->prox;
                free(*LL);
                (*LL) = aux;
                return 1;
            }
            LL = &(*LL)->prox;
        }
    }
    return 0;
}

LinkedList *searchKeyLinkedList(LinkedList *LL, int valor)
{
    LinkedList *aux = LL;
    while (aux != NULL)
    {
        if (aux->valor == valor)
        {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}


//Inputs
char readChar()
{
    char c;
    // Enquanto o caracter inserido for inválido, continue lendo do teclado
    while ((c = getchar()) < '!')
        ;
    // Após ler, descarta qualquer outro caracter no buffer de teclado
    while (getchar() != '\n')
        ;
    // Retorna o caracter lido
    return c;
}


void inverteString(char str[], int length){
    int start = 0, end = length - 1;
    char temp;
    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

char *intToString(int valor, char *str){
    int i = 0, isNegative = 0;
    if(valor == 0){
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if(valor < 0){
        isNegative = 1;
        valor = -valor;
    }
    while(valor != 0){
        str[i++] ='0' + (valor % 10);
        valor = valor / 10;
    }
    if(isNegative){
        str[i++] = '-';
    }
    str[i] = '\0';
    inverteString(str, i);
    return str;
}
void drawNode(int valor){
    char v[4];
    gfx_rectangle(g_X_NODE, g_Y_NODE, g_X_NODE + g_X_NODE_SIZE, g_Y_NODE + g_Y_NODE_SIZE);
    intToString(valor, v);
    gfx_text((g_X_NODE_SIZE)/2 + g_X_NODE, (g_Y_NODE_SIZE)/2 + g_Y_NODE - 5, v);
    g_X_NODE += g_X_NODE_SIZE + 50;
}

void drawArrow(){
    int x = g_X_NODE - 35, y = g_Y_NODE + g_Y_NODE_SIZE/2;
    gfx_line(x, y, x + 20, y);
    gfx_line(x + 10, y + 10, x + 20, y);
    gfx_line(x + 10, y - 10, x + 20, y);
}

void drawLinkedList(LinkedList *L){
    gfx_clear();
    g_X_NODE = g_X_NODE_SIZE;
    g_Y_NODE = g_Y_NODE_SIZE;
    while(L != NULL){
        drawNode(L->valor);
        drawArrow();
        L = L->prox;
    }
    gfx_paint();
}

int main()
{
    char opcEstrutura, opcAcao;
    LinkedList *L;
    int inputValue;
    createLinkedList(&L);
    gfx_init(g_X_SCREEN_SIZE, g_Y_SCREEN_SIZE, "Alocação Encadeada");
    opcEstrutura = 1;
    while (opcEstrutura != '0')
    {
        // 1 - Busca, inserção e remoção em lista simplesmente encadeada sem nó cabeça ordenada;
        // 2 - Busca, inserção e remoção em lista circular simplesmente encadeada sem nó cabeça ordenada;
        // 3 -Busca, inserção e remoção em lista duplamente encadeada com nó cabeça (sem ordenação);
        // 4 -Inserção e remoção em fila (FIFO);
        // 5 -Inserção e remoção em pilha (LIFO).
        printf("0 - Encerrar programa\
        \n1 - Busca, inserção e remoção em lista simplesmente encadeada sem nó cabeça ordenada;\
        \n2 - Busca, inserção e remoção em lista circular simplesmente encadeada sem nó cabeça ordenada;\
        \n3 - Busca, inserção e remoção em lista duplamente encadeada com nó cabeça (sem ordenação);\
        \n4 - Inserção e remoção em fila (FIFO);\
        \n5 - Inserção e remoção em pilha (LIFO).\
        \nDigite uma opção: ");
        opcEstrutura = readChar();
        system("clear");
        opcAcao = 1;
        switch (opcEstrutura)
        {
        case '0':
            break;
        case '1':
            while (opcAcao != '0')
            {
                printf("### Lista simplesmente encadeada sem nó cabeça ordenada ###\n");
                printf("Lista de operações:\
                \n0 - Voltar\
                \n1 - Busca\
                \n2 - Inserção\
                \n3 - Remoção\
                \nDigite uma opção:");
                opcAcao = readChar();
                switch (opcAcao)
                {
                case '0':
                    break;
                case '1':
                    printf("### Busca ###\nDigite o valor que deverá ser buscado: ");
                    scanf("%d", &inputValue);
                    if(searchKeyLinkedList(L, inputValue) != NULL){
                        printf("O valor está presente na lista\n");
                    }
                    else{
                        printf("O valor não está presente na lista\n");
                    }
                    break;
                case '2':
                    printf("### Inserção ###\nDigite o valor que deverá ser inserido na lista: ");
                    scanf("%d", &inputValue);
                    insertKeyLinkedListOrd(&L, inputValue);
                    break;
                case '3':
                    printf("### Remoção ###\nDigite o valor que deverá ser removido da lista: ");
                    scanf("%d", &inputValue);
                    if(removeKeyLinkedList(&L, inputValue)){
                        printf("Removido da lista uma instância do valor\n");
                    }
                    else{
                        printf("O valor não estava presente na lista\n");
                    }
                    break;
                default:
                    printf("Opção inválida! Tente novamente\n");
                    break;
                }
                drawLinkedList(L);
            }
            break;
        case '2':
            while (opcAcao != '0')
            {
                printf("### lista circular simplesmente encadeada sem nó cabeça ordenada ###\n");
                printf("Lista de operações:\
                \n0 - Voltar\
                \n1 - Busca\
                \n2 - Inserção\
                \n3 - Remoção\
                \nDigite uma opção:");
                opcAcao = readChar();
                system("clear");
                switch (opcAcao)
                {
                case '0':
                    break;
                case '1':

                    break;
                case '2':

                    break;
                case '3':

                    break;
                default:
                    printf("Opção inválida! Tente novamente\n");
                    break;
                }
            }
            break;
        case '3':
            while (opcAcao != '0')
            {
                printf("### Lista duplamente encadeada com nó cabeça ###\n");
                printf("Lista de operações:\
                \n0 - Voltar\
                \n1 - Busca\
                \n2 - Inserção\
                \n3 - Remoção\
                \nDigite uma opção:");
                opcAcao = readChar();
                switch (opcAcao)
                {
                case '0':
                    break;
                case '1':

                    break;
                case '2':

                    break;
                case '3':

                    break;
                default:
                    printf("Opção inválida! Tente novamente\n");
                    break;
                }
            }
            break;
        case '4':

            while (opcAcao != '0')
            {
                printf("### Fila ###\n");
                printf("Lista de operações:\
                \n0 - Voltar\
                \n1 - Inserção\
                \n2 - Remoção\
                \nDigite uma opção:");
                opcAcao = readChar();
                switch (opcAcao)
                {
                case '0':
                    break;
                case '1':

                    break;
                case '2':

                    break;
                default:
                    printf("Opção inválida! Tente novamente\n");
                    break;
                }
            }
            break;
        case '5':
            while (opcAcao != '0')
            {
                printf("### Pilha ###\n");
                printf("Lista de operações:\
                \n0 - Voltar\
                \n1 - Inserção\
                \n2 - Remoção\
                \nDigite uma opção:");
                opcAcao = readChar();
                switch (opcAcao)
                {
                case '0':
                    break;
                case '1':

                    break;
                case '2':

                    break;
                default:
                    printf("Opção inválida! Tente novamente\n");
                    break;
                }
            }
            break;
        default:
            printf("Opção inválida! Tente novamente\n");
            break;
        }
    }
    gfx_quit();
    deleteLinkedList(&L);
    return 0;
}