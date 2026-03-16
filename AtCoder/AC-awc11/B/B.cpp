#include <bits/stdc++.h>
using namespace std;

#define L(i, j, n) for (int i = (j); i < (int)n; i ++)
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define vec vector
#define pb push_back
#define eb emplace_back

using ll = long long;
using ld = long double;

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    vec<vec<char>> out(n * k, vec<char>(m * k));
    map<char, char> t;
    char c1, c2; cin >> c1 >> c2;
    t['#'] = c1;
    t['.'] = c2;
    L(i,0,n){
        L(j,0,m){
            char c; cin >> c;     
            char f = t[c];
            L(u,0,k){
                L(v,0,k){
                    out[i * k + u][j * k + v] = f;
                }
            }
        }
    }
    for (auto v: out){
        for (char c: v) {
            cout << c;
        }
        cout << "\n";
    }
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    //cin >> TT;
    while (TT--)
    {
        solve();
    }
}