#include <stdlib.h>
#include <stdio.h>
#include "gfx.h"
#include <time.h>
#include <unistd.h>

#define g_NODE_WIDTH 30
#define g_NODE_HEIGHT 30
#define g_SCREEN_WIDTH 1200
#define g_SCREEN_HEIGHT 800
#define g_X_TREE_ORIGIN 600
#define g_Y_TREE_ORIGIN 30
#define g_NODES_DISTANCE 75
typedef struct AVLTree
{
    int key : 30, balance : 2;
    struct AVLTree *left, *right;
} AVLTree;

int rebalanceFromLeft(AVLTree **);
int rebalanceFromRight(AVLTree **);

typedef struct s_no
{

    int32_t chave : 28;

    int32_t bal : 2;

    int32_t reservado : 2; /* sem uso */

    struct s_no *esq;

    struct s_no *dir;

} AVLNodeTree;

typedef struct s_arq_no
{
    int32_t chave : 28;

    int32_t bal : 2;

    uint32_t esq : 1;

    uint32_t dir : 1;

} AVLNodeFile;

void deleteAVLTree(AVLTree **Tree)
{
    if (Tree)
    {
        if (*Tree)
        {
            if ((*Tree)->left)
            {
                deleteAVLTree(&(*Tree)->left);
            }
            if ((*Tree)->right)
            {
                deleteAVLTree(&(*Tree)->right);
            }
            free(*Tree);
            *Tree = NULL;
        }
    }
}

void leftRotation(AVLTree **T)
{
    AVLTree *aux = *T;
    *T = (*T)->right;
    aux->right = (*T)->left;
    (*T)->left = aux;
    aux->balance = 0;
    (*T)->balance = 0;
}

void rightRotation(AVLTree **T)
{
    AVLTree *aux = *T;
    *T = (*T)->left;
    aux->left = (*T)->right;
    (*T)->right = aux;
    aux->balance = 0;
    (*T)->balance = 0;
}

void leftRightRotation(AVLTree **T, int f)
{
    int ptvb = (*T)->left->right->balance, ptub = (*T)->left->balance;
    leftRotation(&(*T)->left);
    rightRotation(T);
    if (ptvb == -1)
    {
        (*T)->right->balance = 1;
    }
    if (ptvb == 1)
    {
        (*T)->left->balance = -1;
    }
    if (f)
    {
        if (ptub == 0)
        {
            (*T)->balance = -1;
            if (ptvb == 1)
            {
                rebalanceFromRight(&(*T)->left);
            }
            else
            {
                (*T)->left->balance = -1;
            }
        }
    }
}

void rightLeftRotation(AVLTree **T, int f)
{
    int ptvb = (*T)->right->left->balance, ptub = (*T)->right->balance;
    rightRotation(&(*T)->right);
    leftRotation(T);
    if (ptvb == 1)
    {
        (*T)->left->balance = -1;
    }
    if (ptvb == -1)
    {
        (*T)->right->balance = 1;
    }
    if (f)
    {
        if (ptub == 0)
        {
            (*T)->balance = 1;
            if (ptvb == -1)
            {
                rebalanceFromLeft(&(*T)->right);
            }
            else
            {
                (*T)->right->balance = 1;
            }
        }
    }
}

int rebalanceFromRight(AVLTree **T)
{
    int flag = 1;
    switch ((*T)->balance)
    {
    case 1:
        (*T)->balance = 0;
        break;
    case 0:
        (*T)->balance = -1;
        flag = 0;
        break;
    case -1:
        if (!(*T)->left->balance)
        {
            flag = 0;
        }
        if ((*T)->left->balance == -1)
        {
            rightRotation(T);
        }
        else
        {
            leftRightRotation(T, 1);
        }
        break;
    }

    return flag;
}

int rebalanceFromLeft(AVLTree **T)
{
    int flag = 1;

    switch ((*T)->balance)
    {
    case -1:
        (*T)->balance = 0;
        break;
    case 0:
        (*T)->balance = 1;
        flag = 0;
        break;
    case 1:
        if (!(*T)->right->balance)
        {
            flag = 0;
        }
        if ((*T)->right->balance == 1)
        {
            leftRotation(T);
        }
        else
        {
            rightLeftRotation(T, 1);
        }
        break;
    }
    return flag;
}

// Retorna um ponteiro para o menor nó na árvore binária de busca
AVLTree *minBinaryTree(AVLTree *T)
{
    if (T)
    {
        // Percorre a árvore até encontrar o nó mais à esquerda
        while (T->left)
        {
            T = T->left;
        }
    }
    return T;
}

AVLTree *newNodeAVLTree(int key)
{
    AVLTree *new = malloc(sizeof(AVLTree));
    new->key = key;
    new->left = new->right = NULL;
    new->balance = 0;
    return new;
}

void insertKeyAVLTree(AVLTree **T, int key)
{
    static int flag;
    flag = 0;
    if (!(*T))
    {
        flag = 1;
        (*T) = newNodeAVLTree(key);
        return;
    }
    if ((*T)->key < key)
    {
        insertKeyAVLTree(&(*T)->right, key);
        if (flag)
        {
            switch ((*T)->balance)
            {
            case -1:
                (*T)->balance = flag = 0;
                break;
            case 0:
                (*T)->balance = 1;
                break;
            case 1:
                if ((*T)->right->balance == 1)
                {
                    leftRotation(T);
                }
                else
                {
                    rightLeftRotation(T, 0);
                }
                flag = 0;
                break;
            }
        }
    }
    else if ((*T)->key > key)
    {
        insertKeyAVLTree(&(*T)->left, key);
        if (flag)
        {
            switch ((*T)->balance)
            {
            case 1:
                (*T)->balance = flag = 0;
                break;
            case 0:
                (*T)->balance = -1;
                break;
            case -1:
                if ((*T)->left->balance == -1)
                {
                    rightRotation(T);
                }
                else
                {
                    leftRightRotation(T, 0);
                }
                flag = 0;
                break;
            }
        }
    }
}

