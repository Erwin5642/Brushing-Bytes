#include <cmath>
using namespace std;

class Inteiro
{
private:
    int num;
public:
    Inteiro(int num = 0):num(num)
    {};
    double sqrt() const{
        return std::sqrt(num);
    };
    double pot() const{
        return num * num;
    }
    double soma(Inteiro other){
        return num + other.num;
    }
    operator int(){
        return num;
    }
};

int main(){
    Inteiro i(1), j(3);
    cout << i.sqrt() << endl;
    cout << j.pot() << endl;
    cout << i.soma(j) << endl;
    
    return 0;
}
