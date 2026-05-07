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
    int n; cin >> n;
    vec<vec<pair<ll, int>>> g(n);
    L(i,1,n){
        int u, v; ll w; cin >> u >> v >> w;
        u --; v--;
        g[u].eb(w, v);
        g[v].eb(w, u);
    }
    int m; cin >> m;
    vec<int> par(n);
    L(i,0,m){
        int u, v; cin >> u >> v;
        u --; v --;
        par[u] ^= 1;
        par[v] ^= 1;
    }
    ll cost = 0;
    auto calc = [&](auto && dfs, int u, int p) -> void {
        for (auto [w, v]: g[u]) if (v != p) {
            dfs(dfs, v, u);
            if (par[v]) {
                par[v] ^= 1;
                par[u] ^= 1;
                cost += w;
            }
        }
    };
    calc(calc, 0, -1);
    cout << cost << "\n";
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