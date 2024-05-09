#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

#define MAX_MAP_SIZE 10

template <typename K, typename V>
class myMap
{
    K KeysArray[MAX_MAP_SIZE];
    V ValuesArray[MAX_MAP_SIZE];
    unsigned nElem;

    bool findFromKey(const K key, unsigned &index) const
    {
        unsigned i;
        for (i = 0; i < nElem; i++)
        {
            if (key == KeysArray[i])
            {
                index = i;
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
        return findFromKey(key, i);
    }

    bool insert(const K key, const V value)
    {
        if ((nElem >= MAX_MAP_SIZE) || (findFromKey(key)))
        {
            return false;
        }

        KeysArray[nElem] = key;
        ValuesArray[nElem] = value;
        nElem++;
        return true;
    }

    bool remove(const K key)
    {
        unsigned i, index;
        if ((nElem > 0) || (!findFromKey(key, index)))
        {
            return false;
        }
        nElem--;
        for (i = index; i < nElem; i++)
        {
            KeysArray[i] = KeysArray[i + 1];
            ValuesArray[i] = ValuesArray[i + 1];
        }

        return true;
    }

    V &at(const K key)
    {
        unsigned i;
        if (findFromKey(key, i))
        {
            return ValuesArray[i];
        }
        throw "Mapa erro: chave nao encontrada!";
    }
};

int main()
{
    myMap<string, int> mapa;
    mapa.insert("Paysandu", 10);
    mapa.insert("Corintians", 1);

    cout << mapa.at("Paysandu") << mapa.at("Corintians") << endl;

    return 0;
}