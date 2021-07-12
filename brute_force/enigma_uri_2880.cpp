#include <bits/stdc++.h>

using namespace std;

//https://www.urionlinejudge.com.br/judge/pt/problems/view/2880

int brute_force_cont(string patt, string txt){
    int cont = 0;
    int N = txt.length();
    int M = patt.length();
    int iteration = N - M;
    int f, j;

    for(int i = 0; i <= iteration; i++){

        j = 0;
        f = 1;
        while(f && j < M){
            if(patt[j] == txt[i+j]){
                f = 0;
            } else{
                j++;
            }
        }
        if(j == M){
            cont++;
        }
    }

    return cont;
}

int main(){
    string text;
    string pat;
    cin >> text >> pat;
    cout << brute_force_cont(pat, text) << endl;
    return 0;

}