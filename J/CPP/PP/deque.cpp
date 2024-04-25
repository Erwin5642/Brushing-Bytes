#include <iostream>
using namespace std;

class CircularDinamicList
{
    int front;
    int back;
    int size;
    int *ptr;

    void resize(const double ratio)
    {
        int *aux = new int[(int)ratio * size];
        int i = front, j = 0;
        while ((i != back))
        {
            aux[j] = ptr[i];
            j++;
            i = (i + 1) % size;
        }
        delete[] ptr;
        ptr = aux;
        front = 0;
        back = j;
        size *= ratio;
    }

public:
    CircularDinamicList()
    {
        size = 2;
        front = 0;
        back = 0;
        ptr = new int[size];
    }
    ~CircularDinamicList()
    {
        delete[] ptr;
    }
    int getFront() const
    {
        return front;
    }
    int getBack() const
    {
        return back;
    }
    int getSize() const
    {
        return size;
    }
    bool isEmpty() const
    {
        return front == back;
    }
    bool isFull() const
    {
        return (back + 1) % size == front;
    }
    void pushFront(const int value)
    {
        if (isFull())
        {
            resize(2);
        }
        front == 0 ? front = (front + size - 1) % size : front = (front - 1) % size;
        ptr[front] = value;
    }
    void pushBack(const int value)
    {
        if (isFull())
        {
            resize(2);
        }
        ptr[back] = value;
        back = (back + 1) % size;
    }
    void popBack()
    {
        if (!isEmpty())
        {
            back == 0 ? back = (back + size - 1) % size : back = (back - 1) % size;
            if ((back + size - front) % size < size / 4)
            {
                resize(0.5);
            }
        }
    }
    void popFront()
    {
        if (!isEmpty())
        {
            front = (front + 1) % size;
            if ((back + size - front) % size < size / 4)
            {
                resize(0.5);
            }
        }
    }
    void imprime() const
    {
        int i;
        for (i = 0; i < size; i++)
        {
            if (i == front)
            {
                cout << "|F->" << ptr[i] << "| ";
            }
            else if (i == back)
            {
                cout << "|B->" << ptr[i] << "| ";
            }
            else
            {
                cout << "|" << ptr[i] << "| ";
            }
        }
        cout << endl;
    }
};

int main()
{
    CircularDinamicList deque;

    deque.pushBack(1);
    deque.imprime();
    deque.pushFront(2);
    deque.imprime();
    deque.pushBack(3);
    deque.imprime();
    deque.pushFront(4);
    deque.imprime();
    deque.popFront();
    deque.imprime();
    deque.popBack();
    deque.imprime();
    deque.popBack();
    deque.imprime();
    return 0;
}
