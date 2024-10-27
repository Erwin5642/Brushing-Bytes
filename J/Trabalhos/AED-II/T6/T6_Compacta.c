#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    struct ListNode *next;
    char character;
} List;

typedef struct HuffmanNode
{
    struct HuffmanNode *children[2];
    unsigned frequency;
    char character;
} HuffmanTrie;

typedef struct
{
    unsigned *nodes;
    List *characters;
    int n, m;
} Table;

typedef struct
{
    HuffmanTrie **array;
    int n, m;
} Heap;

List *newListNode(char character)
{
    List *aux = malloc(sizeof(List));
    aux->next = NULL;
    aux->character = character;
    return aux;
}

void insertList(List **L, char newChar)
{
    List *aux;
    aux = *L;
    *L = newListNode(newChar);
    (*L)->next = aux;
}

// Desaloca os nós da Lista Encadeada Simples
List *deleteList(List *L)
{
    List *aux;
    // Enquanto não chegar no fim da lista, salva o próximo nó à *L em aux, desaloca *L
    // e reconecta *L com o restante da lista em aux
    while (L != NULL)
    {
        aux = (L)->next;
        free(L);
        L = aux;
    }
    return NULL;
}

Table createFrequencyTable(char *text, int size)
{
    Table newTable;
    int i;
    newTable.nodes = calloc(256, sizeof(unsigned));
    newTable.m = 256;
    newTable.n = 0;
    newTable.characters = NULL;
    for (i = 0; i < size; i++)
    {
        if (newTable.nodes[(unsigned)text[i]] == 0)
        {
            newTable.n++;
            insertList(&newTable.characters, text[i]);
        }
        newTable.nodes[(unsigned)text[i]]++;
    }
    return newTable;
}

void deleteTable(Table *table)
{
    free(table->nodes);
    table->nodes = NULL;
    table->characters = deleteList(table->characters);
    table->m = 0;
    table->n = 0;
}

void swapNode(HuffmanTrie **a, HuffmanTrie **b)
{
    HuffmanTrie *aux;
    aux = *b;
    *b = *a;
    *a = aux;
}

HuffmanTrie *newTrieNode(char newChar, unsigned newFreq)
{
    HuffmanTrie *aux = malloc(sizeof(HuffmanTrie));
    aux->character = newChar;
    aux->frequency = newFreq;
    aux->children[0] = aux->children[1] = NULL;
    return aux;
}

void descendHeap(Heap heap, int i)
{
    int j = 2 * i + 1, n = heap.n;
    if (j < n)
    {
        if (j < n - 1)
        {
            if (heap.array[j + 1]->frequency < heap.array[j]->frequency)
            {
                j++;
            }
        }
        if (heap.array[i]->frequency > heap.array[j]->frequency)
        {
            swapNode(&heap.array[i], &heap.array[j]);
            descendHeap(heap, j);
        }
    }
}

void ascendHeap(Heap heap, int index)
{
    int j = (index - 1) / 2;
    if (j >= 0 && index)
    {
        if (heap.array[j]->frequency > heap.array[index]->frequency)
        {
            swapNode(&(heap.array[j]), &(heap.array[index]));
            ascendHeap(heap, j);
        }
    }
}

void insertHeap(Heap *heap, HuffmanTrie *newNode)
{
    if (heap->n < heap->m)
    {
        heap->array[heap->n] = newNode;
        ascendHeap(*heap, heap->n);
        heap->n++;
    }
}

HuffmanTrie *removeHeap(Heap *heap)
{
    HuffmanTrie *aux;
    if (heap->n)
    {
        aux = heap->array[0];
        heap->array[0] = heap->array[heap->n - 1];
        heap->n--;
        descendHeap(*heap, 0);
        return aux;
    }
    return NULL;
}

Heap createMinHeap(Table table)
{
    Heap newHeap;
    List *auxList = table.characters;
    newHeap.array = malloc(table.n * sizeof(HuffmanTrie *));
    newHeap.m = table.n;
    newHeap.n = 0;
    while (auxList)
    {
        insertHeap(&newHeap, newTrieNode(auxList->character, table.nodes[(unsigned)auxList->character]));
        auxList = auxList->next;
    }
    return newHeap;
}

