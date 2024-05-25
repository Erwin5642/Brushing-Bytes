#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> c;
    vector<string> co;
    vector<string>::iterator it;
    vector<string>::iterator jt;
    vector<string>::iterator kt;
    int i;
    long int n;
    string inp;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> inp;
        c.push_back(inp);
    }

    for (i = 0; i < n; i++)
    {
        cin >> inp;
        co.push_back(inp);
    }

    jt = c.begin();
    it = co.begin();
    for (i = 0; i < n; i++)
    {
        while(*it == ""){
            it++;
        }
        cout << *it;
        if(i != n - 1){
            cout << " ";
        }
        while(*jt != *it){
            it++;
        }
        co.insert(it, "");
        jt++;
    }
    cout << endl;
    
    return 0;
}