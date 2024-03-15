// Biblioteca de Álgebra Linear
#define NULL (void *)0
class Fraction
{
private:
    int den;
    int num;

public:
    Fraction(int num = 0, int den = 1)
    {
        this->den = den;
        this->num = num;
    }
    int getDen() const
    {
        return den;
    }
    int getNum() const
    {
        return num;
    }
    void setDen(int const den)
    {
        this->den = den;
    }
    void setNum(int const num)
    {
        this->num = num;
    }
    void simplify()
    {
        int i;

        for (i = 2; i < (den > num ? den : num) / 2; i++)
        {
            if ((den % i == 0) && (num % i == 0))
            {
                den /= i;
                num /= i;
                i--;
            }
        }
    }
    Fraction sumFraction(Fraction other) const
    {
        Fraction ret;
        ret.den = den * other.den;
        ret.num = num * other.den + other.num * den;
        ret.simplify();
        return ret;
    }
    Fraction multiplyFraction(Fraction other) const
    {
        Fraction ret;
        ret.den = den * other.den;
        ret.num = num * other.num;
        ret.simplify();
        return ret;
    }
};

class Matrix
{
private:
    int m, n;
    double **p;

public:
    Matrix(int m = 1, int n = 1, double **p = nullptr)
    {
        this->m = m;
        this->n = n;
        this->p = p;
    }
    void setIJMatrix(const double x, const int i, const int j)
    {
        if ((i <= m) && (j <= n))
            p[i][j] = x;
    }
    double getIJMatrix(const int i, const int j) const
    {
        if ((i <= m) && (j <= n))
        {
            return p[i][j];
        }
        return 0;
    }
    int getLines() const
    {
        return n;
    }

    int getCollums() const
    {
        return m;
    }
    Matrix sumMatrix(Matrix other)
    {
        Matrix ret;
        int i, j;
        if ((n == other.getLines()) && m == other.getCollums())
        {
            for (i = 0; i < m; i++)
            {
                for (j = 0; j < n; j++)
                {
                    ret.setIJMatrix(p[i][j] + other.getIJMatrix(i, j), i, j);
                }
            }
            return ret;
        }
    }
};

int main()
{
    return 0;
}
