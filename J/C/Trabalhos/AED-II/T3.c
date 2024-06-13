// Nome: João Vitor Antunes da Silva         RGM: 48935

#include <stdlib.h>
#include <stdio.h>
#include "gfx.h"

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

void printSearchTree(Tree *T)
{
    if (T)
    {
        if (T->left)
        {
            printSearchTree(T->left);
        }
        printf("%d ", T->value);
        if (T->right)
        {
            printSearchTree(T->right);
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

int main()
{
    Tree *root = NULL;
    insertValueSearchTree(&root, 2);
    insertValueSearchTree(&root, 1);
    insertValueSearchTree(&root, 6);
    insertValueSearchTree(&root, 4);
    insertValueSearchTree(&root, 3);
    insertValueSearchTree(&root, 5);
    insertValueSearchTree(&root, 8);
    insertValueSearchTree(&root, 7);
    insertValueSearchTree(&root, 9);

    printSearchTree(root);
    printf("\n");
    printf("%d", minSearchTree(root)->value);
    printf("\n");
    //Remover valor fora da arvore
    removeValueSearchTree(&root, 0);
    printSearchTree(root);
    printf("\n");

    //Remover folha
    removeValueSearchTree(&root, 1);
    printSearchTree(root);
    printf("\n");

    //Remover nó com um filho
    removeValueSearchTree(&root, 6);
    printSearchTree(root);
    printf("\n");

    //Remover nó com dois filhos
    removeValueSearchTree(&root, 4);
    printSearchTree(root);
    printf("\n");

    deleteSearchTree(&root);
    return 0;
}
