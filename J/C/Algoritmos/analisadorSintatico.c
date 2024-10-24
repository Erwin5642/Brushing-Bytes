#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// S -> aSc | Ac  :. S -> a(S | A)c
// A -> cd | aB 
// B -> b | d
//     |
//     v
// S -> aS'c
// S' -> S | A
// A -> cd | aB
// B -> b | d

char buffer[80], lookahead;
int i = 0;

void erro();
void getstring(char *, int);
void S();
void S_();
void A();
void A_();
void reconhecedor(char);

void reconhecedor(char t)
{
    if (lookahead == t)
        lookahead = buffer[i++];
    else
        erro();
}

void erro()
{
    printf("\n Erro Sintatico");
    exit(1);
}

void getstring(char *s, int size)
{
    fgets(s, size, stdin);
    s[strlen(s) - 1] = '\0';
}

int main()
{ // testar para
    printf("\n Cadeia: ");
    getstring(buffer, 80);
    lookahead = buffer[i++];
    S(); // S -> aS'
    if (lookahead == '\0')
        printf("\nAnalise Sintatica completa com sucesso");
    else
        printf("\nEra esperado fim da cadeia");

    getchar();
}

void S()
{
    // S -> aS' first(S)={a}
    reconhecedor('a');
    S_();
}

void S_()
{ // S'-> Sd | Ad  first(S_)={a,b}
    if (lookahead == 'a')
    { 
        S();
    }
    else{
        A();
    }
    reconhecedor('d');
}

void A()
{ // A -> bA' first(A)={b}
    reconhecedor('b');
    A_();
}

void A_()
{ // A'->Ac|c  first(A_)={b,c}
    if(lookahead == 'b')
    {
        A();
    }
    reconhecedor('c');
}