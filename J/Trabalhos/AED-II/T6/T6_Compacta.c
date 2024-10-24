#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned *nodes;

    size_t n, m;
}Table;

typedef struct Node{
    struct Node *children[2];
    unsigned frequency;
    char character;
}HuffmanTrie;

typedef struct  
{
    struct HuffmanTrie **array;
    size_t n;
}Heap;

unsigned h(char element, int k){
    return 
}

void resizeTable(Table *t){
    int i;
    Table new;
    if(t->nodes){
        new.nodes = calloc(2 * )
        for(i = 0; i < t->m; i++){

        }
    }
}

Table createFrequencyTable(char *text, size_t size){
    Table t;
    t.nodes = calloc(32, sizeof(unsigned));
    t.m = 32;
    t.n = 0;

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