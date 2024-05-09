#include <iostream>

using namespace std;

template <typename T> class ArrayTree{
private:
    T* ptr;
    int size;

public:
    ArrayTree(T arr[], int s);
    void print();
};

template <typename T> ArrayTree<T>::ArrayTree(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

template <typename T> void ArrayTree<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}