void deleteHeap(Heap *ptheap)
{
    free(ptheap->array);
    ptheap->array = NULL;
    ptheap->n = 0;
    ptheap->m = 0;
}

HuffmanTrie *mergeTries(HuffmanTrie *t1, HuffmanTrie *t2)
{
    HuffmanTrie *aux = newTrieNode('\0', t1->frequency + t2->frequency);
    aux->children[0] = t1;
    aux->children[1] = t2;
    return aux;
}

HuffmanTrie *createHuffmanTrie(Heap *heap)
{
    HuffmanTrie *aux1, *aux2;
    while (heap->n > 1)
    {
        aux1 = removeHeap(heap);
        aux2 = removeHeap(heap);
        insertHeap(heap, mergeTries(aux2, aux1));
    }
    return heap->array[0];
}

void showHuffmanTrie(HuffmanTrie *trie){
    if (trie->children[0])
    {
        printf("Freq: %d\n", trie->frequency);
        showHuffmanTrie(trie->children[0]);
        showHuffmanTrie(trie->children[1]);
    }
    else{
        printf("Freq: %d Char: %c\n", trie->frequency, trie->character);
    }
}

HuffmanTrie *deleteHuffmanTrie(HuffmanTrie *trie)
{
    if(trie){
        if (trie->children[0])
        {
            deleteHuffmanTrie(trie->children[0]);
            deleteHuffmanTrie(trie->children[1]);
        }
        free(trie);
    }
    return NULL;
}

// Operações em Arquivo
// Abre um arquivo
FILE *openFile(const char *name, const char *mode)
{
    FILE *file;
    if ((file = fopen(name, mode)) == NULL)
    {
        printf("Não foi possível abrir o arquivo %s\n", name);
    }
    return file;
}

// Aloca um vetor e armazena o conteúdo de um arquivo binário nele e retorna um ponteiro para os dados
// e o tamanho do conjunto
char *readTextFromFile(const char *fileName, int *size)
{
    FILE *file = openFile(fileName, "rb");
    int bytes;
    char *t;
    if (file)
    {
        // Calcula o tamanho do arquivo a partir da quantidade de bytes do ínicio ao fim
        fseek(file, 0, SEEK_END);
        bytes = ftell(file);
        fseek(file, 0, SEEK_SET);
        // Aloca um vetor com o número de bytes no vetor
        t = malloc(bytes);
        // Salva todos os bytes no vetor
        fread(t, bytes, 1, file);
        fclose(file);
        // Divide o número de bytes pelo tamanho do char para obter o tamanho do conjunto
        *size = bytes / sizeof(char);
        return t;
    }
    *size = 0;
    return NULL;
}

// Salva o conteúdo de um vetor em um arquivo binário
int saveTextInFile(char *text, int size, const char *fileName)
{
    FILE *file = openFile(fileName, "wb");
    if (file)
    {
        fwrite(text, sizeof(char), size, file);
        fclose(file);
        return 1;
    }
    return 0;
}

void compressFile(char *filename)
{
    int size;
    char *text = readTextFromFile(filename, &size);
    Table frequency;
    Heap priorityListNodes;
    HuffmanTrie *codesTrie;
    if (text)
    {
        frequency = createFrequencyTable(text, size);
        priorityListNodes = createMinHeap(frequency);
        codesTrie = createHuffmanTrie(&priorityListNodes);
        showHuffmanTrie(codesTrie);
        deleteTable(&frequency);
        deleteHeap(&priorityListNodes);
        codesTrie = deleteHuffmanTrie(codesTrie);
        free(text);
    }
}

void decompressFile(char *filename)
{
    filename[0] = 1;
}

int main(int argc, char *argv[])
{
    // if (argc != 3)
    // {
    //     printf("Numero de argumentos invalido!\n");
    //     return 0;
    // }
    // if (argv[1][0] != 'd' || argv[1][0] != 'c')
    // {
    //     printf("Operacao invalida!\n");
    //     return 0;
    // }

    // if (argv[1][0] == 'c')
    // {
    //     compressFile(argv[2]);
    //     printf("Arquivo foi compactado!\n");
    // }
    // else
    // {
    //     decompressFile(argv[2]);
    //     printf("Arquivo foi descompactado!\n");
    // }

    compressFile("/home/sofia/Brushing-Bytes/J/Trabalhos/AED-II/T6/teste.txt");

    return 0;
}