#include <stdio.h>

#define Pi 3.1415926535

long int fat(long int x){
    long int f = 1;
    while (x > 1)
    {
        f *= x--;
    }
    return f;
}

long double pot(long double x, int n){
    long double ret = 1;
    while(n > 0){
        ret *= x;
        n--;
    }
    return ret;
}

long double coss(long double rad){
    int i;
    long double ret = 0;
    for(i = 0; i < 100; i ++){
        if(i % 2 == 0){
            ret += pot(rad, 2 * i)/fat(2 * i);
        }
        else{
            ret -= pot(rad, 2 * i)/fat(2 * i);
        }
        printf("%Lf\n", ret);
    }    
    return ret;
}

int main(){
    int div, mult;
    scanf("%d %d", &mult, &div);
    printf("%Lf\n", coss(mult * Pi/div));
    return 0;
}