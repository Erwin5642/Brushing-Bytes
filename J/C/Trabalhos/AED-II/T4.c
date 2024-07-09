
#include <stdlib.h>
#include <stdio.h>
#include "gfx.h"
#include <time.h>

#define g_NODE_WIDTH 30
#define g_NODE_HEIGHT 30
#define g_SCREEN_WIDTH 1200
#define g_SCREEN_HEIGHT 800
#define g_X_TREE_ORIGIN 600
#define g_Y_TREE_ORIGIN 30
#define g_NODES_DISTANCE 50

typedef struct AVLTree
{
    int value, balance;
    struct AVLTree *left;
    struct AVLTree *right;
} AVLTree;

// Desaloca todos os nós de uma árvore binária de busca
void deleteSearchTree(AVLTree **T)
{
    if (T)
    {
        if (*T)
        {
            if ((*T)->left)
            {
                deleteSearchTree(&(*T)->left);
            }
            if ((*T)->right)
            {
                deleteSearchTree(&(*T)->right);
            }
            free((*T));
            *T = NULL;
        }
    }
}

AVLTree *newNodeSearchTree(int value)
{
    AVLTree *aux = malloc(sizeof(AVLTree));
    aux->value = value;
    aux->left = aux->right = NULL;
    aux->balance = 0;
    return aux;
}

// Insere um valor numa árvore binária de busca
void insertValueSearchTree(AVLTree **T, int value)
{
    if (T)
    {
        while (*T)
        {
            if ((*T)->value > value)
            {
                T = &(*T)->left;
            }
            else
            {
                T = &(*T)->right;
            }
        }
        (*T) = newNodeSearchTree(value);
    }
}

void leftRotation(AVLTree **T){
    AVLTree *aux;
    aux = *T;
    *T = (*T)->right;
    aux->right = (*T)->left;
    (*T)->left = aux;
    
}

void rightRotation(AVLTree **T){
    AVLTree *aux;
    aux = *T;
    *T = (*T)->left;
    aux->left = (*T)->right;
    (*T)->right = aux;
}

void leftRightRotation(AVLTree **T){
    leftRotation(&(*T)->left);
    rightRotation(T);
}

void rightLeftRotation(AVLTree **T){
    rightRotation(&(*T)->right);
    leftRotation(T);
}

void balanceAVLTree(){

}

// Retorna um ponteiro para o menor nó na árvore binária de busca
AVLTree *minSearchTree(AVLTree *T)
{
    if (T)
    {
        // Percorre a árvore até encontrar o nó mais à esquerda
        while (T->left)
        {
            T = T->left;
        }
        // Retorna o nó com o menor valor
        return T;
    }
    // Retorna NULL se a árvore era vazia
    return NULL;
}

// Retorna um ponteiro para o maior nó na árvore binária de busca
AVLTree *maxSearchTree(AVLTree *T)
{
    if (T)
    {
        // Percorre a árvore até encontrar o nó mais à direita
        while (T->right)
        {
            T = T->right;
        }
        // Retorna o nó com o maior valor
        return T;
    }
    // Retorna NULL se a árvore era vazia
    return NULL;
}

// Retorna um ponteiro para o nó com valor buscado ou NULL caso ele não exista na árvore binária de busca
AVLTree *searchValueSearchTree(AVLTree *T, int value)
{
    // Percorre a árvore enquanto ela não vazia ou houverem valores possíveis para se analisar
    while (T)
    {
        // Se o valor buscado estiver no nó ou nos nós a esquerda ou direita, retorna o endereço deles
        if (T->value == value)
        {
            return T;
        }
        if (T->value > value)
        {
            T = T->left;
        }
        else
        {
            T = T->right;
        }
    }
    // Se a árvore era vazia ou o valor não encontrado retorna NULL
    return NULL;
}

// Retorna um ponteiro para o sucessor de um dado valor na árvore binária de busca
AVLTree *sucessorNodeSearchTree(AVLTree *T, int value)
{
    AVLTree *ancestralNode = NULL;
    // Se a árvore não for vazia efetua uma busca pelo valor que se deseja descobrir o sucessor
    // Enquanto mantém um ponteiro para o último nó em que foi efetuado uma "virada para esquerda"
    // Que será o ancestral mais baixo que possui um nó filho à esquerda que é ancestral do nó buscado
    while (T)
    {
        if (T->value < value)
        {
            T = T->right;
        }
        else if (T->value > value)
        {
            ancestralNode = T;
            T = T->left;
        }
        else if (T->right)
        {
            // No caso do nó com o valor buscado tiver filho à direita, o sucessor
            // será o menor valor na sub-árvore direita dele
            return minSearchTree(T->right);
        }
        else
        {
            // Caso não exista a sub-árvore direita, o sucessor será o nó ancestral que foi mantido durante a busca
            return ancestralNode;
        }
    }
    return NULL;
}

