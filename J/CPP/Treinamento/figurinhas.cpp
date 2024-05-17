#include <iostream>
using namespace std;

int mdc(int a, int b){
    int resto;
    resto = a % b;
    if(resto == 0){
        return b;
    }
    return mdc(b, resto);
}

int main()
{
    int testes, R, V, res;

    cin >> testes;

    while (testes)
    {

        cin >> R;
        cin >> V;

        res = mdc(R, V);

        cout << res << endl;

        testes--;
    }
    return 0;
}