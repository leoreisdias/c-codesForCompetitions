// Permutação - Backtracking

#include<bits/stdc++.h>
using namespace std;

void troca(int v[],int i,int j) //Troca elementos de posições
{
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

void permuta(int v[],int base,int limite)
{
	if(base == limite){ //Se chegou ate o tamanho do vetor, exibe a permutação atual
		for(int i = 0; i <=limite ; i++)
			cout << v[i] << " ";
		cout << endl;
	}
	else{
		for(int i=base; i<= limite;i++){
			troca(v,base,i); //Troca dois elementos de posição
			permuta(v,base+1,limite); //Leva adiante até exibir a permutação
			troca(v,base,i); //Destroca de novo para no proximo i haver outra troca diferente
		}
	}
}

int main(int argc, char** argv)
{
	int v[] = {1,2,3};
	int tam_v = sizeof(v) / sizeof(int);
	
	permuta(v,0,tam_v - 1);
	return 0;
}