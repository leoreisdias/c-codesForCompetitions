#include<bits/stdc++.h>
using namespace std;

void kadane(vector<int>& vet)
{
    int atual = 0,  total = -1;
    int tam = vet.size();

    for(int i=0; i<tam; i++)
    {
        atual+= vet[i]; //Vai somando as posições

        if(atual<0) atual=0; //Se der negativo, restart pra 0

        total = max(total,atual); //Sempre guardando a maior soma a cada iteração no total
    }
    cout << total << endl;
}

int main(int argc, char * argv[])
{
    vector<int> vet;
    vet.push_back(-2);
    vet.push_back(5);
    vet.push_back(-1);
    vet.push_back(2);
    vet.push_back(-3);

    kadane(vet);


    return 0;
}
