#include<bits/stdc++.h>
using namespace std;

int getLCS(string& s1, string& s2)
{
    int tam_s1 = s1.size(), tam_s2 = s2.size();
    int mat[tam_s1+1][tam_s2+1];

    //Zerando a primeira linha e primeira coluna.
    for(int i=0;i<=tam_s1;i++)
        mat[i][0] = 0;
    for(int i=1;i<=tam_s2;i++)
        mat[0][i] = 0;

    for(int i=1;i<=tam_s1;i++){
        for(int j=1;j<=tam_s2;j++){
            if(s1[i-1] == s2[j-1])
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
        }
    }

    return mat[tam_s1][tam_s2]; // Resposta esta na ultima posição da matriz

}

int main(int argc, char * argv[])
{
    string s1("ABCB"), s2("BDCAB");

    int tam_lcs = getLCS(s1,s2);
    cout << "Maior Subsequencia Comum: " << tam_lcs << endl;

	return 0;
}
