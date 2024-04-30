#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    string::iterator it;
    int qtd = 0, cont = 0, tam;
    cin >> tam;
    cin >> input;
    it = input.begin();
    while(tam){
        if(*it == 'a'){
            cont++;
            if(cont == 2){
                qtd += 2;
            }
            if(cont > 2){
                qtd++;
            }
        }
        else{
            cont = 0;
        }
        it++;
        tam--;
    }
    cout << qtd << endl;
    return 0;
}