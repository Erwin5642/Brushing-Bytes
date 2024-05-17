#include <iostream>

using namespace std;

int mdc(int a, int b)
{
    if (b == 0)
        return a;
    return mdc(b, a % b);
}

int mmc(int a, int b)
{
    return (a / mdc(a, b)) * b;
}

int main()
{
    int buracos, i, j, tempo, m;
    cin >> buracos;

    int B[buracos], tempos[buracos];
    for (i = 0; i < buracos; i++)
    {
        cin >> B[i];
    }

    for(i = 0; i < buracos; i++){
        tempo = 1;
        j = B[i] - 1;
        while(B[j] != B[i]){
            tempo ++;
            j = B[j] - 1;
        }
        tempos[i] = tempo;
    }
    m = 1;
    for(i = 0; i < buracos; i++){
        m = mmc(m, tempos[i]);
    }

    cout << m << endl;

    return 0;
}