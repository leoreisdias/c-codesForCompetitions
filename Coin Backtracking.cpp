/*
	Problema do número mínimo de moedas
	Resolução através de backtracking
*/

#include <iostream>
#define INFINITO 10000000

using namespace std;

int obter_min_moedas(int moedas[], int troco, int tam_moedas)
{
	int min_moedas = INFINITO;

	if(troco == 0)
		return 0;

	for(int i = 0; i < tam_moedas; i++)
	{
		if(troco >= moedas[i])
		{
			int cont = 1 + obter_min_moedas(moedas, troco - moedas[i], tam_moedas);

			min_moedas = min(min_moedas,cont);
		}
	}

	return min_moedas;
}

int main(int argc, char *argv[])
{
    int troco, num_moedas;
    cin >> troco >> num_moedas;
	int moedas[num_moedas];
	for(int i=0;i<num_moedas;i++)
        cin >> moedas[i];

	int tam_moedas = sizeof(moedas) / sizeof(int);

	cout << obter_min_moedas(moedas, troco, tam_moedas) << endl;

	return 0;
}
