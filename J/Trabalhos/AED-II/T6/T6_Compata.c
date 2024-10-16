#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned a:1;
    unsigned b:1;
    unsigned c:1;
    unsigned d:1;
    unsigned e:1;
    unsigned f:1;
    unsigned g:1;
    unsigned h:1;
}code;

typedef struct{
    char index;
    char *value;
}table;

char *ordenateSymbols(FILE *);
table *createCodeTable(char *);
FILE *openFile(char[], char[]);
void compactFile(FILE *);
void decompactFile(FILE *);

int main(){


    return 0;
}