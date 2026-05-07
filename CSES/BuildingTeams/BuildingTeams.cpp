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
    int n, m; cin >> n >> m ;
    vec<vec<int>> g(n);
    L(i,0,m){
        int u, v; cin >> u >> v;
        u -- ; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vec<int> col(n, - 1);
    auto paint = [&](auto && dfs, int u) -> void {
        for (int v: g[u]) {
            if (col[v] == -1) {
                col[v] = 1 - col[u]; // Perfecto 01
                dfs(dfs, v);
            }
            else {
                if (col[v] == col[u]) {
                    cout << "IMPOSSIBLE\n";
                    exit(0);//exit(codigo de error)
                }
            }
        }
    };
    L(i,0,n) if (cond) {
        codigo
    }
    
    L(i,0,n) if (col[i] == -1) {
        col[i] = 0;
        paint(paint, i);
    }
    L(i,0,n) cout << col[i] + 1 << " ";
    cout << "\n";
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