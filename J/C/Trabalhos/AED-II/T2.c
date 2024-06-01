#include <stdlib.h>
#include <stdio.h>
#include "gfx.h"

const unsigned short g_X_NODE_SIZE = 50;
const unsigned short g_Y_NODE_SIZE = 50;
const unsigned short g_X_SCREEN_SIZE = 800;
const unsigned short g_Y_SCREEN_SIZE = 600;
const unsigned short g_X_LIST_ORIGIN = g_X_NODE_SIZE;
const unsigned short g_Y_LIST_ORIGIN = g_Y_NODE_SIZE;
const unsigned short g_NODES_DISTANCE = 25;

// Declaração do tipo Lista Encadeada Simples
typedef struct LinkedList
{
    int valor;
    struct LinkedList *prox;
} LinkedList;

// ### Operações na Lista Encadeada Simples ###
// Inicializa uma Lista Encadeada Simples como vazia
void createLinkedList(LinkedList **LL)
{
    (*LL) = NULL;
}

// Desaloca os nós da Lista Encadeada Simples
void deleteLinkedList(LinkedList **LL)
{
    LinkedList *aux;
    // Garante que o ponteiro apontava para algo
    if (LL != NULL)
    {
        // Enquanto não chegar no fim da Lista desaloca o próximo nó e avança
        while ((*LL) != NULL)
        {
            aux = (*LL)->prox;
            free(*LL);
            (*LL) = aux;
        }
    }
}

// Insere um valor numa Lista Encadeada Simples de forma Ordenada
void insertValueOrderedLinkedList(LinkedList **LL, int valor)
{
    LinkedList *aux;
    if (LL != NULL)
    {
        while ((*LL) != NULL && (*LL)->valor < valor)
        {
            LL = &((*LL)->prox);
        }
        aux = malloc(sizeof(LinkedList));
        aux->valor = valor;
        aux->prox = (*LL);
        (*LL) = aux;
    }
}

int removeValueLinkedList(LinkedList **LL, int valor)
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

LinkedList *searchValueLinkedList(LinkedList *LL, int valor)
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

//### Lista duplamente encadeada
typedef struct DoublyLinkedList
{
    int valor;
    struct DoublyLinkedList *ant;
    struct DoublyLinkedList *prox;
} DoublyLinkedList;

void createDoublyLinkedList(DoublyLinkedList *DLL)
{
    if (DLL)
    {
        DLL->prox = NULL;
        DLL->ant = NULL;
    }
}

void deleteDoublyLinkedList(DoublyLinkedList *DLL)
{
    DoublyLinkedList *aux;
    if (DLL)
    {
        while (DLL->prox)
        {
            aux = DLL->prox->prox;
            free(DLL->prox);
            DLL->prox = aux;
        }
    }
}

void insertValueDoublyLinkedList(DoublyLinkedList *DLL, int valor)
{
    DoublyLinkedList *aux;
    if (DLL)
    {
        aux = malloc(sizeof(DoublyLinkedList));
        aux->valor = valor;
        aux->ant = DLL;
        aux->prox = DLL->prox;
        if (DLL->prox)
        {
            DLL->prox->ant = aux;
        }
        DLL->prox = aux;
    }
}

int removeValueDoublyLinkedList(DoublyLinkedList *DLL, int valor)
{
    DoublyLinkedList *aux;
    if (DLL)
    {
        while (DLL->prox)
        {
            if (DLL->prox->valor == valor)
            {
                aux = DLL->prox->prox;
                free(DLL->prox);
                if (aux)
                {
                    aux->ant = DLL;
                }
                DLL->prox = aux;
                return 1;
            }
            DLL = DLL->prox;
        }
    }
    return 0;
}

DoublyLinkedList *searchValueDoublyLinkedList(DoublyLinkedList DLL, int valor)
{
    while (DLL.prox)
    {
        if (DLL.prox->valor == valor)
        {
            return DLL.prox;
        }
        DLL = *(DLL.prox);
    }
    return NULL;
}

// ### Nó para fila ###
typedef struct QNode
{
    int valor;
    struct QNode *prox;
} QNode;

// ### Fila ###
typedef struct Queue
{
    struct QNode *frente, *tras;
} Queue;

// ### Operações com Fila
void createQueue(Queue *Q)
{
    if (Q)
    {
        Q->frente = NULL;
        Q->tras = NULL;
    }
}

void deleteQueue(Queue *Q)
{
    QNode *aux;
    if (Q)
    {
        while (Q->frente)
        {
            aux = Q->frente->prox;
            free(Q->frente);
            Q->frente = aux;
        }
        Q->tras = NULL;
    }
}

