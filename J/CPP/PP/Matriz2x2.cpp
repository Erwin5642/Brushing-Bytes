#include <cmath>
#include <iostream>
using namespace std;

class Matriz2x2
{
private:
    double m[2][2];
public:
    Matriz2x2(const double a11 = 0, const double a12 = 0, const double a21 = 0, const double a22 = 0){
        m[0][0] = a11;
        m[0][1] = a12;
        m[1][0] = a21;
        m[1][1] = a22;
    }
    double det() const{
        return m[0][0] * m[1][1] - m[1][0] * m[0][1];
    }
    Matriz2x2 operator+(const Matriz2x2 other) const {
        Matriz2x2 ret;
        ret.m[0][0] = m[0][0] + other.m[0][0];
        ret.m[0][1] = m[0][1] + other.m[0][1];
        ret.m[1][0] = m[1][0] + other.m[1][0];
        ret.m[1][1] = m[1][1] + other.m[1][1];
        return ret;
    }
    Matriz2x2 operator*(const Matriz2x2 other) const{
        Matriz2x2 ret;
        ret.m[0][0] = m[0][0] * other.m[0][0] + m[0][1] * other.m[1][0];
        ret.m[0][1] = m[0][0] * other.m[0][1] + m[0][1] * other.m[1][1];
        ret.m[1][0] = m[1][0] * other.m[0][0] + m[1][1] * other.m[0][1];
        ret.m[1][1] = m[1][0] * other.m[0][1] + m[1][1] * other.m[1][1];
        return ret;
    }
    Matriz2x2 operator*(const double other) const{
        Matriz2x2 ret;
        ret.m[0][0] = m[0][0] * other;
        ret.m[0][1] = m[0][1] * other;
        ret.m[1][0] = m[1][0] * other;
        ret.m[1][1] = m[1][1] * other;
        return ret;
    }
    Matriz2x2 operator!(){
        Matriz2x2 ret;
        ret.m[0][0] = m[1][1] * (1 / det());
        ret.m[0][1] = -m[0][1] * (1 / det());
        ret.m[1][0] = -m[1][0] * (1 / det());
        ret.m[1][1] = m[0][0] * (1 / det());
        return ret;
    }
};
