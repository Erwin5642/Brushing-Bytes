//Problema retirado do livro https://m.media-amazon.com/images/I/81RFK7nbFPL._AC_UF1000,1000_QL80_.jpg
//Tambem encontrado no beecrowd problema 2227
#include <cstdio>
#include <cstring>

int main()
{
    int naero, maior, n, i, j, k, teste = 1;
    while ((scanf("%d %d", &naero, &n)) && !((naero == 0) && (n == 0)))
    {
        maior = -1;
        int voos[naero];
        memset(voos, 0, naero * sizeof(int));

        for (k = 0; k < n; k++)
        {
            scanf("%d %d", &i, &j);
            voos[i - 1] = voos[i - 1] + 1;
            voos[j - 1] = voos[j - 1] + 1;

            if (maior < voos[i - 1])
            {
                maior = voos[i - 1];
            }
            else if (maior < voos[j - 1])
            {
                maior = voos[j - 1];
            }
        }
        printf("Teste %d\n", teste++);
        for (i = 0; i < naero; i++)
        {
            if (maior == voos[i])
            {
                printf("%d ", i + 1);
            }
        }
        printf("\n\n");
    }
    return 0;
}
