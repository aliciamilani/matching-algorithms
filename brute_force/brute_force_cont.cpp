#include <bits/stdc++.h>

using namespace std;

//O((N-M) * M)

//lista com todas as ocorrências de um pattern
vector <int> occurrences;

//função que retorna a quantidade de vezes que um pattern foi encontrado
int brute_force_cont(string patt, string txt){
    int cont = 0; //contador de frequência
    int N = txt.length(); //tamanho do texto
    int M = patt.length(); //tamanho do pattern
    int iteration = N - M; //quantidade de iterações máximas
    int f, j;

    //esse for percorre N-M indexs do meu texto
    //assim ele encontra todas as ocorrências de um pattern
    for(int i = 0; i <= iteration; i++){

        //i é o meu index do texto que será o inicio da minha substring
        //que será comparada com o meu pattern.

        j = 0;
        f = 1;

        //Enquanto flag for verdadeiro e eu não estiver no final do meu pattern
        //eu percorro o texto a partir do index em questão e comparo cada caracter
        //do meu pattern e do meu texto, a fim de encontrar uma igualdade.
        while(f && j < M){

            //se o caracter do meu pattern for diferente do caracter
            //na mesma posição da substring do meu texto, então eu abaixo minha flag
            //para encerrar as comparações, pois não é uma substring que me atenda.
            if(patt[j] != txt[i+j]){
                f = 0;
            } 
            //se não, eu continuo percorrendo meu pattern
            else{
                j++;
            }
        }

        //Se, ao encerrar o loop, o j tiver o mesmo valor que o tamanho do meu pattern
        //quer dizer que todos os caracteres são iguais e foi encontrada uma ocorrência.
        if(j == M){
            //então é inserido o index do inicio da ocorrencia na lista de ocorrencias
            occurrences.push_back(i);

            //e a quantidade de ocorrencias é incrementada
            cont++;
        }
    }

    //ao final, é retornada a quantidade de ocorrencias
    return cont;
}

int main(){

    string text, pattern;
    cin >> text >> pattern;
    int total_occurrences = brute_force_cont(pattern, text);
    cout << "Total: " << total_occurrences << endl;
    for(int i = 0; i < occurrences.size(); i++){
        cout << "Ocorrencia em: " << i << endl;
    }

    return 0;
}