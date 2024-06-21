// Nome: João Vitor Antunes da Silva         RGM: 48935

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

int removeValueSearchTree(Tree **T, int value)
{
    Tree *aux;
    if (T)
    {
        while (*T)
        {
            if ((*T)->value == value)
            {
                aux = *T;
                if ((*T)->left && (*T)->right)
                {
                    T = &(*T)->right;
                    while ((*T)->left)
                    {
                        T = &(*T)->left;
                    }
                    aux->value = (*T)->value;
                    value = aux->value;
                }
                else if ((*T)->left)
                {
                    *T = (*T)->left;
                    free(aux);
                    return 1;
                }
                else if ((*T)->right)
                {
                    *T = (*T)->right;
                    free(aux);
                    return 1;
                }
                else
                {
                    free(*T);
                    *T = NULL;
                    return 1;
                }
            }
            else if ((*T)->value > value)
            {
                T = &(*T)->left;
            }
            else if ((*T)->value < value)
            {
                T = &(*T)->right;
            }
        }
    }
    return 0;
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

Tree *sucessorSearchTree(Tree *T, int value)
{
    Tree *ancestralNode = NULL;
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
            return minSearchTree(T->right);
        }
        else
        {
            return ancestralNode;
        }
    }
    return NULL;
}

Tree *predecessorSearchTree(Tree *T, int value)
{
    Tree *ancestralNode = NULL;
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
            return maxSearchTree(T->left);
        }
        else
        {
            return ancestralNode;
        }
    }
    return NULL;
}

