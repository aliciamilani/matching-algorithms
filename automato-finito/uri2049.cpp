#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256 
int getNextState(string p, int M, int s, int x){ 
    if (s < M && x == p[s])
        return s+1;
    int ns, i; 
    for (ns = s; ns > 0; ns--) {
        if (p[ns-1] == x){ 
            for (i = 0; i < ns-1; i++) 
                if (p[i] != p[s-ns+1+i]) 
                    break; 
            if (i == ns-1) 
                return ns; 
        } 
    } 
    return 0; 
}
void computeTF(string p, int M, int TF[][NO_OF_CHARS]){ 
    int s, x; 
    for (s = 0; s <= M; ++s) 
        for (x = 0; x < NO_OF_CHARS; ++x) 
            TF[s][x] = getNextState(p, M, s, x); 
} 
void search(string p, string t, int num){ 
    int M = p.size(); 
    int N = t.size(); 
    int TF[M+1][NO_OF_CHARS]; 
    computeTF(p, M, TF); 
    int i, s=0, c=0; 
    for (i = 0; i < N; i++){ 
        s = TF[s][t[i]]; 
        if (s==M){
            c++;
            cout<<"Instancia " << num << "\n" << "verdadeira" << endl;
            break;
        }
    }
    if (c==0){
            cout<<"Instancia " << num << "\n" << "falsa" << endl;
        }
} 
int main(){ 
    string t, p;
    int num = 0;
    int a = 1;
    while (a=1){
        cin >> p;
        if(p == "0"){
            a--;
        }
        num++;
        cin >> t;
        search(p, t, num);
    }
    return 0;
}