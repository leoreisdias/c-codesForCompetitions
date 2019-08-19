#include <iostream>
using namespace std;

int knapsack(int W, int weightElement[], int b[], int n){
	// tabela que sera preenchida
	int V[n + 1][W + 1];

	// inicializando a primeira linha e primeira coluna com 0
	for(int backpackWeight = 0; backpackWeight <= W; backpackWeight++)
		V[0][backpackWeight] = 0;
	for(int i = 1; i <= n; i++)
		V[i][0] = 0;

	for(int i = 1; i <= n; i++){
		for(int backpackWeight = 1; backpackWeight <= W; backpackWeight++){
			// elemento pode fazer parte da solucao
			if(weightElement
		[i - 1] <= backpackWeight)
                V[i][backpackWeight] = max(b[i-1] + V[i-1][backpackWeight - weightElement
			[i-1]], V[i-1][backpackWeight]);
			else
				V[i][backpackWeight] = V[i-1][backpackWeight]; // peso do elemento > sub peso da mochila atual
		}
	}
	// retorna o valor maximo colocado na mochila
	return V[n][W];
}

int main(int argc, char *argv[])
{
	// capacidade maxima da mochila: W
	int W = 10;

	// namero de elementos
	int n = 5;

	// vetor com os valores (beneficio) de cada elemento
	int b[] = {3, 5, 8, 4, 10};

	// vetor com os pesos de cada elemento
	int wt[] = {2, 2, 3, 7, 6};

	// obtem o maximo valor que pode ser colocado na mochila
	int max_valor = knapsack(W, wt, b, n);

	cout << "Maximum Value: " << max_valor << endl;

	return 0;
}
