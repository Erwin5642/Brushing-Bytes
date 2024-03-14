//Biblioteca de Álgebra Linear

#include <cmath>
using namespace std;

class fracao
{
private:
    int den;
    int num;
public:

    void simplify(){
        int i;

        for (i = 2; i < sqrt(den > num ? den : num); i++)
        {
            if((den % i == 0) && (num % i ==0)){
                den /= i;
                num /= i;
            }
        }
        
    }

};

