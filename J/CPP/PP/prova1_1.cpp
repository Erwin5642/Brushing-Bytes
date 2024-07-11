#include <iostream>
using namespace std;

template <class T>
class NoFila
{
    T key;
    NoFila<T> *next;

public:
    NoFila(T key = 0, NoFila<T> *next = NULL)
    {
        this->key = key;
        this->next = next;
    }
    T& getKey()
    {
        return key;
    }
    NoFila<T>* &getNext()
    {
        return next;
    }
    void setKey(T key)
    {
        this->key = key;
    }
    void setNext(NoFila<T> *next)
    {
        this->next = next;
    }
};

template <class T>
class Fila
{
    NoFila<T> *ptr;

public:
    Fila(NoFila<T> *ptr = NULL) : ptr(ptr)
    {
    }
    ~Fila(){
        NoFila<T> *auxPtr;
        while(ptr != NULL){
            auxPtr = ptr;
            ptr = ptr->getNext();
            delete auxPtr;
        }
    }

    void enqueue(T key)
    {
        NoFila<T> **aux = &ptr;
        while (*aux)
        {
            aux = &(*aux)->getNext();
        }
        (*aux) = new NoFila<T>(key);
    }

    T dequeue()
    {
        T ret = ptr->getKey();
        NoFila<T> *auxPtr = ptr;
        ptr = ptr->getNext();
        delete auxPtr;
        return ret;
    }

    T &operator[](unsigned i)
    {
        NoFila<T> *aux = ptr;
        while (i--)
        {
            aux = aux->getNext();
        }
        return aux->getKey();
    }
};

int main()
{
    Fila<int> fifo;

    fifo.enqueue(3);
    fifo[0] = 1;
    fifo.dequeue();

    return 0;
}
