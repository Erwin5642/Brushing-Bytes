#include <iostream>
using namespace std;
const double METROS_POR_MILHAS = 1609.34;

class Metros
{
    double medida;
public:
    Metros(double medida = 0.0) : medida(medida)
    {
    }
    operator double() const {
        return medida;
    }
};

class Milhas
{
    double medida;

public:
    Milhas(double medida = 0.0) : medida(medida)
    {
    }
    Milhas(const Metros &metro){
        medida = (double) metro / METROS_POR_MILHAS;
    }
    operator Metros(){
        return Metros(medida * METROS_POR_MILHAS);
    }
    operator double() const {
        return medida;
    }

    
};

int main()
{
    Metros metro;
    Milhas milha(10);
    metro = milha;
    milha = metro;
    cout << milha << endl;
    cout << metro << endl;
    return 0;
}
