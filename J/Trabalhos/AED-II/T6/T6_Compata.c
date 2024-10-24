#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *pont[2];
    unsigned r;
}HuffmanTrie;

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

//Faz a descida de um elemento seguindo a estrutura de um heap
void descend(HuffmanTrie *nodes, int i, int n){
    int j = 2 * i + 1;
    if(j < n){
        if(j < n - 1){
            if(nodes[j + 1].r > nodes[j].r){
                j++;
            }
        }
        if(nodes[i].r < nodes[j].r){
            swap(&nodes[i].r, &nodes[j].r);
            descend(vector, j, n);
        }
    }
}

//Organiza um vetor num heap
void arrange(, int n){
    int i;
    for(i = (n - 1)/2; i >= 0; i--){
        descend(vector, i, n);
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

//Aloca um vetor e armazena o conteúdo de um arquivo binário nele e retorna um ponteiro para os dados 
//e o tamanho do conjunto
char *readTextFromFile(const char *fileName, int *size)
{
    FILE *file = openFile(fileName, "r");
    int bytes;
    char *text;
    if(file){
        //Calcula o tamanho do arquivo a partir da quantidade de bytes do ínicio ao fim
        fseek(file, 0, SEEK_END);
        bytes = ftell(file);
        fseek(file, 0, SEEK_SET);
        //Aloca um vetor com o número de bytes no vetor
        text = malloc(bytes);
        //Salva todos os bytes no vetor
        fread(text, bytes, 1, file);
        fclose(file);
        //Divide o número de bytes por 4 (32 bits) para obter o tamanho do conjunto
        *size = bytes/sizeof(char);
        return text;
    }
    *size = 0;
    return NULL;
}

//Salva o conteúdo de um vetor em um arquivo binário
int saveTextInFile(char *text, int n, const char *fileName)
{
    FILE *file = openFile(fileName, "w");
    if (file)
    {
        fwrite(text, sizeof(char), n, file);
        fclose(file);
        return 1;
    }
    return 0;
}

int main(){


    return 0;
}