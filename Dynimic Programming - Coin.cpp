#include <bits/stdc++.h>
using namespace std;
#define INF 10000000;

vector<vector<int> > vetor;

int getMoeda(int num_moedas,int moedas[],int indice,int troco,vector<vector<int> > vetor)
{
	//Casos bases
	if(indice == num_moedas && troco > 0) vetor[indice][troco] = INF; 
	if(indice == num_moedas && troco == 0) vetor[indice][troco] = 0;
	if(troco<0) return INF;

	if(vetor[indice][troco] == -1){
		//O min por ser o menor numero de moeda, e soma 1 pois considera que pegou a atual do indice
		vetor[indice][troco] = min(1 + getMoeda(num_moedas,moedas,indice,troco - moedas[indice],vetor),getMoeda(num_moedas,moedas,indice+1,troco,vetor));
	}
	return vetor[indice][troco];
}

int main(int argc, char *argv[])
{
	
	int troco, num_moedas;
	cout << "Valor a ser trocado e quantidade de moedas, respectivamente: ";
	cin >> troco >> num_moedas;

	vector<int> aux(troco+2,-1);
	for(int i=0;i<=troco+1;i++){
		vetor.push_back(aux);	
	}
	
	cout << "Moedas: ";
	int * moedas = new int[num_moedas];
	for(int i=0;i<num_moedas;i++)
        cin >> moedas[i];


	cout << "Minimo de Moedas: " << getMoeda(num_moedas,moedas,0,troco,vetor) << endl;
	return 0;
}