void enQueue(Queue *Q, int valor)
{
    QNode *aux;
    if (Q)
    {
        aux = malloc(sizeof(QNode));
        aux->valor = valor;
        aux->prox = NULL;

        if (Q->tras)
        {
            Q->tras->prox = aux;
            Q->tras = aux;
        }
        else
        {
            Q->tras = aux;
            Q->frente = aux;
        }
    }
}

int deQueue(Queue *Q)
{
    QNode *aux;
    if (Q)
    {
        if (Q->frente)
        {
            aux = Q->frente->prox;
            free(Q->frente);
            Q->frente = aux;
            if (Q->frente == NULL)
            {
                Q->tras = NULL;
            }
            return 1;
        }
    }
    return 0;
}

//### Nó para Pilha ### 
typedef struct SNode{
    int valor;
    struct SNode *prox;
}SNode;

//### Pilha ###
typedef struct Stack{
    SNode *topo;
}Stack;

//### Operações com Pilha ###
void createStack(Stack *S)
{
    if (S)
    {
        S->topo = NULL;
    }
}

void deleteStack(Stack *S)
{
    SNode *aux;
    if (S)
    {
        while (S->topo)
        {
            aux = S->topo->prox;
            free(S->topo);
            S->topo = aux;
        }
    }
}

void push(Stack *S, int valor)
{
    SNode *aux;
    if (S)
    {
        aux = malloc(sizeof(SNode));
        aux->valor = valor;
        aux->prox = S->topo;
        S->topo = aux;
    }
}

int pop(Stack *S)
{
    SNode *aux;
    if (S)
    {
        if (S->topo)
        {
            aux = S->topo->prox;
            free(S->topo);
            S->topo = aux;
            return 1;
        }
    }
    return 0;
}
// Inputs
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

