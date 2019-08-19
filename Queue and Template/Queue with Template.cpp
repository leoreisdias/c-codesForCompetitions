#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Fila
{
private:
    list<T> fila;
public:
    void inserir(const T& n)
    {
        fila.push_back(n);
    }
    bool vazia()
    {
        return fila.empty();
    }
    double remover()
    {
        if(!this->vazia())
        {
            T e = fila.front();
            fila.pop_front();
            return e;
        }
        throw "Fila Vazia!";
    }
    T frente()
    {
        if(!this->vazia())
        {
            return fila.front();
        }
        throw "Fila Vazia!";
    }
    T final()
    {
        if(!this->vazia())
            return fila.back();
        throw "Fila Vazia!";
    }
    int tamanho()
    {
        return fila.size();
    }
};

template<class T> T soma(T n1, T n2)
{
    return n1 + n2;
}

int main(int argc, char * argv[])
{
    Fila<double> f1;
    cout << "Antes de inserir elementos...\n";

    if(f1.vazia())
        cout << "Fila vazia!\n";
    else
        cout << "Fila não vazia!\n";

    try
    {
        double c = f1.remover();
        cout << "Removido o elemento: " << c << endl;
    }catch(const char* msg)
    {
        cerr << "Erro: " << msg << endl;
    }

    f1.inserir(5.23);
    f1.inserir(10.20);
    f1.inserir(22.30);

    cout << "\nDepois da inserção...\n";

    if(f1.vazia())
        cout << "Fila Vazia\n";
    else
        cout << "Fila nao Vazia\n";

    return 0;
}
