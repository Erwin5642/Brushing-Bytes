#include <cmath>
using namespace std;

class Ponto
{
private:
    double x, y;
public:
    Ponto(double x = 0, double y = 0): x(x), y(y){}
    void setX(const double x){
        this->x = x;
    }
    void setY(const double y){
        this->y = y;
    }
    void transladar(const double vX, const double vY){
        x += vX;
        y += vY;
    }
    double dist(const Ponto other) const{
        return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};