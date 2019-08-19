#include<bits/stdc++.h>


using namespace std;

template <class Type>
class Pilha
{
private:
	Type *vet;
	int max_tam;
	int topo;
public:
	Pilha<Type>(int tam)
	{
		vet = new Type[tam];
		max_tam = tam - 1;
		topo = -1;
	}
	~Pilha<Type>()
	{
		delete[] vet;
	}

	void empilhar(Type n)
	{
		if(topo == max_tam)
		{
			cout << "Pilha Cheia!\n";
		}
		else
			vet[++topo] = n;
	}

	void desempilhar()
	{
		if(topo == -1)
			cout << "Pilha Vazia!\n";
		else
			topo--;
	}

	Type getTopo()
	{
		if(topo != -1)
			return vet[topo];
		return NULL;
	}

	int vazia()
	{
		return (topo == -1);
	}
};

int main(int argc, char* argv[])
{
	Pilha<const char*> p(100);
	p.empilhar("Ola");
	p.empilhar("Teste");

	cout << "Pilha vazia: " << p.vazia() << endl;
	cout << "Topo: " << p.getTopo() << endl;

	return 0;
}
