#include <iostream>
#include <vector>
using namespace std;

class Ponto
{
    double x, y;

public:
    Ponto(double x = 0.0, double y = 0.0) : x(x), y(y)
    {
    }
    double getX() const{
        return x;
    }
    double getY() const{
        return y;
    }
};

class Poliedro
{
    vector<Ponto> vertices;

public:
    double area() const
    {
        unsigned short i;
        double a = 0;
        double b, B, h;
        int qtdV = vertices.size();
        for (i = 0; i < qtdV; i++)
        {
            b = vertices[i].getY();
            B = vertices[(i + 1) % qtdV].getY();
            h = vertices[(i + 1)% qtdV].getX() - vertices[i].getX();
            cout << "Ponto: " << vertices[i].getX() << " " << vertices[i].getY() << endl;
            cout << "Ponto: " << vertices[(i + 1) % qtdV].getX() << " " << vertices[(i+1)%qtdV].getY() << endl;
            cout << "b " << b << endl;
            cout << "B " << B << endl;
            cout << "h " << h << endl;
            cout << "a " << (b + B) * h / 2 << endl;
            a += (b + B) * h / 2;
        }
        return abs(a);
    }
    Poliedro& operator=(const Ponto p){
        vertices.push_back(p);
        return *this;
    }
    void clear(){
        vertices.clear();
    }
};

int main()
{
    Poliedro quadrilatero;
    quadrilatero = {0,0};    
    quadrilatero = {1,2};    
    quadrilatero = {3,2};    
    quadrilatero = {5,1};    

    cout << quadrilatero.area() << endl;

    return 0;
}
