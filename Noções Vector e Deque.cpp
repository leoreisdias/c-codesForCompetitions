#include<bits/stdc++.h>
using namespace std;

class Ponto
{
public:
    int x, y;

    Ponto(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int main()
{
    vector<int> vet;

    vet.push_back(2);
    vet[1] = 3;
    vector<int>::iterator it;
    it = vet.begin();
//--------------------------------------------------------- EXIBIÇÕES ---------------------------------------------------------------
    cout << "Primeiro Valor por *: "<< *vet.begin()<< endl; // Exibe conteudo por * de uma referenciação
    cout << "Segundo valor por [ ]: "<< vet[1] << endl;
    cout <<"Primeiro valor pelo Iterator: "<< *it << endl;

    *it = 1; // Alterações feitas no conteudo do iterator alteram o conteudo do endereço do vector que ele esta apontado.
    cout << endl << "Primeiro valor alterado a partir do iterator: " << *vet.begin() << endl;

    vet.push_back(5);
    vet.push_back(10);

    cout << "Valores do Vector: ";
    for(int i=0;i<vet.size();i++)
        cout << vet[i] << " ";
    cout << "\n";
//------------------------------------------------ INSERT PELA POSIÇÃO DO ITERATOR --------------------------------------------------------
    it= vet.begin();
    it+=2;
    vet.insert(it,9); // O iterator move-se pelo vector, e serve como referencia de posição dentro deste para operadores como .insert, etc
    cout << "Valores do Vector apos o .insert na posição referenciada pelo iterator: ";
    for(int i=0;i<vet.size();i++)
        cout << vet[i] << " ";
    cout << "\n";
//-------------------------------------------- REVERSE ITERATOR - PERCORRER AO CONTRARIO ---------------------------------------------------
    vector<int>::reverse_iterator rit;// Reverse iterator para percorrer o inverso.
    cout << "Usando reverse Iterator para percorrer ao contrario, entre o reverse de begin(rbegin) e de end(rend): ";
    for(rit=vet.rbegin(); rit!=vet.rend();++rit) // Para o reverso usar o reverso de begin(rbegin) e o reverso de end(rend)
        cout << *rit << " ";
    cout << "\n";
//---------------------------------------------   ERASE  -------------------------------------------------
    vet.erase(vet.begin()); //Primeira posição apagada
    vet.erase(vet.begin()); //Nova primeira posição apagada
    cout << "Valores do Vector .erase na posicao 0 e 1: ";
    for(int i=0;i<vet.size();i++)
        cout << vet[i] << " ";
    cout << "\n";

//---------------------------------------------   SWAP E PREENCHIMENTO  -------------------------------------------------
    vector<int>a(3,20); //Define que inicialmente o vector A possui 3 posições já preenchidas com o inteiro 20.
    vector<int>b(2,10); //Define que inicialmente o vector B possui 2 posições já preenchidas com o inteiro 10.

    a.swap(b); // Troca os valores de A por B;

       cout << "\nValores do Vector A eram 20 20 20, apos a troca com .swap sao: ";
    for(int i=0;i<a.size();i++)
        cout << a[i] << " ";
    cout << "\n";

    a.clear(); // Limpa toda a alocação e dados
    cout << "\nTamanho de A apos ser limpado com .clear: "<<a.size()<<endl << endl;

//---------------------------------------------   Chamando Vector para Classes Feitas  -------------------------------------------------
    vector<Ponto*>v; // Vector do tipo Ponto*, mas poderia não ser ponteiro
    vector<Ponto*>::iterator pont;// Em forma de ponteiro para economia de memoria ao não precisar fazer copias dos objetos, o que ponteiro não faz

    Ponto* p1 = new Ponto(1,2); // Por ser ponteiro, caso não fosse seria: Ponto p1(1,2);
    Ponto* p2 = new Ponto(3,4);
    v.push_back(p1);
    v.push_back(p2);

    cout << "Pontos guardados no vector de tipo Ponto: ";
    for(pont=v.begin();pont!=v.end();++pont)
        cout << "(" << (*pont)->x << "," << (*pont)->y << ")\n"; //Ponteiro apontado usa "->"

//---------------------------------------------   DEQUE e função find()  -------------------------------------------------
    deque<int>deq;
    deq.push_back(2);
    deq.push_back(4);
    deq.push_back(10);

    if(find(deq.begin(),deq.end(),10) != deq.end())
        cout << "\n10 achado";

    system("pause>null");
    return 0;
}
