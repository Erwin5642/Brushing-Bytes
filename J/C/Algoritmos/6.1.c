// Exercício 6.1 do livro Estruturas de Dados e seus algoritmos 3ed
// Verificar se uma sequência faz parte de um heap

#include <stdio.h>

int checkHeap(int *arr, int size)
{
    int i;
    for (i = (size) / 2 - 1; i >= 0; i--)
    {
        if ((arr[i] < arr[(i * 2) + 1]))
        {
            return 0;
        }
        if ((i * 2) + 2 < size)
        {
            if (arr[i] < arr[(i * 2) + 2])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int h1[] = {33, 32, 28, 31, 26, 29, 25, 30, 27}, h2[] = {33, 32, 28, 31, 29, 26, 25, 30, 27};

    printf("%d\n", checkHeap(h1, 9));
    printf("%d\n", checkHeap(h2, 9));

    return 0;
}
