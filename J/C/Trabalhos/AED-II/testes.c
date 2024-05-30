#include <stdlib.h>
#include <stdio.h>
#include "gfx.h"

const unsigned short g_X_NODE_SIZE = 75;
const unsigned short g_Y_NODE_SIZE = 50;
const unsigned short g_X_SCREEN_SIZE = 800;
const unsigned short g_Y_SCREEN_SIZE = 600;

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

void insertSearchTree(Tree **T, int value)
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
void printSearchTree(Tree *T)
{
    if (T)
    {
        if (T->left)
        {
            printSearchTree(T->left);
        }
        printf("%d ", T->value);
        if(T->right){
            printSearchTree(T->right);
        }
    }
}

int minSearchTree(Tree *T){
    if(T){
        while(T->left){
            T = T->left;
        }
        return T->value;
    }
    return 0; 
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
void drawNode(int valor, int x, int y){
    char v[4];
    x += g_X_NODE;
    y += g_Y_NODE;
    gfx_rectangle(g_X_NODE, g_Y_NODE, g_X_NODE + g_X_NODE_SIZE, g_Y_NODE + g_Y_NODE_SIZE);
    intToString(valor, v);
    gfx_text((g_X_NODE_SIZE)/2 + g_X_NODE, (g_Y_NODE_SIZE)/2 + g_Y_NODE - 5, v);
}

void drawArrow(int x, int y){
    x += g_X_NODE - 35;
    y += g_Y_NODE + g_Y_NODE_SIZE/2;
    gfx_line(x, y, x + 20, y);
    gfx_line(x + 10, y + 10, x + 20, y);
    gfx_line(x + 10, y - 10, x + 20, y);
}

void drawTree(Tree *T){
    gfx_clear();
    int i, j;
    g_X_NODE = g_X_NODE_SIZE;
    g_Y_NODE = g_Y_NODE_SIZE;
    
    gfx_paint();
}

int main()
{
    Tree *root = NULL;
    insertSearchTree(&root, 3);
    insertSearchTree(&root, 1);
    insertSearchTree(&root, 2);
    insertSearchTree(&root, 7);
    insertSearchTree(&root, 5);
    insertSearchTree(&root, 4);
    insertSearchTree(&root, -1);
    printSearchTree(root);
    printf("\n");
    printf("%d", minSearchTree(root));
    printf("\n");
    deleteSearchTree(&root);
    return 0;
}