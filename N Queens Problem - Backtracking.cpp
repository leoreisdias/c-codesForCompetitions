// N-Queens Problem - Backtracking

#include <bits/stdc++.h>
using namespace std;

//Quantidade de soluções possiveis!
int sol = 0;

//Mostrar o tabuleiro
void print_tab(vector<vector<int> >& tab,int N){
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(tab[i][j] == 1)
				cout << "R\t";
			else
				cout << "-\t";
		}
		cout << "\n\n";
	}
	cout << endl;	
}

//Verifica se é possivel usar daquela posição para a nova Rainha
bool isPossible(vector<vector<int> >& tab, int N, int line,int column){

	//Diagonal Principal
	for(int i=line, j=column;i<N && j<N;i++,j++){
		if(tab[i][j])
			return false;
	}
	for(int i=line, j=column;i>=0 && j>=0;i--,j--){
		if(tab[i][j])
			return false;
	}
	
	//Diagonal Secundaria
	for(int i=line, j=column;i>=0 && j<N;i--,j++){
		if(tab[i][j])
			return false;
	}
	for(int i=line, j=column;i<N && j>=0;i++,j--){
		if(tab[i][j])
			return false;
	}	
	
	// Retorna true se for possivel inserir na posição em questão
	return true;
}

//Retorna true se resolver e false se não resolver
void Queens(vector<vector<int> >& tab, int N,int column,int vect_line[]){
	
	if(column == N){
		cout << "Solucao: " << sol+1 << ":\n\n";
		print_tab(tab,N);
		sol++;
		return;
	}
	for(int i=0;i<N;i++){
		//Seguro colocar nessa posição da coluna e a linha esta vazia?
		if(isPossible(tab,N,i,column) && !vect_line[i]){
			tab[i][column] = vect_line[i] = 1;   //Insere a Rainha e Marca a linha
			Queens(tab,N,column+1,vect_line);   // Chama pra proxima Rainha na próxima coluna
			tab[i][column] = vect_line[i] = 0; // Remove a Rainha no Backtracking e desmarca a linha
		}
	}
}

int main(int argc, char *argv[])
{
	int N = 8;
	int vect_line[N];
	
	vector<vector<int> > tab;
	
	for(int i=0;i<N;i++){
		vector<int> line(N);
		tab.push_back(line);
		vect_line[i] = 0;
	}
	
	Queens(tab,N,0,vect_line);
	
	cout << "Numero de Solucoes: " << sol << endl;
	
	return 0;
}