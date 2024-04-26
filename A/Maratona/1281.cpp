#include <iostream>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, double> prod;
    unsigned n, p, m, quant;
    double preco, total=0.0;
    string nome;

    scanf("%u", &n);
    for(int rep=1; rep<=n; rep++)
    {
        scanf("%u", &m);
        for(int i=1; i<=m; i++)
        {
            cin >> nome;
            cin >> preco;
            prod.insert({nome, preco});
            nome.clear();
        }
        scanf("%u", &p);
        for(int i=1; i<=p; i++)
        {
            cin >> nome;
            cin >> quant;
            total += prod[nome]*quant;
            nome.clear();
        }
        printf("R$ %.2lf\n", total);
        total=0.0;
        prod.clear();
    }
    return 0;
}