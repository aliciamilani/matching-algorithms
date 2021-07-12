// Algoritmo  para pesquisa de padrões de autômatos finitos
#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256 
  
int getNextState(string padrao, int M, int state, int x) 
{ 
    // Se o caractere c for igual ao próximo caractere
    // no padrão, então simplesmente incremente o estado 
    if (state < M && x == padrao[state]) 
        return state+1; 
  
    // ns armazena o resultado que é o próximo estado 
    int ns, i; 
  
    // ns finalmente contém o prefixo mais longo
    // que também é sufixo em "padrao [0..state-1] c" 
  
    // Comece com o maior valor possível
    // e pare quando encontrar um prefixo que
    // também é sufixo 
    for (ns = state; ns > 0; ns--) 
    { 
        if (padrao[ns-1] == x) 
        { 
            for (i = 0; i < ns-1; i++) 
                if (padrao[i] != padrao[state-ns+1+i]) 
                    break; 
            if (i == ns-1) 
                return ns; 
        } 
    } 
  
    return 0; 
} 
  
 // Esta função constrói a tabela TF que representa 4
 // Autômatos finitos para um determinado padrão * /
void computeTF(string padrao, int M, int TF[][NO_OF_CHARS]) 
{ 
    int state, x; 
    for (state = 0; state <= M; ++state) 
        for (x = 0; x < NO_OF_CHARS; ++x) 
            TF[state][x] = getNextState(padrao, M, state, x); 
} 
  
/*Imprime todas as ocorrências de padrao no texto */
void search(string padrao, string texto) 
{ 
    int M = padrao.size(); 
    int N = texto.size(); 
  
    int TF[M+1][NO_OF_CHARS]; 
  
    computeTF(padrao, M, TF); 
  
    // Processa o texto no AF. 
    int i, state=0; 
    for (i = 0; i < N; i++) 
    { 
        state = TF[state][texto[i]]; 
        if (state == M) 
            cout<<" padrão encontrado no index "<< i-M+1<<endl; 
    } 
} 
  
// Driver program to test above function 
int main() 
{ 
    string texto, padrao;

    cout << "Insira o texto: ";
    cin >> texto;
    cout << "Insira o padrão: ";
    cin >> padrao;

    search(padrao, texto); 
    return 0; 
}