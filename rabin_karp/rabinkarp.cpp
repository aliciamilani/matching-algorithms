#include <bits/stdc++.h>
using namespace std;

// d é o número de caracteres no alfabeto que sera utilizado
#define d 256

// pat -> pattern (padrao)
// txt -> texto
// q -> numero primo

void search(char pat[], char txt[], int q)
{
  int M = strlen(pat); // tamanho do padrao
  int N = strlen(txt); // tamanho do texto
  int i, j;
  int p = 0; // valor hash para o padrao
  int t = 0; // valor hash para o texto
  int h = 1;

  for (i = 0; i < M - 1; i++)
    h = (h * d) % q;

  // Calculando o valor hash do padrao e da primeira janela do texto
  for (i = 0; i < M; i++)
  {
    p = (d * p + pat[i]) % q;
    t = (d * t + txt[i]) % q;
  }

  // Checando o padrão no texto posicao a posicao
  for (i = 0; i <= N - M; i++)
  {

    // Comparando os valores hash da janela de texto atual e do padrão.
    // Se esses valores forem iguais, será necessario verificar os caracteres um a um
    if (p == t)
    {
      // Verificando os caracteres um a um
      for (j = 0; j < M; j++)
      {
        if (txt[i + j] != pat[j]) // se algum caracter nao bater,
          break;                  // ocorre a saida do laco
      }

      // se j (contador) for igual a M (tam do padrao)
      // significa que nao houve break, todas os caracteres bateram
      if (j == M)
        cout << "Pattern found at index " << i << endl;
    }

    // Recalculando o valor do hash para a prox janela
    // removendo o digito inicial e adicionando o final

    if (i < N - M)
    {
      t = (d * (t - txt[i] * h) + txt[i + M]) % q;

      // Se o t ficar negativo, será necessário deixa-lo positivo
      if (t < 0)
        t = (t + q);
    }
  }
}

int main()
{
  char txt[] = "teste karp rabin teste.";
  char pat[] = "teste";

  // inicialização do número primo
  int q = 101;

  // chamada da função
  search(pat, txt, q);
  return 0;
}