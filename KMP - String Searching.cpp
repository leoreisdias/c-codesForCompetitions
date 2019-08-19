// Kruth-Morris-Pratt - KMP - String Searching

#include <bits/stdc++.h>
using namespace std;

void prefix(string word, vector<int>& aux){
	
	aux[0] = 0; //Sempre inicia em 0
	int j = 0, i = 1; // Tamanho do maior Prefixo que é Sufixo
	
	while((unsigned)i < word.size()){
		if(word[i] == word[j]){ //Se as posições forem iguais, o auxiliar recebe a posição do J+1
			j++;
			aux[i] = j;
			i++;
		}
		else{
			if(j) // Se for qualquer coisa diferente de 0
				j = aux[j-1];
			else{ //Se for zero
				aux[i] = 0;
				i++;
			}
		}
	}
}

void KMP(string text, string substr,vector<int>aux){
	
	int i_text = 0, i_substr = 0;
	
	while((unsigned)i_text < text.size()){ //Enquanto não chegar no final do texto
		
		if(substr[i_substr] == text[i_text]){ //Achou letra igual, passa pra proxima de cada
			i_text++;
			i_substr++;
		}
		
		if((unsigned)i_substr == substr.size()){ //Se chegar no final da palavra menor, é sucesso, exibi resultado e volta o indice dela pro ponto marcado
			cout << "Padrao encontrado na posicao: " << (i_text - i_substr) << endl;
			i_substr = aux[i_substr-1];
		}
		
		if((unsigned)i_text < text.size() && substr[i_substr]!=text[i_text]){ //Se nao achou igual e ainda nao tiver terminando o texto
			if(i_substr) // !=0
				i_substr = aux[i_substr - 1]; //Se achou alguma letra igual até aqui, a sequencia de iguais quebrou, logo volte para a primeira letra
			else
				i_text++; //Se não achou nada ainda, a posição da palavra ainda é zero, logo, so incrementa no texto
		}
	}
}

int main(int argc, char *argv[])
{
	
	string text = "C++ eh legal, lalalala";
	string word = "la";
	
	vector<int>aux(word.size());
	
	prefix(word,aux);
	KMP(text,word,aux); 
	
	return 0;
}