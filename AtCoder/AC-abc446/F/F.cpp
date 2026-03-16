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
    int r = 0;
    vec<vec<int>> g(n), rg(n);
    L(i,0,m){
        int u, v; cin >> u >> v;
        u --; v--;
        g[u].pb(v);
        rg[v].pb(u);
    }
    L(i,0,n){
        for (int v: g[i]) {
            if (v > i) r ++; // I need to disconnect it from the ones higer
        }
        for (int v: rg[i]){
            if (v < i) r --;
        }
        cout << r << "\n";
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