// Arvore
#include <stdlib.h>
#include <stdio.h>

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