#include <iostream>

using namespace std;

int main(){
    long long v, e, i, h, min;
    cin >> e;
    cin >> v;
    i = e / v;
    e -= i * v;
    cout << e << endl;
    h = (19 + i) % 24;
    for(i = 0; i * (v / 60) < e; i++);
    min = (i - 1);

    cout << h << " " << min << endl;

    return 0;
}