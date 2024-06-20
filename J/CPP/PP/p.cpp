#include <iostream>
using namespace std;
#define METROS_POR_MILHAS 1609.34
class DMetro{
    float medida;
public:
    DMetro(float medida = 0.0):
    medida(medida)
    {}
    operator float() const{
        return medida;
    }
};
class DMilhas{
    float medida;
public:
    DMilhas(float medida = 0.0):
            medida(medida)
    {}
    DMilhas(const DMetro &metro){
        medida = (float) metro / METROS_POR_MILHAS;
    }
    operator DMetro(){
        return DMetro(medida * METROS_POR_MILHAS);
    }
};
int main() {
    DMetro me(100.0);
    DMilhas mi;
    mi = me;
    me = mi;
    cout<<me<<endl;
    return 0;
}