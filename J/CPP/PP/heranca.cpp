using namespace std;

class Base
{
private:
    /* data */
public:
    Base(/* args */){

    }
    Base(int i, int j){

    }
    ~Base(){
        
    }
    int& at(unsigned){

    }
};


class Derivada : Base{
    private:

    public:
        Derivada(){

        }
        Derivada(int i, int j){
            Base(i, j);
        }
        ~Derivada(){

        }
        int at(unsigned){

        }

};

int main(){
    Base *pontBase;

    return 0;
} 