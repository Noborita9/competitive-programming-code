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
    vec<int> reach(n);
    vec<vec<int>> g(n);
    L(i,0,m){
        int u, v; cin >> u >> v;
        u --; v--;
        g[u].pb(v);
    }
    auto go = [&](auto && dfs, int u) -> void {
        if (reach[u]) return;
        reach[u] = 1;
        for (int v: g[u]) dfs(dfs, v);
    };
    go(go, 0);
    cout << accumulate(ALL(reach), 0) << "\n";
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