/* Problema 1:
Dado um array ordenado verifique se existem dois valores A[i] e A[j] tal que A[i] + A[j] == x.

Solução ótima: 
Levando em consideração que o array está ordenado, é possível atribuir um ponteiro para o fim do array
e outro ponteiro para o ínicio do array. Dessa forma, se o valor de X superar o valor de A[i] + A[j], então 
a soma deve assumir um valor maior. Para assumir um valor maior A[i] ou A[j] deve crescer, mas dado que 
A[j] está no final do array (ordenado de forma crescente), então ele já assume um valor máximo
e portanto A[i] deve ser incrementado. De forma recíproca, se x fosse inferior basta decrementar A[j].
Repetindo o raciocínio indutivamente, ou a soma será encontrada ou A[i] == A[j] e portanto não existiram dois
valores que satisfaçam a soma. 

Complexidade do algoritmo: 
-Tempo O(n)
-Espaço O(1)
*/
//ex:
#include <stdio.h>

void parSomaX(int vetor[], int x){
    int frente = 0, tras = 14, comp;
    while(frente < tras){
        comp = vetor[frente] + vetor[tras];
        if(comp == x){
            printf("%d %d\n", vetor[frente], vetor[tras]);
        }
        if(comp > x){
            tras--;
        } 
        else{
            frente++;
        }
    }
}

int main(){
    int vetor[] = {1, 3, 6, 7, 8, 9, 11, 14, 15, 18, 19, 20, 23, 27, 28}, x = 24;
    parSomaX(vetor, x);
    return 0;
}
