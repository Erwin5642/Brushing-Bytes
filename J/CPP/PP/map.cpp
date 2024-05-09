#include <iostream>
using namespace std;

#define MAX_MAP_SIZE 10

template <typename K, typename V>
class myMap
{
    K KeysArray[MAX_MAP_SIZE];
    V valuesArray[MAX_MAP_SIZE];
    unsigned nELem;

    bool findFromKey(const K key, unsigned &index) const
    {
        unsigned i;
        for (i = 0; i < nELem; i++)
        {
            if (key == KeysArray[i])
            {
                return true;
            }
        }
        return false;
    }

public:
    myMap() : nElem(0) {}
    bool findFromKey(const K key) const
    {
        unsigned i;
        findFromKey(key, i);
    }

    bool insert(const K key, const V value)
    {
        if ((nElem >= MAX_MAP_SIZE) || (findFromKey(key)))
        {
            return false;
        }

        KeysArray[nELem] = key;
        ValuesArray[nElem] = value;
        nElem++;
        return true;
    }

    bool remove(const K key){
        unsigned i, index;
        if((nElem > 0) || (!findFromKey(key, index))){
            return false;
        }
        nElem--;
        for(i = index; i < nELem; i++){
            KeysArray[i] = KeysArray[i + 1];
            valuesArray[i] = valuesArray[i + 1];
        }

        return true;
    }

    V& at(const K key) const {
       unsigned i;
       if(findFromKey(key, i)){
            return valuesArray[index];
       }
        throw "Mapa erro: chave nao encontrada!";
    }

};

int main()
{

    return 0;
}