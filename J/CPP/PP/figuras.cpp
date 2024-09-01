#include <vector>
#include <iostream>
using namespace std;

#define PI 3.1415926535

class Ponto{
    double x,y;
public:
    Ponto(double x = 0.0, double y = 0.0){
        this->x = x;
        this->y = y;
    }
    Ponto(const Ponto& a){
        x = a.x;
        y = a.y;
    }
    double getX() const{
        return x;
    }
    double getY() const{
        return y;
    }
    void setX(double x){
        this->x = x;
    }
    void setY(double y){
        this->y = y;
    }
};

class Figura
{

public:
    virtual double area() const = 0;
};

class App
{

    vector<Figura *> geometrias;

public:
    ~App(){
        vector<Figura *>::iterator it = geometrias.begin();
        double a = 0.0;
        while (it != geometrias.end())
        {
            free(*it);
            it++;
        }
    }
    double areaTotal()
    {
        vector<Figura *>::iterator it = geometrias.begin();
        double a = 0.0;
        while (it != geometrias.end())
        {
            a = (*it)->area();
            it++;
        }
        return a;
    }
    void push(Figura *f)
    {
        geometrias.push_back(f);
    }
};

class Circulo : public Figura
{
    double raio;

public:
    Circulo(double r)
    {
        raio = r;
    }
    double area() const
    {
        return raio * raio * PI;
    }
};

class Triangulo : public Figura
{
    double base, altura;

public:
    Triangulo(double b, double h)
    {
        base = b;
        altura = h;
    }
    double area() const
    {
        return base * altura / 2;
    }
};

class Quadrilatero : public Figura
{
    double base, altura;

public:
    Quadrilatero(double b, double h)
    {
        base = b;
        altura = h;
    }
    double area() const
    {
        return base * altura;
    }
};

int main()
{
    App calculadora;

    calculadora.push(new Quadrilatero(1, 2));
    cout << calculadora.areaTotal() << endl;
    calculadora.push(new Triangulo(2, 4));
    cout << calculadora.areaTotal() << endl;
    calculadora.push(new Circulo(2));
    cout << calculadora.areaTotal() << endl;



    return 0;
}