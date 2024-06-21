#include <vector>
#include <iostream>
using namespace std;

class BigInt{
    vector<short> num;
    public:
    BigInt& operator =(BigInt other){
        vector<short>::iterator itOther = other.num.begin();
        num.clear();
        while (itOther != other.num.end())
        {
            num.push_back(*itOther);
            itOther++;
        }
        return *this;
    }

    BigInt& operator =(int other){
        num.clear();
        short temp;
        if(other == 0){
            num.push_back(0);
        }
        while (other > 0)
        {
            temp = other / 10;
            temp = other - 10 * temp;
            num.push_back(temp);
            other = other/10;
        }
        return *this;
    }

    BigInt operator +(BigInt other){
        BigInt result;
        result.num.clear();
        int itOther = 0, otherEnd = other.num.size(), itThis = 0, thisEnd = num.size(); 
        short carry = 0;
        while((itOther != otherEnd) && (itThis != thisEnd)){
            result.num.push_back((other.num[itOther] + num[itThis] + carry) % 10);
            carry = (other.num[itOther] + num[itThis] + carry)/10;
            itOther++;
            itThis++;
        }
        while(itThis != thisEnd){
            result.num.push_back((num[itThis] + carry) % 10);
            carry = (num[itThis] + carry)/10;
            itThis++;
        }
        
        while(itOther != otherEnd){
            result.num.push_back((other.num[itOther] + carry) % 10);
            carry = (other.num[itOther] + carry)/10;
            itOther++;
        }
        if(carry){
            result.num.push_back(carry);
        }

        return result;
    }

    BigInt operator *(int other){
        BigInt result;
        result = 0;
        while(other){
            result = *this + result;
            other--;
        }
        return result;
    }

    BigInt fatorial(int other){
        BigInt result;
        result = 1;
        while(other){
            result = (result * other);
            other--;
        }
        return result;
    }

    int print(){
        vector<short>::iterator it = num.end();
        int i = 0;
        do{
            it--;
            i++;
            cout << *it;
        }while(it != num.begin());
        cout << endl;
        return i;
    }
};

int main(){
    BigInt a, b, c;
    int i;
    a = a.fatorial(10000); 
    a.print();
  
    return 0;
}
