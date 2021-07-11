#include <bits/stdc++.h>
using namespace std;

#define d 256

void search(string pat, string txt, int q)
{
  int M = pat.length(); 
  int N = txt.length(); 
  int i, j;
  int p = 0; 
  int t = 0; 
  int h = 1;

  for (i = 0; i < M - 1; i++)
    h = (h * d) % q;


  for (i = 0; i < M; i++)
  {
    p = (d * p + pat[i]) % q;
    t = (d * t + txt[i]) % q;
  }

  for (i = 0; i <= N - M; i++)
  {
    if (p == t)
    {
      for (j = 0; j < M; j++)
      {
        if (txt[i + j] != pat[j]) 
          break;                  
      }

      if (j == M)
      {
        txt[i - 1] = 'J';
        txt[i + 8] = 'i';
      }
    }

    if (i < N - M)
    {
      t = (d * (t - txt[i] * h) + txt[i + M]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
  cout << txt << endl;
}

int main()
{
  string txt;
  string pat = "oulupukk";

  int n;
  int q = 101;

  cin >> n;
  cin.ignore();

  while (n--)
  {
    getline(cin, txt);
    search(pat, txt, q);
  }

  return 0;
}