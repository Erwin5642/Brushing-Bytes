#include <iostream>
#include <string>
#include <stdio.h>
#include <stack>

using namespace std;

void sDiamond(string input)
{
    stack<int> graos;
    string::iterator it;
    unsigned diamond = 0;
    it=input.begin();
    while(it!=input.end())
    {
        if(*it=='<') {
            graos.push(1);
        } else if(*it=='>') {
            if(!graos.empty()) {
                graos.pop();
                diamond++;
            }
        }
        it++;
    }
    printf("%u\n", diamond);
}
int main()
{
    string input;
    unsigned n;
    cin >> n;
    for(int rep=1; rep<=n; rep++)
    {
        cin >> input;
        sDiamond(input);
    }
    return 0;
}