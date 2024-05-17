#include <iostream>

using namespace std;

int binDec(string a){
    string::iterator it = a.begin();
    int num = 0;
    while(*it != '\0'){
        num = *it - '0' + 2 * num;
        it++;
    }
    return num;
}

int mdc(int num1, int num2)
{
    if(num1%num2 == 0)
        return num2;
    else
        return mdc(num2, num1%num2);
}

int main(){
    int testes, teste = 1;
    string s1, s2;

    cin >> testes;

    while (testes)
    {
        cin >> s1;
        cin >> s2;

        cout << "Pair #" << teste << ":";

        if(mdc(binDec(s1), binDec(s2))== 1){
            cout << " Love is not all you need!" << endl;
        }
        else{
            cout << " All you need is love!" << endl;
        }

        testes--;
        teste++;
    }
    
    return 0;
}