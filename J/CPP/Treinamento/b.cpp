#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, v, h, min, seg, corredor, volta, linha;

    scanf("%d %d", &n, &v);

    unsigned long int total, totalcor, menor = INT32_MAX, matriz[n][v + 2], totais[n];    

    for(int i = 0; i < n; i++){
        scanf("%lu", &matriz[i][0]);
        total = 0;
        for(int j = 1; j < v + 1; j++){
            scanf("%d:%d:%d", &h, &min, &seg);
            matriz[i][j] = seg + min * 1000 + h * 100000;
            if(menor > matriz[i][j]){
                menor = matriz[i][j];
                corredor = matriz[i][0];
                volta = j;
                linha = i;
            }
            if((menor == matriz[i][j]) && (j < volta)){
                corredor = matriz[i][0];
                volta = j;
                linha = i;
            }
            total += matriz[i][j];
        }
        totais[i] = total; 
    }

    totalcor = totais[linha];

    sort(totais, totais + n);
    for(int i = 0; i < 10; i++){
        if(totais[i] == totalcor){
            printf("%d\n", corredor);
            return 0;
        }
    }
    printf("NENHUM\n");

    return 0;
}