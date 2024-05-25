#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int m, n, k, l, i, j;
    cin >> m;
    cin >> n;
    char t[m][n];
    int a, maior = -1, iM, jM;
    cin >> k;
    cin >> l;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> t[i][j];
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            a = 0;
            if (t[i][j] != '*')
            {
                if (j - k + 1 >= 0 && i - l + 1 >= 0)
                {
                    if (t[i - l + 1][j - k + 1] == '*')
                    {
                        a++;
                    }
                }
                if (j + k - 1 < n && i - l + 1 >= 0)
                {

                    if (t[i - l + 1][j + k - 1] == '*')
                    {
                        a++;
                    }
                }
                if (j + k - 1 < n && i + l - 1 < m)
                {

                    if (t[i + l - 1][j + k - 1] == '*')
                    {
                        a++;
                    }
                }
                if (j - k + 1 >= 0 && i + l - 1 < m)
                {

                    if (t[i + l - 1][j - k + 1] == '*')
                    {
                        a++;
                    }
                }
                //
                if (j - l + 1 >= 0 && i - k + 1 >= 0)
                {
                    if (t[i - k + 1][j - l + 1] == '*')
                    {
                        a++;
                    }
                }
                if (j + l - 1 < n && i - k + 1 >= 0)
                {

                    if (t[i - k + 1][j + l - 1] == '*')
                    {
                        a++;
                    }
                }
                if (j + l - 1 < n && i + k - 1 < m)
                {

                    if (t[i + k - 1][j + l - 1] == '*')
                    {
                        a++;
                    }
                }
                if (j - l + 1 >= 0 && i + k - 1 < m)
                {

                    if (t[i + k - 1][j - l + 1] == '*')
                    {
                        a++;
                    }
                }
                if(a > maior){
                    maior = a;
                    iM = i + 1;
                    jM = j + 1;
                    if(maior == 8){
                        i = m;
                        j = n;
                    }
                }
            }
        }
    }

    cout << iM << " " << jM << endl;

    return 0;
}