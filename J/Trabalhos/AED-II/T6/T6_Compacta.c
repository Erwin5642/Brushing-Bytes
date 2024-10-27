#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t Byte;

typedef struct
{
    unsigned long fileInit;
    unsigned uselessBits : 3;
} Header;

int i = sizeof(Header);

typedef struct ListNode
{
    struct ListNode *next;
    Byte character;
} List;

typedef struct HuffmanNode
{
    struct HuffmanNode *children[2];
    unsigned frequency;
    Byte character;
} HuffmanTrie;

typedef struct
{
    unsigned frequency;
    unsigned long long code;
    short unsigned bitsActuallyUsed;
} TableNode;

typedef struct
{
    TableNode *nodes;
    List *characters;
    int n, m;
} Table;

typedef struct
{
    HuffmanTrie **array;
    int n, m;
} Heap;

List *newListNode(Byte character)
{
    List *aux = malloc(sizeof(List));
    aux->next = NULL;
    aux->character = character;
    return aux;
}

void insertList(List **L, Byte newChar)
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

Table createFrequencyTable(Byte *text, int size)
{
    Table newTable;
    int i;
    newTable.nodes = calloc(256, sizeof(TableNode));
    newTable.m = 256;
    newTable.n = 0;
    newTable.characters = NULL;
    for (i = 0; i < size; i++)
    {
        if (newTable.nodes[(unsigned)text[i]].frequency == 0)
        {
            newTable.n++;
            insertList(&newTable.characters, text[i]);
        }
        newTable.nodes[(unsigned)text[i]].frequency++;
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

HuffmanTrie *newTrieNode(Byte newChar, unsigned newFreq)
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
        insertHeap(&newHeap, newTrieNode(auxList->character, table.nodes[auxList->character].frequency));
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

// void showHuffmanTrie(HuffmanTrie *trie)
// {
//     if (trie->children[0])
//     {
//         printf("Freq: %d\n", trie->frequency);
//         showHuffmanTrie(trie->children[0]);
//         showHuffmanTrie(trie->children[1]);
//     }
//     else
//     {
//         printf("Freq: %d Char: %c\n", trie->frequency, trie->character);
//     }
// }

HuffmanTrie *deleteHuffmanTrie(HuffmanTrie *trie)
{
    if (trie)
    {
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
Byte *readTextFromFile(const char *fileName, int *size)
{
    FILE *file = openFile(fileName, "rb");
    int bytes;
    Byte *t;
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
        *size = bytes;
        return t;
    }
    *size = 0;
    return NULL;
}

// Salva o conteúdo de um vetor em um arquivo binário
int saveTextInFile(Byte *text, int size, const char *fileName)
{
    FILE *file = openFile(fileName, "wb");
    if (file)
    {
        fwrite(text, sizeof(Byte), size, file);
        fclose(file);
        return 1;
    }
    return 0;
}

void encodeBytes(HuffmanTrie *codesTrie, Table bytesTable, unsigned long long codesAux, unsigned bitsUsed)
{
    if (codesTrie)
    {
        if (codesTrie->children[0])
        {
            codesAux = codesAux << 1;
            if (bitsUsed)
            {
                bitsUsed++;
            }
            encodeBytes(codesTrie->children[0], bytesTable, codesAux, bitsUsed);
            if (bitsUsed == 1)
            {
                bitsUsed = 1;
            }
            codesAux++;
            encodeBytes(codesTrie->children[1], bytesTable, codesAux, bitsUsed);
        }
        else
        {
            if (bitsUsed == 0)
            {
                bitsUsed = 1;
            }
            bytesTable.nodes[codesTrie->character].bitsActuallyUsed = bitsUsed;
            bytesTable.nodes[codesTrie->character].code = codesAux;
        }
    }
}

// void showCodes(Table bytesTable){
//     List *aux = bytesTable.characters;
//     while(aux){
//         printf("Char: %c Code: %llu\n", aux->character, bytesTable.nodes[aux->character].code);
//         aux = aux->next;
//     }
// }

unsigned long encodeHuffmanTrie(FILE *filePointer, HuffmanTrie *codesTrie, Byte *aux, Byte *used)
{
    Byte temp;
    static unsigned long size = 0;
    if (codesTrie->children[0])
    {
        if (*used == 8)
        {
            fwrite(aux, 1, 1, filePointer);
            size = size + 8;
            *aux = 0;
            *used = 0;
        }
        (*used)++;
        encodeHuffmanTrie(filePointer, codesTrie, aux, used);
        encodeHuffmanTrie(filePointer, codesTrie, aux, used);
    }
    else
    {
        if (*used == 8)
        {
            fwrite(aux, 1, 1, filePointer);
            size = size + 8;
            *used = 0;
        }
        *aux = (*aux) | (1 << (7 - *used));
        (*used)++;
        if (*used == 8)
        {
            fwrite(&codesTrie->character, 1, 1, filePointer);
            size = size + 8;
            *aux = 0;
            *used = 0;
        }
        else
        {
            temp = (codesTrie->character) << (8 - *used);
            *aux = *aux | ((codesTrie->character) >> (8 - *used));
            fwrite(aux, 1, 1, filePointer);
            *aux = temp;
            *used = 8 - *used;
            size = size + 8;
        }
    }
    return size;
}

unsigned long *encodeFile(char *fileName, HuffmanTrie *codesTrie, Table codesTable, char *text, int textSize)
{
    FILE *file = openFile(fileName, "w");
    Byte used = 0, aux = 0, temp;
    Header h;
    TableNode auxNode;
    int i;
    h.fileInit = 0;
    h.uselessBits = 0;
    if (file)
    {
        fwrite(&h, 1, 1, file);
        h.fileInit = encodeHuffmanTrie(file, codesTrie, &aux, &used);
        i = 0;
        if (aux != 0)
        {
            h.fileInit += used;
            auxNode = codesTable.nodes[text[0]];
            temp = (auxNode.code) << (8 - (auxNode.bitsActuallyUsed + used));
            aux = aux | temp;
            fwrite(aux, 1, 1, file);
            aux = temp;
            used = 8 - used;
            i++;
        }

        // while(i < textSize){
            
        //     i++;
        // }

        // if (aux != 0)
        // {
        //     h.fileInit += used;
        //     temp = text[0] << (8 - used);
        //     aux = aux | ((text[0]) >> (8 - used));
        //     fwrite(aux, 1, 1, file);
        //     aux = temp;
        //     used = 8 - used;
        // }

        fseek(file, 0, SEEK_SET);
        fwrite(&h, 1, 1, file);
        fclose(file);
    }
    return 0;
}

void compressFile(char *filename)
{
    int size;
    Byte *text = readTextFromFile(filename, &size);
    Table bytesTable;
    Heap priorityListNodes;
    HuffmanTrie *codesTrie;
    char filenameTemp[80];
    int i = strlen(filename);
    strcpy(filenameTemp, filename);
    filenameTemp[i] = '.';
    filenameTemp[i + 1] = 'c';
    filenameTemp[i + 2] = 'm';
    filenameTemp[i + 3] = 'p';
    filenameTemp[i + 4] = '\0';
    if (text)
    {
        filename = strncat(filename, filenameTemp, 4);
        bytesTable = createFrequencyTable(text, size);
        priorityListNodes = createMinHeap(bytesTable);
        codesTrie = createHuffmanTrie(&priorityListNodes);
        // showHuffmanTrie(codesTrie);
        encodeBytes(codesTrie, bytesTable, 0, 0);
        encodeFile(filenameTemp, codesTrie, bytesTable, text, size);
        // showCodes(bytesTable);
        deleteTable(&bytesTable);
        deleteHeap(&priorityListNodes);
        codesTrie = deleteHuffmanTrie(codesTrie);
        free(text);
    }
}

// int decodeByte(HuffmanTrie codesTrie, Byte *byte)
// {
//     return 0;
// }

// void decompressFile(char *filename)
// {
//     filename[0] = 0;
// }

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