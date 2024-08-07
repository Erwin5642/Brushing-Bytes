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

int max(int a, int b){
    return a > b ? a : b;
}

int getHeight(AVLTree *node){
    if(!node){
        return 0;
    }
    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

int getBalance(AVLTree *node){
    return getHeight(node->right) - getHeight(node->left);
}

void leftRotation(AVLTree **T){
    AVLTree *aux = *T;
    *T = (*T)->right;
    aux->right = (*T)->left;
    (*T)->left = aux;
    aux->balance = getBalance(aux);
    (*T)->balance = getBalance(*T);
}   

void rightRotation(AVLTree **T){
    AVLTree *aux = *T;
    *T = (*T)->left;
    aux->left = (*T)->right;
    (*T)->right = aux;
    aux->balance = getBalance(aux);
    (*T)->balance = getBalance(*T);
}   

void leftRightRotation(AVLTree **T){
    leftRotation(&(*T)->left);
    rightRotation(T);
}

void rightLeftRotation(AVLTree **T){
    rightRotation(&(*T)->right);
    leftRotation(T);
}

AVLTree *newNodeAVLTree(int key){
    AVLTree *new = malloc(sizeof(AVLTree));
    new->key = key;
    new->left = new->right = NULL;
    new->balance = 0;
    return new;
}

int rebalanceNode(AVLTree **T, int equilibrium){
    int balance = (*T)->balance + equilibrium;
    if(balance > 1){
        if((*T)->right->balance == -1){
            rightLeftRotation(T);
        }
        else{
            leftRotation(T);
        }
    }
    else if(balance < -1){
        if((*T)->left->balance == 1){
            leftRightRotation(T);
        }
        else{
            rightRotation(T);
        }
    }
    else{
        (*T)->balance = balance;
        return 0;
    }
    return 1;
}

int insertAVLTree(AVLTree **T, int key){
    int wasRebalanced;
    if(T){
        if(*T){
            if((*T)->key > key){
                wasRebalanced = insertAVLTree(&(*T)->left, key);
                if(!wasRebalanced){
                    wasRebalanced = rebalanceNode(T, -1);
                }
            }
            else if((*T)->key < key){
                wasRebalanced = insertAVLTree(&(*T)->left, key);
                if(!wasRebalanced){
                    wasRebalanced = rebalanceNode(T, 1);
                }
            }
        }
        else{
            *T = newNodeAVLTree(key);
        }
    }
    return 0;
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
        drawNode(x - g_NODE_WIDTH / 2, y, T->key, getBalance(T));
    }
}

// Operações em Arquivo
struct s_arq_no
{
    int32_t chave : 30;
    uint32_t esq : 1;
    uint32_t dir : 1;
};


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
    AVLTree *root = NULL;
    srand(time(NULL));

    gfx_init(g_SCREEN_WIDTH, g_SCREEN_HEIGHT, "Arvore de Busca");

    int i;
    for(i = 0; i < 10; i++){
        insertAVLTree(&root, rand() % 100 + 1);
        gfx_clear();
        drawTree(root, g_X_TREE_ORIGIN, g_Y_TREE_ORIGIN, g_SCREEN_WIDTH/2);
        gfx_paint();
    }

    deleteAVLTree(&root);
    gfx_quit();
    return 0;
}