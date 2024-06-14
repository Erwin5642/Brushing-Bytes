// Nome: João Vitor Antunes da Silva         RGM: 48935

#include <stdlib.h>
#include <stdio.h>
//#include "gfx.h"
#include <time.h>

#define g_NODE_WIDTH 30
#define g_NODE_HEIGHT 30
#define g_SCREEN_WIDTH 1200
#define g_SCREEN_HEIGHT 800
#define g_X_LIST_ORIGIN 600
#define g_Y_LIST_ORIGIN 30
#define g_NODES_DISTANCE 50

typedef struct Tree
{
    int value;
    struct Tree *left;
    struct Tree *right;
} Tree;

void deleteSearchTree(Tree **T)
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

Tree *minSearchTree(Tree *T)
{
    if (T)
    {
        while (T->left)
        {
            T = T->left;
        }
        return T;
    }
    return NULL;
}

Tree *maxSearchTree(Tree *T)
{
    if (T)
    {
        while (T->right)
        {
            T = T->right;
        }
        return T;
    }
    return NULL;
}

void insertValueSearchTree(Tree **T, int value)
{
    Tree *aux;
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
        aux = malloc(sizeof(Tree));
        aux->value = value;
        aux->left = NULL;
        aux->right = NULL;
        (*T) = aux;
    }
}

void removeValueSearchTree(Tree **T, int value)
{
    Tree *aux;
    if(T){
        while(*T){
            if((*T)->value == value){
                aux = *T;
                if((*T)->left && (*T)->right){
                    T = &(*T)->right;
                    while((*T)->left){
                        T = &(*T)->left;
                    }
                    aux->value = (*T)->value;
                    value = aux->value;
                }
                else if((*T)->left){
                    *T = (*T)->left;
                    free(aux);
                    return;
                }
                else if((*T)->right){
                    *T = (*T)->right;
                    free(aux);
                    return;                    
                }
                else{
                    free(*T);
                    *T = NULL;
                    return;
                }
            }
            else if ((*T)->value > value)
            {
                T = &(*T)->left;
            }
            else if((*T)->value < value)
            {
                T = &(*T)->right;
            }
        }
    }
}

Tree *searchValueSearchTree(Tree *T, int value)
{
    while (T)
    {
        if (T->value == value)
        {
            return T;
        }
        if (T->left && T->left->value == value)
        {
            return T->left;
        }
        if (T->value > value)
        {
            T = T->left;
        }
        if (T->right && T->right->value == value)
        {
            return T->right;
        }
        if (T->value < value)
        {
            T = T->right;
        }
    }
    return NULL;
}

Tree *sucessorSearchTree(Tree *T, int value){
    Tree *daddyNode = NULL;
    while (T)
    {
        if(T->value < value){
            T = T->right;
        }
        else if(T->value > value){
            daddyNode = T;
            T = T->left;
        }
        else if(T->right){
            return minSearchTree(T->right);
        }
        else{
            return daddyNode;
        }
    }
    return NULL;
}

/*
void drawNode(int x, int y, int value)
{
    char v[10];
    int largura, altura;
    gfx_rectangle(x, y, x + g_NODE_WIDTH, y + g_NODE_HEIGHT);
    //Guarda o valor na string v
    sprintf(v, "%d", value);
    gfx_get_text_size(v, &largura, &altura);
    gfx_text(x + g_NODE_WIDTH/2 - largura/2, y + g_NODE_HEIGHT/2 - altura/2, v);
}

void drawTree(Tree *T, int x, int y, int dist){
    if(T){
        dist /= 2;
        if(T->left){
            gfx_line(x - g_NODE_WIDTH/2, y + 2*g_NODE_HEIGHT/3, x - dist + g_NODE_WIDTH/2, y + g_NODES_DISTANCE + g_NODE_HEIGHT/3);
            drawTree(T->left, x - dist, y + g_NODES_DISTANCE, dist);
        }
        if(T->right){
            gfx_line(x + g_NODE_WIDTH/2, y + 2*g_NODE_HEIGHT/3, x + dist - g_NODE_WIDTH/2, y + g_NODES_DISTANCE + g_NODE_HEIGHT/3);
            drawTree(T->right, x + dist, y + g_NODES_DISTANCE, dist);
        }
        drawNode(x - g_NODE_WIDTH/2, y, T->value);
    }
}
*/
int main()
{
    Tree *root = NULL, *teste;
    //gfx_init(g_SCREEN_WIDTH, g_SCREEN_HEIGHT, "Arvore de Busca");

    insertValueSearchTree(&root, 15);
    insertValueSearchTree(&root, 18);
    insertValueSearchTree(&root, 17);
    insertValueSearchTree(&root, 20);
    insertValueSearchTree(&root, 6);
    insertValueSearchTree(&root, 3);
    insertValueSearchTree(&root, 2);
    insertValueSearchTree(&root, 4);
    insertValueSearchTree(&root, 7);
    insertValueSearchTree(&root, 13);
    insertValueSearchTree(&root, 9);

    if((teste = sucessorSearchTree(root, 15)) == NULL){
        printf("0\n");
    }
    else{
        printf("15 %d\n", teste->value);
    }
    if((teste = sucessorSearchTree(root, 6)) == NULL){
        printf("0\n");
    }
    else{
        printf("6 %d\n", teste->value);
    }if((teste = sucessorSearchTree(root, 3)) == NULL){
        printf("0\n");
    }
    else{
        printf("3 %d\n", teste->value);
    }if((teste = sucessorSearchTree(root, 2)) == NULL){
        printf("0\n");
    }
    else{
        printf("2 %d\n", teste->value);
    }if((teste = sucessorSearchTree(root, 4)) == NULL){
        printf("0\n");
    }
    else{
        printf("4 %d\n", teste->value);
    }if((teste = sucessorSearchTree(root, 7)) == NULL){
        printf("0\n");
    }
    else{
        printf("7 %d\n", teste->value);
    }if((teste = sucessorSearchTree(root, 13)) == NULL){
        printf("0\n");
    }
    else{
        printf("13 %d\n", teste->value);
    }if((teste = sucessorSearchTree(root, 9)) == NULL){
        printf("0\n");
    }
    else{
        printf("9 %d\n", teste->value);
    }if((teste = sucessorSearchTree(root, 18)) == NULL){
        printf("0\n");
    }
    else{
        printf("18 %d\n", teste->value);
    }if((teste = sucessorSearchTree(root, 17)) == NULL){
        printf("0\n");
    }
    else{
        printf("17 %d\n", teste->value);
    }if((teste = sucessorSearchTree(root, 20)) == NULL){
        printf("20 0\n");
    }
    else{
        printf("20 %d\n", teste->value);
    }if((teste = sucessorSearchTree(root, 21)) == NULL){
        printf("21 0\n");
    }
    else{
        printf("21 %d\n", teste->value);
    }
    if((teste = sucessorSearchTree(root, 0)) == NULL){
        printf("0 0\n");
    }
    else{
        printf("0 %d\n", teste->value);
    }
    //drawTree(root, g_X_LIST_ORIGIN, g_Y_LIST_ORIGIN, g_SCREEN_WIDTH/2);
    //gfx_paint();
    //getchar();
   
    //gfx_clear();
    //drawTree(root, g_X_LIST_ORIGIN, g_Y_LIST_ORIGIN, g_SCREEN_WIDTH/2);
    //gfx_paint();
    //getchar();
    
    
    //gfx_quit();
    deleteSearchTree(&root);
    return 0;
}
