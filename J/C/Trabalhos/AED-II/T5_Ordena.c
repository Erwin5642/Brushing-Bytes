#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int32_t *a, int32_t *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void bubbleSortOriginal(int32_t *vector, size_t n)
{
    size_t i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
            }
        }
    }
}

void bubbleSortImproved(int32_t *vector, size_t n)
{
    size_t i, last = n;
    char flag = 1;

    while (flag)
    {
        flag = 0;
        for (i = 0; i < last - 1; i++)
        {
            if (vector[i] > vector[i + 1])
            {
                swap(&vector[i], &vector[i + 1]);
                flag = 1;
            }
        }
        last = i;
    }
}

void insertionSort(int32_t *vector, size_t n)
{
    size_t i, j;
    for (i = 1; i < n; i++)
    {
        for (j = i - 1; j >= 0 && vector[i] < vector[j]; j--)
        {
            vector[j + 1] = vector[j];
        }
        vector[j + 1] = vector[i];
    }
}

void intercalar(int32_t *vector, size_t n1, size_t n2)
{
    size_t i, j, k;
    int32_t* temp = malloc((n1 + n2) * sizeof(int32_t));
    i = j = k = 0;
    while(i < n1 && j < n2){
        if(vector[i] < vector[j + n1]){
            temp[k] = vector[i];
            i++; 
        }
        else{
            temp[k] = vector[j + n1];
            j++;
        }
        k++;
    }
    for(i = 0; i < n1 + n2; i++){
        vector[i] = temp[i];
    }
}

void mergeSort(int32_t *vector, size_t n)
{
}

void heapSort()
{
}

void quickSortEnd()
{
}

void quickSortRand()
{
}

void quickSortMedian()
{
}

int32_t *readVectorFromFile()
{
}

void saveVectorInFile(int32_t *vector, FILE *FILE)
{
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Entrada do programa inválida!\n");
        return 0;
    }
    if (argv[1] < 1 || argv[1] > 8)
    {
        printf("Opção de algoritmo de ordenação inexistente!\n");
        return 0;
    }

    return 0;
}