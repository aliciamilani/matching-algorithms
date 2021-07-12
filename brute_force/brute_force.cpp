#include <bits/stdc++.h>

using namespace std;

//O((N-M) * M)

//função que retorna o index da primeira ocorrência de um pattern
//ou então o tamanho do meu texto caso não encontre nenhuma ocorrência
int brute_force(string patt, string txt){
    int j, M = patt.length(); //tamanho do pattern
    int i, N = txt.length(); //tamanho do texto

    //esse for percorre N-M indexs do texto
    //assim ele encontra todas as ocorrências de um pattern
    for(i = 0; i <= (N - M); i++){

        //i é o meu index do texto que será o inicio da minha substring
        //que será comparada com o meu pattern.

        //esse for percorre todo o pattern e compara caracter por caracter
        //com o texto fornecido.
        for(j = 0; j < M; j++){

            //se eu encontrar um caracter do meu texto que não seja igual
            //ao caracter em questão do meu pattern, quer dizer que aquela não é uma substring útil
            //então eu quero meu loop
            if(txt[i+j] != patt[j]){
                break;
            }
        }

        //se ao chegar ao final do loop o meu j tiver o mesmo tamanho que o meu pattern
        //quer dizer que encontrei uma ocorrência do pattern no texto e então retorno o index inicial
        if(j == M){
            return i;
        }
    }

    //caso não encontre nenhuma ocorrência, é retornado o tamanho do texto
    return N;
}

int main(){

    string text, pattern;
    cin >> text >> pattern;
    int pos = brute_force(pattern, text);
    if(pos == text.length()){
        cout << pattern << " Não encontrado" << endl;
    } else{
        cout << "Encontrado na posição: " << pos << endl;
    }

    return 0;
}