void inverteString(char str[], int length)
{
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

char *intToString(int valor, char *str)
{
    int i = 0, isNegative = 0;
    if (valor == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if (valor < 0)
    {
        isNegative = 1;
        valor = -valor;
    }
    while (valor != 0)
    {
        str[i++] = '0' + (valor % 10);
        valor = valor / 10;
    }
    if (isNegative)
    {
        str[i++] = '-';
    }
    str[i] = '\0';
    inverteString(str, i);
    return str;
}
void drawNode(int x, int y, int valor)
{
    char v[4];
    gfx_rectangle(x, y, x + g_X_NODE_SIZE, y + g_Y_NODE_SIZE);
    intToString(valor, v);
    gfx_text((g_X_NODE_SIZE) / 2 + x, (g_Y_NODE_SIZE) / 2 + y - 5, v);
}

void drawArrow(int x, int y)
{
    gfx_line(x, y, x + 20, y);
    gfx_line(x + 10, y + 10, x + 20, y);
    gfx_line(x + 10, y - 10, x + 20, y);
}

void drawnUnderArrow(int x1, int y1, int x2, int y2)
{
    gfx_line(x1, y1, x1, y1 + 20);
    gfx_line(x1, y1 + 20, x2, y2 + 20);
    gfx_line(x2, y2, x2, y2 + 20);
    gfx_line(x2 - 10, y2 + 10, x2, y2);
    gfx_line(x2 + 10, y2 + 10, x2, y2);
}

void drawTwoArrow(int x, int y)
{
    gfx_line(x + 0, y - 10, x + 20, y - 10);
    gfx_line(x + 10, y, x + 20, y - 10);
    gfx_line(x + 10, y - 20, x + 20, y - 10);

    gfx_line(x - g_X_NODE_SIZE, y + 10, x - g_X_NODE_SIZE - 20, y + 10);
    gfx_line(x - g_X_NODE_SIZE - 10, y, x - g_X_NODE_SIZE - 20, y + 10);
    gfx_line(x - g_X_NODE_SIZE - 10, y + 20, x - g_X_NODE_SIZE - 20, y + 10);
}

void drawLinkedList(LinkedList *L)
{
    int x = g_X_LIST_ORIGIN, y = g_Y_LIST_ORIGIN;
    gfx_clear();
    while (L != NULL)
    {
        drawNode(x, y, L->valor);
        drawArrow(x + g_X_NODE_SIZE, y + (g_Y_NODE_SIZE) / 2);
        L = L->prox;
        x += g_X_NODE_SIZE + g_NODES_DISTANCE;
    }
    gfx_paint();
}

void drawDoublyLinkedList(DoublyLinkedList head)
{
    int x = g_X_LIST_ORIGIN, y = g_Y_LIST_ORIGIN;
    gfx_clear();

    gfx_rectangle(x, y, x + g_X_NODE_SIZE, y + g_Y_NODE_SIZE);
    drawTwoArrow(x + g_X_NODE_SIZE, y + g_Y_NODE_SIZE / 2);
    while (head.prox)
    {
        x += g_NODES_DISTANCE + g_X_NODE_SIZE;
        drawNode(x, y, head.prox->valor);
        drawTwoArrow(x + g_X_NODE_SIZE, y + g_Y_NODE_SIZE / 2);
        head = *(head.prox);
    }

    gfx_paint();
}

void drawQueue(Queue Q){
    int x = g_X_LIST_ORIGIN, y = g_Y_LIST_ORIGIN;
    gfx_clear();
    while (Q.frente)
    {
        drawNode(x, y, Q.frente->valor);
        drawArrow(x + g_X_NODE_SIZE, y + (g_Y_NODE_SIZE) / 2);
        Q.frente = Q.frente->prox;
        x += g_X_NODE_SIZE + g_NODES_DISTANCE;
    }
    gfx_paint();
}

void drawStack(Stack S){
   int x = g_X_LIST_ORIGIN, y = g_Y_LIST_ORIGIN;
    gfx_clear();
    while (S.topo)
    {
        drawNode(x, y, S.topo->valor);
        drawArrow(x + g_X_NODE_SIZE, y + (g_Y_NODE_SIZE) / 2);
        S.topo = S.topo->prox;
        x += g_X_NODE_SIZE + g_NODES_DISTANCE;
    }
    gfx_paint();
}

int main()
{
    char opcEstrutura, opcAcao;
    LinkedList *ListaOrdenada;
    DoublyLinkedList Cabeca;
    Queue Fila;
    Stack Pilha;
    int inputValue;
    createLinkedList(&ListaOrdenada);
    createDoublyLinkedList(&Cabeca);
    createQueue(&Fila);
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
                drawLinkedList(ListaOrdenada);
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
                    if (searchValueLinkedList(ListaOrdenada, inputValue) != NULL)
                    {
                        printf("O valor está presente na lista\n");
                    }
                    else
                    {
                        printf("O valor não está presente na lista\n");
                    }
                    break;
                case '2':
                    printf("### Inserção ###\nDigite o valor que deverá ser inserido na lista: ");
                    scanf("%d", &inputValue);
                    insertValueOrderedLinkedList(&ListaOrdenada, inputValue);
                    break;
                case '3':
                    printf("### Remoção ###\nDigite o valor que deverá ser removido da lista: ");
                    scanf("%d", &inputValue);
                    if (removeValueLinkedList(&ListaOrdenada, inputValue))
                    {
                        printf("Removido da lista uma instância do valor\n");
                    }
                    else
                    {
                        printf("O valor não estava presente na lista\n");
                    }
                    break;
                default:
                    printf("Opção inválida! Tente novamente\n");
                    break;
                }
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
                drawDoublyLinkedList(Cabeca);
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
                    printf("### Busca ###\nDigite o valor que deverá ser buscado: ");
                    scanf("%d", &inputValue);
                    if (searchValueDoublyLinkedList(Cabeca, inputValue) != NULL)
                    {
                        printf("O valor está presente na lista\n");
                    }
                    else
                    {
                        printf("O valor não está presente na lista\n");
                    }
                    break;
                case '2':
                    printf("### Inserção ###\nDigite o valor que deverá ser inserido na lista: ");
                    scanf("%d", &inputValue);
                    insertValueDoublyLinkedList(&Cabeca, inputValue);
                    break;
                case '3':
                    printf("### Remoção ###\nDigite o valor que deverá ser removido da lista: ");
                    scanf("%d", &inputValue);
                    if (removeValueDoublyLinkedList(&Cabeca, inputValue))
                    {
                        printf("Removido da lista uma instância do valor\n");
                    }
                    else
                    {
                        printf("O valor não estava presente na lista\n");
                    }
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
                drawQueue(Fila);
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
                    printf("### Inserção ###\nDigite o valor que deverá ser inserido no fim fila: ");
                    scanf("%d", &inputValue);
                    enQueue(&Fila, inputValue);
                    break;
                case '2':
                    printf("### Remoção ###\n");
                    if(deQueue(&Fila)){
                        printf("Removido o valor na frente da fila\n");
                    }
                    else{
                        printf("A lista já está vazia\n");
                    }
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
                drawStack(Pilha);
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
                    printf("### Inserção ###\nDigite o valor que deverá ser inserido no topo da pilha: ");
                    scanf("%d", &inputValue);
                    push(&Pilha, inputValue);
                    break;
                case '2':
                    printf("### Remoção ###\n");
                    if(pop(&Pilha)){
                        printf("Removido o valor no topo da pilha\n");
                    }
                    else{
                        printf("A pilha já está vazia\n");
                    }
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
    deleteLinkedList(&ListaOrdenada);
    deleteDoublyLinkedList(&Cabeca);
    deleteQueue(&Fila);
    deleteStack(&Pilha);
    return 0;
}