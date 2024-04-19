//Problema retirado do livro https://m.media-amazon.com/images/I/81RFK7nbFPL._AC_UF1000,1000_QL80_.jpg

#include <cstdio>
#include <cstring>

int main(){
    int naero, maior = 0, n, i, j, k;
    scanf("%d %d", &naero, &n);

    int voos[naero];
    memset(voos, 0, naero);

    for(k = 0; k < n; k++)
    {
        scanf("%d %d", &i, &j);
        voos[i - 1] = voos[i- 1] + 1;
        voos[j - 1] = voos[j - 1] + 1;
    
        if(maior < voos[i - 1]){
            maior = voos[i - 1];
        }
        else if(maior < voos[j - 1]){
            maior = voos[j - 1];
        }
    }
    for(i = 0; i < naero; i++){
        if(maior == voos[i]){
            printf("%d ", i + 1);
        }
    }
    printf("quantidade: %d\n", maior);

    return 0;
}
