#include <stdio.h>
#include <time.h>
#include <unistd.h>

const long double pi = 3.14159265358979;

long double fatorial(long double n)
{
    long double i = 1;
    while (n > 1)
    {
        i *= n--;
    }
    return i;
}

long double potencia(long double x, int n)
{
    long double i = 1;
    while (n--)
    {
        i *= x;
    }
    return i;
}

long double cosseno(long double rad, int nTermos)
{
    long double res = 0, i = 0, h = 1;
    while(rad > 10 * pi){
        rad -= 2 * pi;
    }
    while (nTermos-- > 0)
    {
        res += h * potencia(rad, i) / fatorial(i);
        i += 2;
        h *= -1;
    }
    return res;
}


int main()
{
    long double x, cos, t;
    int n, a, b;
    printf("Insira a razão multilicada por Pi que representa o angulo: ");
    scanf("%d/%d", &a, &b);
    x = a * pi / b;

    printf("Insira o numero de termos utilizado pela função cosseno\n");
    scanf("%d", &n);
    clock_t temp;
    temp = clock();
    cos = cosseno(x, n);
    temp = clock() - temp;
    t = ((long double)temp) / CLOCKS_PER_SEC;
    
    printf("Cosseno de %Lf eh: %Lf.\n\n O algoritmo levou %Lf segundos\n", x, cos, t);
    return 0;
}