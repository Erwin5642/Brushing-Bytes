#include <iostream>
#include <cstdio>

using namespace std;

int mdc(int num1, int num2)
{
    if(num1%num2 == 0)
        return num2;
    else
        return mdc(num2, num1%num2);
}

int main(){
    int x, y, tam;

    while (scanf("%d %d", &x, &y) != EOF)
    {
        tam = mdc(x, y);
        cout << 2 * (x / tam + y / tam) << endl;
    }
    
    return 0;
}