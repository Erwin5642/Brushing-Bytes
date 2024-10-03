#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <bits/stdint-intn.h>

void swap(int32_t *a, int32_t *b)
{
    int32_t aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void bubbleSortOriginal(int32_t *vector, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                swap(&vector[j], &vector[j+1]);
            }
        }
    }
}

void bubbleSortImproved(int32_t *vector, int n)
{
    int i, last = n;
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

void insertionSort(int32_t *vector, int n)
{
    int i, j;
    int32_t value;
    for(i = 1; i < n; i++){
        value = vector[i];
        j = i - 1;
        while(j >= 0 && value < vector[j]){
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = value;
    }    

}

void intercalar(int32_t *vector, int n1, int n2)
{
    int i, j, k;
    int32_t *temp = malloc((n1 + n2) * sizeof(int32_t));
    i = j = k = 0;
    while (i < n1 && j < n2)
    {
        if (vector[i] < vector[j + n1])
        {
            temp[k] = vector[i];
            i++;
        }
        else
        {
            temp[k] = vector[j + n1];
            j++;
        }
        k++;
    }
    while(i < n1){
        temp[k] = vector[i];
        i++;
        k++;
    }
    while(j < n2){
        temp[k] = vector[j + n1];
        j++;
        k++;
    }
    for (i = 0; i < n1 + n2; i++)
    {
        vector[i] = temp[i];
    }
    free(temp);
}

void mergeSort(int32_t *vector, int n)
{
    if (n > 1)
    {
        mergeSort(vector, (n + 1) / 2);
        mergeSort(vector + (n + 1) / 2, n / 2);
        intercalar(vector, (n + 1) / 2, n / 2);
    }
}

// void heapSort(int32_t *vector, int n)
// {
// }

void quickSortEnd(int32_t *vector, int n)
{
    int pivot, i, j;
    int32_t pivotValue;
    if(n <= 2){
        if(n == 2){
            if(vector[0] > vector[1]){
                swap(&vector[0], &vector[1]);
            }
        }
        return;
    }           
    pivot = n - 1;
    pivotValue = vector[pivot];
    i = 0;
    j = n - 2;
    while(j >= i){
        while((vector[i] < pivotValue) && (i <= n - 1)){
            i++;
        }
        while((vector[j] > pivotValue) && (j >= 0)){
            j--;
        }
        if(j >= i){
            swap(&vector[i], &vector[j]);
            i++;
            j--;
        }
    }
    swap(&vector[i], &vector[n - 1]);
    quickSortEnd(vector, i);
    quickSortEnd(vector + i, n - i);
}

void quickSortRand(int32_t *vector, int n)
{
    int pivot, i, j;
    int32_t pivotValue;
    if(n <= 2){
        if(n == 2){
            if(vector[0] > vector[1]){
                swap(&vector[0], &vector[1]);
            }
        }
        return;
    }           
    pivot = rand() % n;
    pivotValue = vector[pivot];
    swap(&vector[pivot], &vector[n - 1]);
    i = 0;
    j = n - 2;
    while(j >= i){
        while((vector[i] < pivotValue) && (i <= n - 1)){
            i++;
        }
        while((vector[j] > pivotValue) && (j >= 0)){
            j--;
        }
        if(j >= i){
            swap(&vector[i], &vector[j]);
            i++;
            j--;
        }
    }
    swap(&vector[i], &vector[n - 1]);
    quickSortRand(vector, i);
    quickSortRand(vector + i, n - i);
}

void quickSortMedian(int32_t *vector, int n)
{
    
    int pivot, i, j;
    int32_t pivotValue, iniValue, endValue, medValue;
    if(n <= 2){
        if(n == 2){
            if(vector[0] > vector[1]){
                swap(&vector[0], &vector[1]);
            }
        }
        return;
    }           
    iniValue = vector[0];
    endValue = vector[n - 1];
    medValue = vector[n/2];
    if(((iniValue > medValue) && (iniValue < endValue)) || ((iniValue < medValue) && (iniValue > endValue))){
        pivotValue = iniValue;
        pivot = 0;
    }
    else if(((medValue > iniValue) && (medValue < endValue)) || ((medValue < iniValue) && (medValue > endValue))){
        pivotValue = medValue;
        pivot = n/2;
    }
    else{
        pivotValue = endValue;
        pivot = n - 1;
    }
    swap(&vector[pivot], &vector[n - 1]);
    i = 0;
    j = n - 2;
    while(j >= i){
        while((vector[i] < pivotValue) && (i <= n - 1)){
            i++;
        }
        while((vector[j] > pivotValue) && (j >= 0)){
            j--;
        }
        if(j >= i){
            swap(&vector[i], &vector[j]);
            i++;
            j--;
        }
    }
    swap(&vector[i], &vector[n - 1]);
    quickSortMedian(vector, i);
    quickSortMedian(vector + i, n - i);
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

int32_t *readVectorFromFile(const char *fileName, int *size)
{
    FILE *file = openFile(fileName, "rb");
    int bytes;
    int32_t *vector;
    if(file){
        fseek(file, 0, SEEK_END);
        bytes = ftell(file);
        fseek(file, 0, SEEK_SET);
        vector = malloc(bytes);
        fread(vector, bytes, 1, file);
        fclose(file);
        *size = bytes/4;
        return vector;
    }
    *size = 0;
    return NULL;
}

int saveVectorInFile(int32_t *vector, int n, const char *fileName)
{
    FILE *file = openFile(fileName, "wb");
    if (file)
    {
        fwrite(vector, sizeof(int32_t), n, file);
        fclose(file);
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int opc, size;
    char inputFileName[20], outputFileName[20];
    int32_t *vetor;
    clock_t t;
    if(argc != 4){
        printf("Numero de argumentos invalido!\n");
        return 0;
    }
    opc = atoi(argv[1]);
    if(opc > 8 || opc < 1){
        printf("Opção de ordenação invalida!\n");
        return 0;
    }
    strcpy(inputFileName, argv[2]);
    strcpy(outputFileName, argv[3]);
    if(!(vetor = readVectorFromFile(inputFileName, &size))){
        printf("Houve um erro com o arquivo de entrada!\n");
        return 0;
    }
    t = clock();
    switch (opc)
    {
    case 1:
        bubbleSortOriginal(vetor, size);
        break;
    case 2:
        bubbleSortImproved(vetor, size);
        break;
    case 3:
        insertionSort(vetor, size);
        break;
    case 4:
        mergeSort(vetor, size);
        break;
    case 5:
        quickSortEnd(vetor, size);
        break;
    case 6:
        quickSortRand(vetor, size);
        break;
    case 7:
        quickSortMedian(vetor, size);
        break;
    case 8:
        
        break;
    }
    t = clock() - t;
    printf("Tempo total: %lf segundos\n", ((double)t) / CLOCKS_PER_SEC);
    saveVectorInFile(vetor, size, outputFileName);
    free(vetor);
    return 0;
}