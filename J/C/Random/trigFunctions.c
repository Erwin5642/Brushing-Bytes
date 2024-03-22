#include <stdio.h>
//Definição da constante pi
#define Pi 3.1415926535

//Calcula o fatorial de um número
long double fatorial(int x){
    long double f = 1;
    //Multiplica f por x e decrementa até chegar em um, calculando o produto entre todos os antecessores de x
    while (x > 1)
    {
        f *= x--;
    }
    return f;
}

//Calcula o resultado de um numero x elevado a enésima potência
long double potenciacao(long double x, int n){
    long double ret = 1;
    //Multiplica x com ele mesmo n vezes
    while(n > 0){
        ret *= x;
        n--;
    }
    return ret;
}

long double cosseno(long double rad){
    int i;
    long double ret = 0;
    //Calcula a série infinita de cosseno com 100 termos
    for(i = 0; i < 100; i ++){
        //Se o termo aparecer em uma posição par soma ele a série
        if(i % 2 == 0){
            ret += potenciacao(rad, 2 * i)/fatorial(2 * i);
        }
        //Se aparecer em posição ímpar subtrai ele
        else{
            ret -= potenciacao(rad, 2 * i)/fatorial(2 * i);
        }
        printf("%Lf\n", ret);
    }    
    return ret;
}

int main(){
    long double div, mult;
    //Lê um número que multiplica pi e outro que divide
    //Para escrever mais facilmente os angulos notáveis
    scanf("%Lf %Lf", &mult, &div);
    printf("%Lf\n", cosseno(mult * Pi/div));
    return 0;
}