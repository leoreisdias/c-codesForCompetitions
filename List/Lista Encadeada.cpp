#include<bits/stdc++.h>
using namespace std;

template<class Type>
class No
{
private:
    Type v;
    No* prox;
public:
    No<Type>(Type v)
    {
        this->v = v;
        this->prox = NULL;
    }
    Type getValor()
    {
        return v;
    }

    No* getProx()
    {
        return prox;
    }

    void setProx(No* p)
    {
        prox = p;
    }
};
template<class Type>
class Lista
{
private:
    No<Type>* cabeca;
    No<Type>* cauda;
public:
    Lista<Type>()
    {
        cabeca = NULL;
        cauda = NULL;
    }
    Lista<Type>(Type v)
    {
        cabeca = new No<Type>(v);
        cauda = cabeca;
    }
    virtual ~Lista<Type>()
    {
        delete cabeca;
    }

    bool vazia()
    {
        return cabeca == NULL;
    }

    void mostrar()
    {
        cout << "\nTodos elementos: \n";
        No<Type>* c = cabeca;
        if(vazia())
            cout << "Lista Vazia!\n";
        else{
            while(c){
                cout << c->getValor() << endl;
                c=c->getProx();
            }
            cout << endl;
        }
    }

    void inserir_inicio(Type v)
    {
        No<Type>* novo_no = new No<Type>(v);
        novo_no->setProx(cabeca);
        cabeca = novo_no;
    }

    void inserir_final(Type v)
    {
        No<Type>* novo_no = new No<Type>(v);

        if(vazia())
        {
            cabeca = novo_no;
            cauda = novo_no;
        }
        else
        {
            cauda->setProx(novo_no);
            cauda = novo_no;
        }
    }

    int tamanho()
    {
        if(vazia()) return 0;

        No<Type>* c=cabeca;
        int tam=0;
        do
        {
            c=c->getProx();
            tam++;
        }while(c);

        return tam;
    }

    bool existe(int v)
    {
        No<Type>* c = cabeca;
        while(c)
        {
            if(c->getValor() == v)
                return true;
            c = c->getProx();
        }
        return false;
    }

    void remover()
    {
        if(!vazia())
        {
            if(cabeca->getProx() == NULL)
                cabeca = NULL;
            else if(cabeca->getProx()->getProx() == NULL)
                cabeca->setProx(NULL);
            else
            {
                No<Type>* ant_ant = cabeca;
                No<Type>* ant = cabeca->getProx();
                No<Type>* corrente = cabeca->getProx()->getProx();
                while(corrente)
                {
                    No<Type>* aux = ant;
                    ant = corrente;
                    ant_ant = aux;
                    corrente=corrente->getProx();
                }
                delete ant_ant->getProx();
                cauda = ant_ant;
                ant_ant->setProx(NULL);
            }
        }
    }
};

int main(int argc, char * argv[])
{
    Lista<double> l;

    if(l.vazia())
        cout << "Lista vazia!\n";
    else
        cout << "Lista Nao Vazia!\n";

    l.mostrar();
    if(l.existe(10.0))
        cout << "O elemento existe na lista\n";
    else
        cout << "O elemento nao existe na lista\n";

    l.inserir_final(10.2);
    l.inserir_final(20.6);
    l.inserir_final(40.7);
    l.inserir_inicio(50.12);

     if(l.vazia())
        cout << "\nLista vazia!\n";
    else
        cout << "\nLista Nao Vazia!\n";

    l.mostrar();

     if(l.existe(10.2))
        cout << "\nO elemento existe na lista\n";
    else
        cout << "\nO elemento nao existe na lista\n";

    l.remover();

    l.mostrar();

    cout << "Tamanho da Lista: " << l.tamanho() << endl;
	return 0;
}