// Retorna um ponteiro para o antecessor de um dado valor na árvore binária de busca
AVLTree *predecessorNodeSearchTree(AVLTree *T, int value)
{
    AVLTree *ancestralNode = NULL;
    // Se a árvore não for vazia efetua uma busca pelo valor que se deseja descobrir o antecessor
    // Enquanto mantém um ponteiro para o último nó em que foi efetuado uma "virada para direita"
    // Que será o ancestral mais baixo que possui um nó filho à direita que é ancestral do nó buscado
    while (T)
    {
        if (T->value < value)
        {
            ancestralNode = T;
            T = T->right;
        }
        else if (T->value > value)
        {
            T = T->left;
        }
        else if (T->left)
        {
            // No caso do nó com o valor buscado tiver filho à direita, o antecessor
            // será o maior valor na sub-árvore esquerda dele
            return maxSearchTree(T->left);
        }
        else
        {
            // Caso não exista a sub-árvore esquerda, o antecessor será o nó ancestral que foi mantido durante a busca
            return ancestralNode;
        }
    }
    return NULL;
}


void drawNode(int x, int y, int value)
{
    char v[10];
    int largura, altura;
    gfx_set_color(0, 0, 0);
    gfx_filled_rectangle(x + 1, y + 1, x + g_NODE_WIDTH - 1, y + g_NODE_HEIGHT - 1);
    gfx_set_color(255, 255, 255);
    gfx_rectangle(x, y, x + g_NODE_WIDTH, y + g_NODE_HEIGHT);
    // Guarda o valor na string v
    sprintf(v, "%d", value);
    gfx_get_text_size(v, &largura, &altura);
    gfx_text(x + g_NODE_WIDTH / 2 - largura / 2, y + g_NODE_HEIGHT / 2 - altura / 2, v);
}

void drawTree(AVLTree *T, int x, int y, int dist)
{
    if (T)
    {
        dist /= 2;
        if (T->left)
        {
            gfx_line(x, y + g_NODE_HEIGHT/2, x - dist, y + g_NODES_DISTANCE + g_NODE_HEIGHT/2);
            drawTree(T->left, x - dist, y + g_NODES_DISTANCE, dist);
        }
        if (T->right)
        {
            gfx_line(x, y + g_NODE_HEIGHT / 2, x + dist, y + g_NODES_DISTANCE + g_NODE_HEIGHT / 2);
            drawTree(T->right, x + dist, y + g_NODES_DISTANCE, dist);
        }
        drawNode(x - g_NODE_WIDTH / 2, y, T->value);
    }
}

int main()
{
    AVLTree *root = NULL;


    gfx_init(g_SCREEN_WIDTH, g_SCREEN_HEIGHT, "Arvore de Busca");
    
    insertValueSearchTree(&root, 3);
    insertValueSearchTree(&root, 5);
    insertValueSearchTree(&root, 7);

    insertValueSearchTree(&root, 2);
    insertValueSearchTree(&root, 4);
    insertValueSearchTree(&root, 6);
    insertValueSearchTree(&root, 8);

    drawTree(root, g_X_TREE_ORIGIN, g_Y_TREE_ORIGIN, g_SCREEN_WIDTH / 2);
    gfx_paint();
    getchar();

    leftRotation(&root);
    gfx_clear();
    drawTree(root, g_X_TREE_ORIGIN, g_Y_TREE_ORIGIN, g_SCREEN_WIDTH / 2);
    gfx_paint();
    getchar();
    gfx_clear();
    deleteSearchTree(&root);

    insertValueSearchTree(&root, 7);
    insertValueSearchTree(&root, 5);
    insertValueSearchTree(&root, 3);

    insertValueSearchTree(&root, 2);
    insertValueSearchTree(&root, 4);
    insertValueSearchTree(&root, 6);
    insertValueSearchTree(&root, 8);

    drawTree(root, g_X_TREE_ORIGIN, g_Y_TREE_ORIGIN, g_SCREEN_WIDTH / 2);
    gfx_paint();
    getchar();

    rightRotation(&root);
    gfx_clear();
    drawTree(root, g_X_TREE_ORIGIN, g_Y_TREE_ORIGIN, g_SCREEN_WIDTH / 2);
    gfx_paint();
    getchar();
    gfx_clear();
    deleteSearchTree(&root);


    insertValueSearchTree(&root, 7);
    insertValueSearchTree(&root, 3);
    insertValueSearchTree(&root, 5);

    insertValueSearchTree(&root, 2);
    insertValueSearchTree(&root, 4);
    insertValueSearchTree(&root, 6);
    insertValueSearchTree(&root, 8);

    drawTree(root, g_X_TREE_ORIGIN, g_Y_TREE_ORIGIN, g_SCREEN_WIDTH / 2);
    gfx_paint();
    getchar();

    leftRightRotation(&root);
    gfx_clear();
    drawTree(root, g_X_TREE_ORIGIN, g_Y_TREE_ORIGIN, g_SCREEN_WIDTH / 2);
    gfx_paint();
    getchar();
    gfx_clear();
    deleteSearchTree(&root);

    insertValueSearchTree(&root, 3);
    insertValueSearchTree(&root, 7);
    insertValueSearchTree(&root, 5);

    insertValueSearchTree(&root, 2);
    insertValueSearchTree(&root, 4);
    insertValueSearchTree(&root, 6);
    insertValueSearchTree(&root, 8);

    drawTree(root, g_X_TREE_ORIGIN, g_Y_TREE_ORIGIN, g_SCREEN_WIDTH / 2);
    gfx_paint();
    getchar();

    rightLeftRotation(&root);
    gfx_clear();
    drawTree(root, g_X_TREE_ORIGIN, g_Y_TREE_ORIGIN, g_SCREEN_WIDTH / 2);
    gfx_paint();
    getchar();
    gfx_clear();
    deleteSearchTree(&root);

    gfx_quit();
    return 0;
}