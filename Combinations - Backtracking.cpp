// Combina��o - Backtracking

#include <bits/stdc++.h>
using namespace std;

void combinacao(int v[],bool presente[],int i, int tamanho)
{
	if(i == tamanho){
		for(int i=0;i<tamanho;i++)
			if(presente[i]) // Se estiver presente na combina��o atual, exibe
				cout << v[i] << " ";
			
			cout << endl;
	}
	else{
		presente[i] = true; // Coloca como presente na combina��o atual
		combinacao(v,presente,i+1,tamanho); // E manda adiante para o proximo elemento
		presente[i] = false; // Ao voltar da fun��o, o elemento sai dos presentes para n�o exibir na proxima
		combinacao(v,presente,i+1,tamanho); // E manda adiante para o proximo elemento
	}
}

int main(int argc, char *argv[])
{
	int v[] = {1,2,3};
	int tamanho = sizeof(v) / sizeof(int);
	bool presente[tamanho];
	for(int i=0;i<tamanho;i++)
		presente[i] = false;
	
	combinacao(v,presente,0,tamanho);
	
	return 0;
}