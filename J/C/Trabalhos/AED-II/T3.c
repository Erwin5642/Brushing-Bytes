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

// Desaloca todos os nós de uma árvore binária de busca
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

Tree *newNodeSearchTree(int value)
{
    Tree *aux = malloc(sizeof(Tree));
    aux->value = value;
    aux->left = aux->right = NULL;
    return aux;
}

// Insere um valor numa árvore binária de busca
void insertValueSearchTree(Tree **T, int value)
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

// Remove um valor de uma árvore binária de busca
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

// Retorna um ponteiro para o menor nó na árvore binária de busca
Tree *minSearchTree(Tree *T)
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
Tree *maxSearchTree(Tree *T)
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
Tree *searchValueSearchTree(Tree *T, int value)
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
Tree *sucessorNodeSearchTree(Tree *T, int value)
{
    Tree *ancestralNode = NULL;
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
Tree *predecessorNodeSearchTree(Tree *T, int value)
{
    Tree *ancestralNode = NULL;
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

// Le apenas o primeiro caracter válido do buffer de teclado e descarta o resto
char readChar()
{
    char c;
    // Enquanto o caracter inserido for inválido, continue lendo do teclado
    while ((c = getchar()) < '0')
        ;
    // Após ler, descarta qualquer outro caracter no buffer de teclado até o enter
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
void saveNodesInFile(Tree *T, FILE *dest)
{
    struct s_arq_no temp;
    temp.chave = T->value;
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

void saveSearchTreeInFile(Tree *T, const char *fileName)
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

void createNodesFromFile(Tree **T, FILE *dest)
{
    struct s_arq_no temp;
    if (fread(&temp, sizeof(struct s_arq_no), 1, dest))
    {
        (*T) = newNodeSearchTree(temp.chave);
        if (temp.esq)
        {
            createNodesFromFile(&(*T)->left, dest);
        }
        if (temp.dir)
        {
            createNodesFromFile(&(*T)->right, dest);
        }
    }
}

void readSearchTreeFromFile(Tree **T, const char *fileName)
{
    FILE *treeFile = openFile(fileName, "rb");
    if (treeFile)
    {
        if (feof(treeFile))
        {
            (*T) = NULL;
        }
        else
        {
            createNodesFromFile(T, treeFile);
        }
        fclose(treeFile);
    }
}

void drawNode(int x, int y, int value)
{
    char v[10];
    int largura, altura;
    gfx_set_color(255, 100, 255);
    gfx_filled_rectangle(x + 1, y + 1, x + g_NODE_WIDTH - 1, y + g_NODE_HEIGHT - 1);
    gfx_set_color(255, 255, 255);
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
            if (searchValueSearchTree(root, inputvalue))
            {
                if ((aux = predecessorNodeSearchTree(root, inputvalue)))
                {
                    printf("O antecessor da chave é: %d\n", aux->value);
                }
                else
                {
                    printf("A chave não possui antecessor!\n");
                }
                if ((aux = sucessorNodeSearchTree(root, inputvalue)))
                {
                    printf("O sucessor da chave é: %d\n", aux->value);
                }
                else
                {
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
            deleteSearchTree(&root);
            readSearchTreeFromFile(&root, fileName);
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
        drawTree(root, g_X_TREE_ORIGIN, g_Y_TREE_ORIGIN, g_SCREEN_WIDTH / 2);
        gfx_paint();
        getchar();
    } while (opcAcao != '0');

    return 0;
}