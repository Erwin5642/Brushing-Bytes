#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef struct
{
    string label = "";
    bool itsFinal, itsStart;
    vector<struct Transition> delta;
} State;

typedef struct Transition
{
    vector<State *> to;
    char character;
} Transition;

class Automata
{
    vector<State> estados;
    vector<State *> estadosIniciais;
    vector<State *> estadosFinais;
    vector<char> alfabeto;

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
        int i, j, k, m = estados.size(), n = alfabeto.size(), start, end = -1;
        string buffer, find;
        Transition temp;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                temp.to.clear();
                cout << "(" << (estados[i].label) << "," << (temp.character = alfabeto[j]) << ") = ";
                getline(cin, buffer);
                if (buffer[0] != '-')
                {

                    do
                    {
                        start = end + 1;
                        end = buffer.find(",", start);
                        find = buffer.substr(start, end - start);

                        for (k = 0; k < m; k++)
                        {
                            if (estados[k].label == find)
                            {
                                temp.to.push_back(&estados[k]);
                            }
                        }

                    } while (end != -1);
                }
                else
                {
                    temp.to.push_back(NULL);
                }
                estados[i].delta.push_back(temp);
            }
        }
    }

    void lerEstadosIniciais()
    {
        int start, end = -1, j, n;
        string buffer, find;
        getline(cin, buffer);
        n = buffer.size();

        do
        {
            start = end + 1;
            end = buffer.find(",", start);
            find = buffer.substr(start, end - start);
            n = estados.size();

            for (j = 0; j < n; j++)
            {
                if (estados[j].label == find)
                {
                    estadosIniciais.push_back(&estados[j]);
                    estados[j].itsStart = true;
                }
            }

        } while (end != -1);
    }
    void lerEstadosFinais()
    {
        int start, end = -1, j, n;
        string buffer, find;
        getline(cin, buffer);
        n = buffer.size();

        do
        {
            start = end + 1;
            end = buffer.find(",", start);
            find = buffer.substr(start, end - start);
            n = estados.size();

            for (j = 0; j < n; j++)
            {
                if (estados[j].label == find)
                {
                    estadosFinais.push_back(&estados[j]);
                    estados[j].itsFinal = true;
                }
            }
        } while (end != -1);
    }

    bool transicaoIgual(Transition a, Transition b){
        int i, j, m = a.to.size(), n = b.to.size();
        if(a.character != b.character){
            return false;
        }
        if(m != n){
            return false;
        }
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(a.to[i] == b.to[j]){
                    j = n + 1;
                }
            }
            if(j == n){
                return false;
            }
        }
        return true;

    }

    bool estadoIgual(State a, State b){
        int i, j, m = alfabeto.size();
        for(i = 0; i < m; i++){
            if(!transicaoIgual(a.delta[i], b.delta[i])){
                return false;
            }
        }
        return true;
    }

    bool verificaSeEstadoJaFoiInserido(){

    }

    Automata converteParaAFD(){
        int i, j, k, m = estados.size(), n = alfabeto.size(), l = estadosIniciais.size(), y;
        Automata AFD;
        Transition tempT;
        State tempS;
        tempS.label = "";
        //Estado Inicial
        tempS.itsStart = true;
        tempS.itsFinal = false;
        for(i = 0; i < l; i++){
            tempS.label = tempS.label + estadosIniciais[i]->label;
            for(j = 0; j < n; j++){
                tempT.to.clear();
                tempT.character = alfabeto[j];
                y = estadosIniciais[i]->delta[j].to.size();
                for(k = 0; k < y; k++){
                    tempT.to.push_back(estadosIniciais[i]->delta[j].to[k]);
                }
                tempS.delta.push_back(tempT);
            }
            if(i + 1 < l){
                tempS.label = tempS.label + ",";
            }
        }
        AFD.estados.push_back(tempS);

        return AFD; 
    }
};

int main()
{
    Automata afn;
    afn.lerEstados();
    afn.lerEstadosIniciais();
    afn.lerEstadosFinais();
    afn.lerAlfabeto();
    afn.lerFuncaoTransicao();
    Automata afd = afn.converteParaAFD();

    return 0;
}