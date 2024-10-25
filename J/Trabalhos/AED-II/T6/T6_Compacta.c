#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    struct ListNode *next;
    char character;
}List;

typedef struct{
    unsigned *nodes;
    List *characters;
    size_t n, m;
}Table;

typedef struct TrieNode{
    struct TrieNode *children[2];
    unsigned frequency;
    unsigned short isLeaf;
    char character;
}HuffmanTrie;

typedef struct  
{
    struct HuffmanTrie **array;
    size_t n, m;
}Heap;

void swapNode(HuffmanTrie **a, HuffmanTrie **b){
    HuffmanTrie **aux = a;
    *a = *b;
    *b = *aux;
}

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
        if(newTable.nodes[text[i] == 0]){
            newTable.n++;
            insertList(&newTable.characters, text[i]);
        }
        newTable.nodes[text[i]]++;
    }
    return newTable;
}

void descendHeap(Heap h, size_t i){
    size_t j = 2 * i + 1, n = h.n;
    HuffmanTrie **vector = h.array;
    if(j < n){
        if(j < n - 1){
            if(vector[j + 1]->frequency < vector[j]->frequency){
                j++;
            }
        }
        if(vector[i]->frequency < vector[j]->frequency){
            swapNode(&vector[i], &vector[j]);
            descendHeap(h, i);
        }
    }
}

void arrangeHeap(Heap h){
    size_t i;
    for(i = (h.n - 1)/2; i >= 0; i--){
        descendHeap(h, i);
    }
}

void insertHeap(Heap* h, HuffmanTrie *newNode){

}

HuffmanTrie *removeHeap(Heap *h){
    HuffmanTrie *aux = h->array[0];
    
}

Heap createMinHeap(Table t){
    Heap newHeap;
    size_t i;
    List *auxList = t.characters;
    newHeap.array = malloc(t.n * sizeof(HuffmanTrie *));
    for(i = 0; i < t.n; i++){
        newHeap.array[i] = newTrieNode(auxList->character, t.nodes[auxList->character], 1);
        auxList = auxList->next;
    }
    arrangeHeap(newHeap);
    return newHeap;
}

HuffmanTrie *newTrieNode(char newChar, unsigned newFreq, unsigned short pos){
    HuffmanTrie *aux = malloc(sizeof(HuffmanTrie));
    if((aux->isLeaf = pos)){
        aux->character = newChar;
    }
    aux->frequency = newFreq;
    return aux;
}

HuffmanTrie *mergeTries(HuffmanTrie *t1, HuffmanTrie *t2){
    HuffmanTrie *aux = newTrieNode(' ', t1->frequency + t2->frequency, 0);
    aux->children[0] = t1;
    aux->children[1] = t2;
    return aux;    
}

void createHuffmanTrie(Heap *freq){
    while (freq->n > 1)
    {

    }
    
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

void compactFile(char *filename){
    size_t size;
    char *text = readTextFromFile(filename, &size);
    Table frequencias;
    if(text){
        frequencias = createFrequencyTable(text, size);
        
        free(frequencias.nodes);
    }
}


void decompactFile(char *filename){

}


int main(int argc, char *argv[])
{
    char *text;
    int size;
    if (argc != 3)
    {
        printf("Numero de argumentos invalido!\n");
        return 0;
    }
    if (argv[1][0] != 'd' || argv[1][0] != 'c')
    {
        printf("Operacao invalida!\n");
        return 0;
    }

    if (argv[1][0] == 'c')
    {
        compactFile(argv[2]);
        printf("Arquivo foi compactado!\n");
    }
    else
    {
        decompactFile(argv[2]);
        printf("Arquivo foi descompactado!\n");
    }

    return 0;
}