// Le apenas o primeiro caracter válido do buffer de teclado e descarta o resto
char readChar()
{
    char c;
    // Enquanto o caracter inserido for inválido, continue lendo do teclado
    while ((c = getchar()) < '0')
        ;
    // Após ler, descarta qualquer outro caracter no buffer de teclado
    while (getchar() != '\n')
        ;
    // Retorna o caracter lido
    return c;
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
void saveNodeInFile(Tree *T, FILE *dest)
{
    struct s_arq_no temp;
    temp.chave = T->value;
    temp.esq = T->left != NULL;
    temp.dir = T->right != NULL;
    fwrite(&temp, sizeof(struct s_arq_no), 1, dest);
    if (T->left)
    {
        saveNodeInFile(T->left, dest);
    }
    if (T->right)
    {
        saveNodeInFile(T->right, dest);
    }
}

void saveSearchTreeInFile(Tree *T, const char *fileName)
{
    FILE *treeFIle = openFile(fileName, "wb");
    if (treeFIle)
    {
        if (T)
        {
            saveNodeInFile(T, treeFIle);
        }
        else{
            fputc(0, treeFIle);
        }
        fclose(treeFIle);
    }
}

void readSearchTreeFromFile(const char *fileName)
{
    FILE *treeFile = openFile(fileName, "rb");
    struct s_arq_no temp;
    if (treeFile != NULL)
    {
        while (fread(&temp, sizeof(struct s_arq_no), 1, treeFile))
        {
            printf("Valor: %d Filho Esquerdo: %d Filho Direito: %d\n", temp.chave, temp.esq, temp.dir);
        }
    }
}

void drawNode(int x, int y, int value)
{
    char v[10];
    int largura, altura;
    gfx_rectangle(x, y, x + g_NODE_WIDTH, y + g_NODE_HEIGHT);
    // Guarda o valor na string v
    sprintf(v, "%d", value);
    gfx_get_text_size(v, &largura, &altura);
    gfx_text(x + g_NODE_WIDTH / 2 - largura / 2, y + g_NODE_HEIGHT / 2 - altura / 2, v);
}

void drawTree(Tree *T, int x, int y, int dist)
{
    if (T)
    {
        dist /= 2;
        if (T->left)
        {
            gfx_line(x - g_NODE_WIDTH / 2, y + 2 * g_NODE_HEIGHT / 3, x - dist + g_NODE_WIDTH / 2, y + g_NODES_DISTANCE + g_NODE_HEIGHT / 3);
            drawTree(T->left, x - dist, y + g_NODES_DISTANCE, dist);
        }
        if (T->right)
        {
            gfx_line(x + g_NODE_WIDTH / 2, y + 2 * g_NODE_HEIGHT / 3, x + dist - g_NODE_WIDTH / 2, y + g_NODES_DISTANCE + g_NODE_HEIGHT / 3);
            drawTree(T->right, x + dist, y + g_NODES_DISTANCE, dist);
        }
        drawNode(x - g_NODE_WIDTH / 2, y, T->value);
    }
}

int main()
{
    Tree *root = NULL, *aux;
    char opcAcao, fileName[20];
    int inputvalue;
    gfx_init(g_SCREEN_WIDTH, g_SCREEN_HEIGHT, "Arvore de Busca");
    do
    {
        system("clear");
        printf("### Arvore Binaria de Busca ###\n[0] - Encerrar programa\
        \n[1] - Buscar Maior e Menor Chave;\
        \n[2] - Buscar Chave;\
        \n[3] - Buscar Antecessor e Sucessor;\
        \n[4] - Inserir Chave;\
        \n[5] - Remover Chave;\
        \n[6] - Ler Arquivo com Arvore;\
        \n[7] - Salvar Arvore em Arquivo;\
        \nDigite uma opção para escolher qual operação deve ser feita: ");
        opcAcao = readChar();
        
        switch (opcAcao)
        {
        case '0':
            gfx_quit();
            deleteSearchTree(&root);
            return 0;
            break;
        case '1':
            if ((aux = maxSearchTree(root)))
            {
                printf("\nA maior chave na árvore é: %d", aux->value);
            }
            if ((aux = minSearchTree(root)))
            {
                printf("\nA menor chave na árvore é: %d\n", aux->value);
            }
            else
            {
                printf("\nA árvore não possui maior e nem menor chave pois está vazia!\n");
            }
            break;
        case '2':
            printf("\nInforme o valor da chave a ser buscada: ");
            scanf("%d", &inputvalue);
            getchar();
            if ((searchValueSearchTree(root, inputvalue)))
            {
                printf("A chave está presente na árvore!\n");
            }
            else
            {
                printf("A chave não está presente na árvore!\n");
            }
            break;
        case '3':
            printf("\nInforme o valor da chave que deve ser encontrado o antecessor e sucessor: ");
            scanf("%d", &inputvalue);
            getchar();
            if(searchValueSearchTree(root, inputvalue)){
                if ((aux = predecessorSearchTree(root, inputvalue)))
                {
                    printf("O antecessor da chave é: %d\n", aux->value);
                }
                else
                {
                    printf("A chave não possui antecessor!\n");
                }
                if ((aux = sucessorSearchTree(root, inputvalue)))
                {
                    printf("O sucessor da chave é: %d\n", aux->value);
                }
                else{
                    printf("A chave não possui sucessor!\n");
                }
            }
            else
            {
                printf("A chave não está presente na árvore!\n");
            }
            break;
        case '4':
            printf("\nInforme o valor da chave que deve ser inserida: ");
            scanf("%d", &inputvalue);
            getchar();
            insertValueSearchTree(&root, inputvalue);
            printf("A chave %d foi inserida com sucesso!\n", inputvalue);
            break;
        case '5':
            printf("\nInforme o valor da chave que deve ser removida: ");
            scanf("%d", &inputvalue);
            getchar();
            if (removeValueSearchTree(&root, inputvalue))
            {
                printf("A chave %d foi removida com sucesso!\n", inputvalue);
            }
            else
            {
                printf("A chave não estava presente na árvore!\n");
            }
            break;
        case '6':
            printf("\nInforme o nome do arquivo em que a árvore está salva: ");
            scanf("%s", fileName);
            getchar();
            readSearchTreeFromFile(fileName);
            break;
        case '7':
            printf("\nInforme o nome do arquivo em que a árvore será salva: ");
            scanf("%s", fileName);
            getchar();
            saveSearchTreeInFile(root, fileName);
            printf("Arquivo salvo com sucesso!\n");
            break;
        default:
            printf("\nOpção inválida! Tente novamente...\n");
            break;
        }
        printf("Pressione Enter para continuar\n");
        gfx_clear();
        drawTree(root, g_X_TREE_ORIGIN, g_Y_TREE_ORIGIN, g_SCREEN_WIDTH/2);
        gfx_paint();
        getchar();
    } while (opcAcao != '0');

    return 0;
}
