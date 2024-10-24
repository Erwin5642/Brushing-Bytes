#include <stdio.h>
#include <time.h>

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

//Faz a descida de um elemento seguindo a estrutura de um heap
void descend(int *vector, int i, int n){
    int j = 2 * i + 1;
    if(j < n){
        if(j < n - 1){
            if(vector[j + 1] > vector[j]){
                j++;
            }
        }
        if(vector[i] < vector[j]){
            swap(&vector[i], &vector[j]);
            descend(vector, j, n);
        }
    }
}

//Organiza um vetor num heap
void arrange(int *vector, int n){
    int i;
    for(i = (n - 1)/2; i >= 0; i--){
        descend(vector, i, n);
    }
}

//Ordena um vetor utilizando o heap sort
void heapSort(int *vector, int n){
    arrange(vector, n);

    while (n - 1 > 0)
    {
        swap(&vector[0], &vector[n - 1]);
        n--;
        descend(vector, 0, n);
    }
    
}

int main(){
    int v[] = {95, 42, 51, 37, 23, 40, 27};
    clock_t t;
    t = clock();    
    heapSort(v, 7);
    t = clock() - t;
    printf("O algoritmo levou %.16lf segundos\n", ((double) t))/CLOCKS_PER_SEC;
    return 0;
}