#include <stdio.h>
#include <stdlib.h>

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

double f(double coeficientes[], unsigned n, double x)
{
    unsigned i;
    double s = 0;
    for (i = 0; i <= n; i++)
    {
        s += coeficientes[i] * pot(x, i);
    }
    return s;
}

void swap(double *a, double *b)
{
    double aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int reduzIntervalo(double coeficientes[], unsigned n, double *a, double *b)
{
    double xn, x, fa, fb, erro = 1, epsilon = 1e-6;
    int invert;
    if ((fa = f(coeficientes, n, *a)) * (fb = f(coeficientes, n, *b)) > 0)
    {
        return 0;
    }
    if ((invert = (fa > fb)))
    {
        swap(a, b);
    }
    x = (*a + *b) / 2;
    if (f(coeficientes, n, x) > 0)
    {
        *b = x;
    }
    else
    {
        *a = x;
    }
    while (erro > epsilon)
    {
        xn = (*a + *b) / 2;
        erro = mod(xn - x);
        x = xn;
        if (f(coeficientes, n, xn) > 0)
        {
            *b = xn;
        }
        else
        {
            *a = xn;
        }
    }

    if (invert)
    {
        swap(a, b);
    }

    return 1;
}

int main()
{
    unsigned n, i, opc;
    double *coeficientes, a, b;
    do
    {
        printf("Insira o grau do polinômio:\n[grau]: ");
        scanf("%u", &n);
        coeficientes = malloc(sizeof(double) * (n + 1));
        printf("Insira cada um dos coeficientes do polinomio:\n");
        for (i = 0; i <= n; i++)
        {
            printf("[C%u]: ", i);
            scanf("%lf", &coeficientes[i]);
        }
        printf("Insira o intervalo inicial:\n[a]: ");
        scanf("%lf", &a);
        printf("[b]: ");
        scanf("%lf", &b);
        if (reduzIntervalo(coeficientes, n, &a, &b))
        {
            printf("%.7lf %.7lf", a, b);
        }
        else
        {
            printf("Intervalo inicial invalido\n");
        }
        free(coeficientes);
        printf("\nDeseja realizar outro calculo?\n[0] - Nao\n[1] - Sim\n-:");
        scanf("%u", &opc);
    } while (opc);

    return 0;
}