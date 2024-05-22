#include <iostream>

using namespace std;


int main(){
    int num;

    cin >> num;

    while(num > 7){
        cout << num << endl;
        num = 3 * (num/10) + (num - ((num/10) * 10)); 
        if(num / 10 == 0){
            num = num - 7;
        }
    }

    return 0;
}