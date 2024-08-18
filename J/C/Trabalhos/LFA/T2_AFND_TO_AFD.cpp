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

    bool transicaoIgual(Transition a, Transition b)
    {
        int i, j, m = a.to.size(), n = b.to.size();
        if (a.character != b.character)
        {
            return false;
        }
        if (m != n)
        {
            return false;
        }
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (a.to[i] == b.to[j])
                {
                    j = n + 1;
                }
            }
            if (j == n)
            {
                return false;
            }
        }
        return true;
    }

    bool estadoIgual(State a, State b)
    {
        int i, m = alfabeto.size();
        for (i = 0; i < m; i++)
        {
            if (!transicaoIgual(a.delta[i], b.delta[i]))
            {
                return false;
            }
        }
        return true;
    }

    bool verificaSeTransicaoFoiInserida(vector<Transition> tt, Transition t)
    {
        int i, n = tt.size();
        for (i = 0; i < n; i++)
        {
            if (transicaoIgual(tt[i], t))
            {
                return true;
            }
        }
        return false;
    }

    bool existeElemConjunto(vector<State *> ptss, State *pts)
    {
        int i, n;
        if (ptss.empty())
        {
            return false;
        }

        n = ptss.size();
        for (i = 0; i < n; i++)
        {
            if (ptss[i] == pts)
            {
                return true;
            }
        }
        return false;
    }

    State transicaoParaEstado(Transition x)
    {
        int i, j, k, n, m, y;
        n = x.to.size();
        m = alfabeto.size();
        State ret;
        Transition temp;
        ret.itsStart = false;
        ret.itsFinal = false;
        ret.label = "{";

        for (i = 0; i < n; i++)
        {
            ret.label = ret.label + x.to[i]->label;
            if (x.to[i]->itsFinal)
            {
                ret.itsFinal = true;
            }
            if (i + 1 < n)
            {
                ret.label = ret.label + ",";
            }
        }
        for (j = 0; j < m; j++)
        {
            temp.character = alfabeto[j];
            for (i = 0; i < n; i++)
            {
                y = x.to[i]->delta[j].to.size();
                for (k = 0; k < y; k++)
                {
                    if (!existeElemConjunto(temp.to, x.to[i]->delta[j].to[k]))
                    {
                        temp.to.push_back(x.to[i]->delta[j].to[k]);
                    }
                }
            }
            ret.delta.push_back(temp);
            temp.to.clear();
        }
        ret.label = ret.label + "}";
        return ret;
    }

    bool verificaSeEstadoFoiInserido(vector<State> ss, State s)
    {
        int i, n = ss.size();
        for (i = 0; i < n; i++)
        {
            if (estadoIgual(ss[i], s))
            {
                return true;
            }
        }
        return false;
    }

    Automata converteParaAFD()
    {
        int i, j, k, z, n = alfabeto.size(), l = estadosIniciais.size(), y;
        Automata AFD;
        Transition tempT;
        State tempS;
        tempS.label = "{";
        // Estado Inicial
        tempS.itsStart = true;
        tempS.itsFinal = false;

        for (i = 0; i < l; i++)
        {
            tempS.label = tempS.label + estadosIniciais[i]->label;
            if (i + 1 < l)
            {
                tempS.label = tempS.label + ",";
            }
        }
        tempS.label = tempS.label + "}";
        for (i = 0; i < n; i++)
        {
            tempT.character = alfabeto[i];
            for (j = 0; j < l; j++)
            {
                y = estadosIniciais[j]->delta[i].to.size();
                for (k = 0; k < y; k++)
                {
                    if (!existeElemConjunto(tempT.to, estadosIniciais[j]->delta[i].to[k]))
                    {
                        tempT.to.push_back(estadosIniciais[j]->delta[i].to[k]);
                    }
                }
            }
            tempS.delta.push_back(tempT);
            tempT.to.clear();
        }
        AFD.estados.push_back(tempS);
        AFD.estadosIniciais.push_back(&estados[0]);
    
        j = 0;
        z = 0;
        while(j < (k = AFD.estados.size())){
            for(i = 0; i < n; i++){
                tempS = transicaoParaEstado(AFD.estados[j].delta[i]);
                if(tempS.label != "{}" && !verificaSeEstadoFoiInserido(AFD.estados, tempS)){
                    AFD.estados.push_back(tempS);
                    z++;
                    if(tempS.itsFinal){
                        AFD.estadosFinais.push_back(&estados[z]);
                    }
                }
            }
            j++;
        }
        AFD.alfabeto = alfabeto;
        return AFD;
    }

    void mostrarTabelaTransicao(){
        int i, j, m = estados.size(), n = alfabeto.size();
        State tempS;
        cout << "Tabela de transicao:" << endl;
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                tempS = transicaoParaEstado(estados[i].delta[j]);
                cout << "(" << estados[i].label << "," << alfabeto[j] << ") = " << tempS.label << endl;  
            }
        }
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
    afd.mostrarTabelaTransicao();
    return 0;
}