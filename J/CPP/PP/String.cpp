#include <cstring>
using namespace std;

class String
{
private:
    char *str;
    unsigned int size;

    void resize(unsigned newSize){
        char *pAux;
        pAux = new char[newSize];
        memcpy(pAux, str, newSize);
        delete [] str;
        str = pAux;
        size = newSize;
    }
public:
    String(const char src[]){
        size = strlen(src);
        this->str = new char[size+1];
        memcpy(str, src, size+1);
    }
    String(){
        str = new char[1]; 
        size = 0;
        str[0] = '\0';
    }
    String(const String &src){
        size = src.size;
        memcpy(str, src.str, size + 1);
    }
    ~String(){
    if(str!= nullptr)
            delete [] str;
    }
    String& operator=(const String src){
        size = src.size;
        memcpy(str, src.str, size + 1);
        return *this;
    }
    String operator+(const String src){
        
    }
};
