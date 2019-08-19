// LPS - Longest Palindromic Subsequence

#include<bits/stdc++.h>
using namespace std;

int LPS(string& str,int str_size){
	
	int memo[str_size][str_size];
	
	for(int i=0;i<str_size;i++)
		memo[i][i] = 1; //Diagonal primaria tudo 1, pois sao as letras iguais de tamanho 1
	
	int tamanho_strings = 2; //Inicia para strings de tamanho 2, pegando de 2 em 2 letras
	
	while(tamanho_strings <=str_size){
		for(int i=0,j=tamanho_strings-1 + i; j<str_size; i++,j++){ //Inicia a verificação dos extremos das mini palavras
			if(str[i] == str[j] && tamanho_strings == 2) 
				memo[i][j] = 2;
			else if(str[i] != str[j])
				memo[i][j] = max(memo[i+1][j],memo[i][j-1]); // Se não for igual, pega o maximo do valor de baixo com o da esquerda
			else
				memo[i][j] = memo[i+1][j-1] + 2; //Se for igual, pega o valor da diagonal abaixo na esquerda + 2
		}
		tamanho_strings++;
	}
	
	return memo[0][str_size-1]; //Resposta na primeira linha e ultima coluna
}

int main(int argc, char *argv[])
{  
	string word("ATCATA");
	
	cout << LPS(word,word.size()) << endl;

	return 0;
}