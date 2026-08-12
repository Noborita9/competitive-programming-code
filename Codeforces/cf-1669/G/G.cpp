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
    int n, m; cin >> n >> m;
    vec<vec<char>> g(n, vec<char>(m));
    L(i,0,n)
    {
        L(j,0,m)
        {
            cin >> g[i][j];
        }
    }
    // L(i,0,n){
    //     L(j,0,m){
    //         cout << g[i][j];
    //     }
    //     cout << "\n";
    // }
    for (int i = n - 1; i >= 0; i --)
    {
        for (int j = m - 1; j >= 0; j --) if (g[i][j] == '*')
        {
            for (int k = i; k + 1 < n; k ++) {
                if (g[k + 1][j] == '.') {
                    g[k][j] = '.';
                    g[k + 1][j] = '*';
                } else if (g[k + 1][j] == 'o') break;
            }
        }
    }
    L(i,0,n){
        L(j,0,m){
            cout << g[i][j];
        }
        cout << "\n";
    }
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}