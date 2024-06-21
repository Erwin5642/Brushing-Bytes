#include <cmath>
using namespace std;

class Quadratica
{
private:
    double a, b, c;

public:
    Quadratica(double a = 1, double b = 1, double c = 1) : a(a), b(b), c(c)
    {
    }
    void raiz(double &raiz1, double &raiz2) const {
        raiz1 = (-b - sqrt(b*b - 4 * a * c)) / (2 * a);
        raiz2 = (-b + sqrt(b*b - 4 * a * c)) / (2 * a);
    }
    void vertice(double &x, double &y) const {
        x = -b/(2 * a);
        y = -(b * b - 4 * a * c) / (4 * a);
    }
};
