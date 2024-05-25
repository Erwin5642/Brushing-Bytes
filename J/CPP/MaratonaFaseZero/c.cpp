#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<long long int> a;
    queue<long long int> b;
    long long int n, k, x, i, anta, antb, p;

    cin >> n;
    cin >> k;

    for (i = 0; i < n; i++)
    {
        cin >> x;
        a.push(x);
    }

    for (i = 0; i < n; i++)
    {
        cin >> x;
        b.push(x);
    }

    anta = 0;
    antb = 0;
    p = 0;
    for (i = 0; i < n; i++)
    {
        k -= a.front() - anta;
        if (k < 0)
        {
            if (antb - (a.front() - anta) >= 0)
            {
                k = antb - (a.front() - anta);
                p++;
            }
            else
            {
                p = -1;
                i = n;
            }
        }
        anta = a.front();
        antb = b.front();
        a.pop();
        b.pop();
    }

    cout << p;

    return 0;
}