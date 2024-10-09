#include <stdio.h>

double mod(double x)
{
    return x >= 0.0 ? x : -x;
}

double pot(double x, unsigned n)
{
    double s = 1;
    while (n--)
    {
        s *= x;
    }
    return s;
}

double metodoNewtonRaphson(double p, unsigned m)
{
    double erro = 1, xk_1, xk = p / 2;
    int i = 1;
    printf("Iteração 0: %.16lf\n", xk);
    while (erro != 0.0)
    {
        xk_1 = (1.0 / m) * ((m - 1) * xk + (p / (pot(xk, m - 1))));
        erro = mod(xk_1 - xk);
        xk = xk_1;
        if (erro != 0.0)
        {
            printf("Iteração %d: %.16lf\n", i++, xk_1);
        }
    }
    return xk_1;
}

int main()
{
    int opc;
    unsigned m;
    double p;

    do
    {
        printf("Insira o radicando e o indice da raiz para calcular a raiz enesima:\n[Radicando]: ");
        scanf("%lf", &p);
        printf("[Indice]: ");
        scanf("%u", &m);
        metodoNewtonRaphson(p, m);
        printf("\nDeseja realizar outro calculo?\n[0] - Nao\n[1] - Sim\n-:");
        scanf("%d", &opc);
    } while (opc);

    return 0;
}