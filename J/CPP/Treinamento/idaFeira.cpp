//Problema retirado do beecrowd | 1281
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main(){
    int m, n, p;
    map<string, double> produtos;
    double gasto, preco;
    int qtd;
    string nome;
    scanf("%d", &n);
    while (n)
    {
        gasto = 0;
        scanf("%d", &m);
        while(m){
            cin >> nome;
            cin >> preco;
            produtos.insert(pair<string, double>(nome, preco));
            nome.clear();
            m--;
        }
        scanf("%d", &p);
        while (p)
        {
            cin >> nome;
            cin >> qtd;
            gasto += produtos[nome] * qtd;
            nome.clear();
            p--;
        }
        printf("R$ %.2lf\n", gasto);
        produtos.clear();
        n--;
    }

    return 0;
}
