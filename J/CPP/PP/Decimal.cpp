#include <cstring>
using namespace std;

class String
{
private:
    char *str;
    unsigned int size;

    void resize(unsigned newSize)
    {
        char *pAux;
        pAux = new char[newSize + 1];
        if (newSize > size)
        {
            memcpy(pAux, str, size + 1);
        }
        else
        {
            memcpy(pAux, str, newSize + 1);
        }
        delete[] str;
        str = pAux;
        size = newSize;
    }

public:
    String(const char src[])
    {
        size = strlen(src);
        str = new char[size + 1];
        memcpy(str, src, size + 1);
    }
    String()
    {
        str = new char[1];
        size = 0;
        str[0] = '\0';
    }
    String(const String &src)
    {
        size = src.size;
        str = new char[size];
        memcpy(str, src.str, size + 1);
    }
    ~String()
    {
        if (str != nullptr)
            delete[] str;
    }
    String &operator=(const String src)
    {
        if (size != src.size)
        {
            resize(src.size);
        }
        memcpy(str, src.str, size + 1);
        return *this;
    }
    String &operator=(const char src[])
    {
        if (size != strlen(src))
        {
            resize(strlen(src));
        }
        memcpy(str, src, size + 1);
        return *this;
    }
    String &operator=(const char src)
    {
        char src2[2];
        src2[0] = src;
        src2[1] = '\0';
        if (size != 1)
        {
            resize(1);
        }
        memcpy(str, src2, 2);
        return *this;
    }
    String operator+(const String src)
    {
        resize(src.size + size);
        strncat(str, src.str, src.size + 1);
        return *this;
    }
    String operator+(const char src[])
    {
        resize(strlen(src) + size);
        strncat(str, src, strlen(src) + 1);
        return *this;
    }
    String operator+(const char src)
    {
        char src2[2];
        src2[0] = src;
        src2[1] = '\0';
        resize(size + 1);
        strncat(str, src2, 2);
        return *this;
    }
    char &operator[](const unsigned int i)
    {
        if (i < size)
        {
            return str[i];
        }
        else
        {
            return str[size];
        }
    }
    unsigned int getSize() const
    {
        return size;
    }
    bool operator==(const String cmp) const
    {
        return strncmp(str, cmp.str, size) == 0;
    }
    bool isEmpty() const
    {
        return size == 0;
    }
};

class Decimal
{
private:
    int num;

public:
    Decimal(int num = 0) : num(num) {}
    String hexadecimal() const {
        String ret, concat;
        char a;
        int n = num;
        while(n){
            concat = '0' + num % 16;
            ret = concat + ret; 
            concat = '\0';
        }
    }
};