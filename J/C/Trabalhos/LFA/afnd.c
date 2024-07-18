#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void clear()
{
#ifdef __unix__
    system("clear");
#elif defined(_WIN32) || defined(WIN32)
    system("cls");
#endif
}

// Constantes para teste
const char TRAVOU = '-';
const short NOT_ELEM = -1;

// Constantes de limite para os vetores
const unsigned MAX_INPUT = 30;
const unsigned MAX_SET = 10;

typedef struct{
    char *s;
    unsigned size;
}String;

int main(){
    char funcaoTransicao[MAX_SET][MAX_SET][MAX_SET];    

    

    return 0;
}