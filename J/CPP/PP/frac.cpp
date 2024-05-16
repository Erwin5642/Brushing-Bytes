#include <iostream>

using namespace std;

class Fracao{
    int num, den;

    public:

    Fracao(const int num = 0, const int den = 1) : num(num), den(den){}

    int getNum() const {
        return num;
    }

    int getDen() const {
        return den;
    }

    Fracao operator =(Fracao other){
        den = other.den;
        num = other.num;

        return Fracao(num, den);
    }

    Fracao operator *(Fracao other) const {
        return Fracao(num * other.num, den * other.den);
    }

    Fracao operator +(Fracao other) const {
        return Fracao(other.den * num + den * other.num, other.den * den);
    }

    //Operador pre-fixado
    Fracao operator ++(){
        num += den;
        return Fracao(num, den);
    }

    //Operador pos-fixado
    Fracao operator ++(int){
        num += den;
        return Fracao(num - den, den);
    }

    bool operator ==(Fracao other) const{
        return (den * other.num == num * other.den);
    }

    bool operator !=(Fracao other) const{
        return (den * other.num != num * other.den);
    }
};

int main(){
    Fracao f1(1, 2), f2(2, 1), f3, f4(1, -2);

    cout << f1.getNum() << "/" << f1.getDen() << endl;
    cout << f2.getNum() << "/" << f2.getDen() << endl;

    f3 = f2 * f1;

    cout << f3.getNum() << "/" << f3.getDen() << endl;

    f3 = f2 + f1;

    cout << f3.getNum() << "/" << f3.getDen() << endl;

    ++f3;

    cout << f3.getNum() << "/" << f3.getDen() << endl;

    f3++;

    cout << f3.getNum() << "/" << f3.getDen() << endl;

    f2 = f3++;

    cout << f2.getNum() << "/" << f2.getDen() << endl;
    cout << f3.getNum() << "/" << f3.getDen() << endl;

    return 0;
}