// Remove um nó da árvore a partir de uma chave
// Retorna 1 num sucesso e 0 se houver algum erro
void removeKeyAVLTree(AVLTree **T, int key)
{
    static int flag;
    AVLTree *aux;
    flag = 0;
    if (*T)
    {
        // Procura pelo nó com a chave desejada
        if (key == (*T)->key)
        {
            flag = 1;
            if (!(*T)->left)
            {
                aux = (*T)->right;
                free(*T);
                *T = aux;
            }
            else if (!(*T)->right)
            {
                aux = (*T)->left;
                free(*T);
                *T = aux;
            }
            else
            {
                aux = minBinaryTree((*T)->right);
                (*T)->key = aux->key;
                removeKeyAVLTree(&(*T)->right, aux->key);
                if(flag){
                    flag = rebalanceFromRight(T);
                }
            }
            return;
        }
        if (key < (*T)->key)
        {
            // Se for menor busca na sub arvore esquerda
            removeKeyAVLTree(&(*T)->left, key);
            if (flag)
            {
                flag = rebalanceFromLeft(T);
            }
        }
        else if (key > (*T)->key)
        {
            // Se for maior busca na sub arvore direita
            removeKeyAVLTree(&(*T)->right, key);
            if (flag)
            {
                flag = rebalanceFromRight(T);
            }
        }
    }
}

void drawNode(int x, int y, int key, int balance)
{
    char v[10];
    int largura, altura;
    gfx_set_color(0, 0, 0);
    gfx_filled_rectangle(x + 1, y + 1, x + g_NODE_WIDTH - 1, y + g_NODE_HEIGHT - 1);
    gfx_set_color(255, 255, 255);
    gfx_rectangle(x, y, x + g_NODE_WIDTH, y + g_NODE_HEIGHT);
    // Guarda o valor na string v
    sprintf(v, "%d", key);
    gfx_get_text_size(v, &largura, &altura);
    gfx_text(x + g_NODE_WIDTH / 2 - largura / 2, y + g_NODE_HEIGHT / 2 - altura / 2, v);

    sprintf(v, "%d", balance);
    gfx_get_text_size(v, &largura, &altura);
    gfx_text(x + g_NODE_WIDTH / 2 - largura / 2, y - altura, v);
}

void drawTree(AVLTree *T, int x, int y, int dist)
{
    if (T)
    {
        dist /= 2;
        if (T->left)
        {
            gfx_line(x, y + g_NODE_HEIGHT / 2, x - dist, y + g_NODES_DISTANCE + g_NODE_HEIGHT / 2);
            drawTree(T->left, x - dist, y + g_NODES_DISTANCE, dist);
        }
        if (T->right)
        {
            gfx_line(x, y + g_NODE_HEIGHT / 2, x + dist, y + g_NODES_DISTANCE + g_NODE_HEIGHT / 2);
            drawTree(T->right, x + dist, y + g_NODES_DISTANCE, dist);
        }
        drawNode(x - g_NODE_WIDTH / 2, y, T->key, T->balance);
    }
}

// Operações em Arquivo
FILE *openFile(const char *name, const char *mode)
{
    FILE *file;
    if ((file = fopen(name, mode)) == NULL)
    {
        printf("Não foi possível abrir o arquivo %s\n", name);
    }
    return file;
}

void saveNodesInFile(AVLTree *T, FILE *dest)
{
    struct s_arq_no temp;
    temp.chave = T->key;
    temp.esq = T->left != NULL;
    temp.dir = T->right != NULL;
    fwrite(&temp, sizeof(struct s_arq_no), 1, dest);
    if (T->left)
    {
        saveNodesInFile(T->left, dest);
    }
    if (T->right)
    {
        saveNodesInFile(T->right, dest);
    }
}

void saveSearchTreeInFile(AVLTree *T, const char *fileName)
{
    FILE *treeFIle = openFile(fileName, "wb");
    if (treeFIle)
    {
        if (T)
        {
            saveNodesInFile(T, treeFIle);
        }
        else
        {
            fputc(0, treeFIle);
        }
        fclose(treeFIle);
    }
}

int main()
{
    AVLTree *T = NULL;
    srand(time(NULL));

    gfx_init(g_SCREEN_WIDTH, g_SCREEN_HEIGHT, "Arvore de Busca");

    int i, e;
    for (i = 1; i < 50; i++)
    {
        insertKeyAVLTree(&T, i);
        gfx_clear();
        drawTree(T, g_X_TREE_ORIGIN, g_Y_TREE_ORIGIN, g_SCREEN_WIDTH / 2);
        gfx_paint();
    }

    do
    {
        scanf("%d", &e);
        if (e)
        {
            removeKeyAVLTree(&T, e);
            gfx_clear();
            drawTree(T, g_X_TREE_ORIGIN, g_Y_TREE_ORIGIN, g_SCREEN_WIDTH / 2);
            gfx_paint();
            getchar();
        }
    } while (e);

    deleteAVLTree(&T);
    gfx_quit();
    return 0;
}