#include <iostream>

using namespace std;

template <typename T> class ArrayTree{
private:
    T* ptr;
    int size;

public:
    ArrayTree(int s){
        ptr = new T[s];
        size = s;
    }
    void print();
};

template <typename T> void ArrayTree<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}