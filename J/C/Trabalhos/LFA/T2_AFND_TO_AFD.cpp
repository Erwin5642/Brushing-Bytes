#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct
{
    string label = "";
    bool itsFinal, itsStart, itsValid;
} State;

typedef struct
{
public:
    State from, to;
    char character;
} Transition;

class Automata
{
    vector<State> estados;
    vector<State> estadosIniciais;
    vector<State> estadosFinais;
    vector<char> alfabeto;
    vector<Transition> delta;

public:
    void lerEstados()
    {
        int start, end = -1, cont = 0, n, i;
        string buffer;
        State temp;
        getline(cin, buffer);
        n = buffer.size();
        for (i = 0; i < n; i++)
        {
            if (buffer[i] == ',')
            {
                cont++;
            }
        }
        i = 0;

        do
        {
            start = end + 1;
            end = buffer.find(",", start);
            temp.label = buffer.substr(start, end - start);
            temp.itsFinal = false;
            temp.itsStart = false;
            estados.push_back(temp);
            i++;
        } while (i < cont + 1);
    }

    void lerAlfabeto()
    {
        int n, i;
        string buffer;
        getline(cin, buffer);
        n = buffer.size();
        for (i = 0; i < n; i++)
        {
            if (buffer[i] != ',')
            {
                alfabeto.push_back(buffer[i]);
            }
        }
    }
    void lerFuncaoTransicao()
    {
        int i, j, k, m = estados.size(), n = alfabeto.size();
        string buffer;
        Transition temp;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                temp.from = estados[i];
                cout << "(" << (temp.from.label) << "," << (temp.character = alfabeto[j]) << ") = ";
                getline(cin, buffer);
                for(k = 0; k < m; k++){
                    if(estados[k].label == buffer){
                        temp.to = estados[k];
                    }
                }
                delta.push_back(temp);
            }
        }
    }

    void lerEstadosIniciais()
    {
        int start, end = -1, j, cont = 0, n, i;
        string buffer;
        State temp;
        getline(cin, buffer);
        n = buffer.size();
        for (i = 0; i < n; i++)
        {
            if (buffer[i] == ',')
            {
                cont++;
            }
        }
        i = 0;

        do
        {
            start = end + 1;
            end = buffer.find(",", start);
            temp.label = buffer.substr(start, end - start);
            temp.itsFinal = false;
            temp.itsStart = true;
            estadosIniciais.push_back(temp);
            n = estados.size();

            for (j = 0; j < n; j++)
            {
                if (estados[j].label == estadosIniciais[i].label)
                {
                    estados[j].itsStart = true;
                }
            }
            i++;
        } while (i < cont + 1);
    }
    void lerEstadosFinais()
    {
        int start, end = -1, j, cont = 0, n, i;
        string buffer;
        State temp;
        getline(cin, buffer);
        n = buffer.size();
        for (i = 0; i < n; i++)
        {
            if (buffer[i] == ',')
            {
                cont++;
            }
        }
        i = 0;

        do
        {
            start = end + 1;
            end = buffer.find(",", start);
            temp.label = buffer.substr(start, end - start);
            temp.itsFinal = true;
            temp.itsStart = false;
            estadosFinais.push_back(temp);
            n = estados.size();
            for (j = 0; j < n; j++)
            {
                if (estados[j].label == estadosFinais[i].label)
                {
                    estados[j].itsFinal = true;
                }
            }
            i++;
        } while (i < cont + 1);
    }
};

int main()
{
    Automata afd;
    afd.lerEstados();
    afd.lerEstadosFinais();
    afd.lerEstadosIniciais();
    afd.lerAlfabeto();
    afd.lerFuncaoTransicao();
    return 0;
}