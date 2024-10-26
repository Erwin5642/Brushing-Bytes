#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    struct ListNode *next;
    char character;
}List;

typedef struct HuffmanNode{
    struct HuffmanNode *children[2];
    unsigned frequency;
    char character;
}HuffmanTrie;

typedef struct{
    unsigned *nodes;
    List *characters;
    size_t n, m;
}Table;

typedef struct  
{
    HuffmanTrie **array;
    size_t n, m;
}Heap;

List *newListNode(char character){
    List *aux = malloc(sizeof(List));
    aux->next = NULL;
    aux->character = character;
    return aux;
}

void insertList(List **L, char newChar){
    List *aux;
    aux = *L;
    *L = newListNode(newChar);
    (*L)->next = aux;
}

// Desaloca os nós da Lista Encadeada Simples
void deleteList(List **L)
{
    List *aux;
    // Garante que o ponteiro apontava para algo
    if (L != NULL)
    {
        // Enquanto não chegar no fim da lista, salva o próximo nó à *L em aux, desaloca *L
        // e reconecta *L com o restante da lista em aux 
        while (*L != NULL)
        {
            aux = (*L)->next;
            free(*L);
            *L = aux;
        }
    }
}

Table createFrequencyTable(char *text, size_t size){
    Table newTable;
    size_t i;
    newTable.nodes = calloc(256, sizeof(unsigned));
    newTable.m = 256;
    newTable.n = 0;
    newTable.characters = NULL;
    for(i = 0; i < size; i++){
        if(newTable.nodes[text[i]] == 0){
            newTable.n++;
            insertList(&newTable.characters, text[i]);
        }
        newTable.nodes[(unsigned)text[i]]++;
    }
    return newTable;
}

// void swapNode(HuffmanTrie **a, HuffmanTrie **b){
//     HuffmanTrie **aux = a;
//     *a = *b;
//     *b = *aux;
// }

// HuffmanTrie *newTrieNode(char newChar, unsigned newFreq){
//     HuffmanTrie *aux = malloc(sizeof(HuffmanTrie));
//     aux->character = newChar;
//     aux->frequency = newFreq;
//     return aux;
// }

// void descendHeap(Heap heap, size_t i){
//     size_t j = 2 * i + 1, n = heap.n;
//     if(j < n){
//         if(j < n - 1){
//             if(heap.array[j + 1]->frequency < heap.array[j]->frequency){
//                 j++;
//             }
//         }
//         if(heap.array[i]->frequency < heap.array[j]->frequency){
//             swapNode(&heap.array[i], &heap.array[j]);
//             descendHeap(heap, i);
//         }
//     }
// }

// void ascendHeap(Heap heap, unsigned index){
//     int j = (index - 1)/2;
//     if(j >= 0){
//         if(heap.array[j]->frequency > heap.array[index]->frequency){
//             swapNode(&heap.array[j], &heap.array[index]);
//             ascendHeap(heap, j);
//         }
//     }
// }

// void insertHeap(Heap* heap, HuffmanTrie *newNode){
//     if(heap->n < heap->m){
//         heap->array[heap->n] = newNode;
//         ascendHeap(*heap, heap->n);
//         heap->n++;
//     }
// }

// HuffmanTrie *removeHeap(Heap *ptheap){
//     HuffmanTrie *aux;
//     if(ptheap->n){
//         aux = ptheap->array[0];
//         ptheap->array[0] = ptheap->array[ptheap->n - 1];
//         ptheap->n--;
//         descendHeap(*ptheap, 0);
//         return aux;
//     }
//     return NULL;
// }

// Heap createMinHeap(Table t){
//     Heap newHeap;
//     size_t i;
//     List *auxList = t.characters;
//     newHeap.array = malloc(t.n * sizeof(HuffmanTrie *));
//     newHeap.m = t.n;
//     newHeap.n = 0;
//     for(i = 0; i < t.n; i++){
//         insertHeap(&newHeap, newTrieNode(t.characters->character, t.nodes[(unsigned)t.characters->character]));
//         auxList = auxList->next;
//     }
//     return newHeap;
// }

// HuffmanTrie *mergeTries(HuffmanTrie *t1, HuffmanTrie *t2){
//     HuffmanTrie *aux = newTrieNode(' ', t1->frequency + t2->frequency);
//     aux->children[0] = t1;
//     aux->children[1] = t2;
//     return aux;    
// }

// HuffmanTrie *createHuffmanTrie(Heap *heap){
//     HuffmanTrie *aux1, *aux2;
//     while (heap->n > 1)
//     {
//         aux1 = removeHeap(heap);
//         aux2 = removeHeap(heap);
//         insertHeap(heap, mergeTries(aux1, aux2));
//     }
//     return heap->array[0];
// }

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
char *readTextFromFile(const char *fileName, size_t *size)
{
    FILE *file = openFile(fileName, "rb");
    size_t bytes;
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
        // Divide o número de bytes por 4 (32 bits) para obter o tamanho do conjunto
        *size = bytes / sizeof(char);
        return t;
    }
    *size = 0;
    return NULL;
}

// Salva o conteúdo de um vetor em um arquivo binário
int saveTextInFile(char *text, size_t size, const char *fileName)
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

void compressFile(char *filename){
    size_t size;
    char *text = readTextFromFile(filename, &size);
    Table frequencias;
    if(text){
        frequencias = createFrequencyTable(text, size);

        free(frequencias.nodes);
        free(text);
    }
}


void decompressFile(char *filename){
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