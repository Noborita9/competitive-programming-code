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
    vec<vec<int>> g(n);
    L(i,0,m){
        int u, v; cin >> u >> v;
        u--;v--;
        g[u].pb(v);
    }
    vec<int> vis(n), prev(n, -1);
    auto getp = [&](auto && dfs, int u) -> void {
        vis[u] = 1;
        for (int v: g[u]) if (!vis[v]){
            prev[v] = u;
            dfs(dfs, v);
        }
    };
    getp(getp, 0);
    vec<int> depth(n), reach(n), proh(n);
    vec<int> path;
    for (int x = n - 1; x != -1; x = prev[x]) path.pb(x);
    reverse(ALL(path));
    L(i,0,SZ(path)) {
        depth[path[i]] = i;
        proh[path[i]] = 1;
        // cout << path[i] << " ";
    }
    // cout << "\n";
    proh[0] = 0; // walk on initial
    vec<int> crit;

    auto expl = [&](auto && dfs, int u) -> int {
        reach[u] = 1;
        int k = -1;
        for (int v: g[u]) {
            if (proh[v]) {
                k = max(k, depth[v]);
            } else if (!reach[v]) {
                k = max(k, dfs(dfs, v));
            }
        }
        return k;
    };

    int last_crit = 0;
    int last_d = 0;
    crit.pb(0);
    while (last_crit != n - 1) {
        int d = expl(expl, last_crit);
        // cout << d << endl;
        // assert(d != -1);
        for (int j = last_d + 1; j <= d; j ++) proh[path[j]] = 0;
        crit.pb(path[d]);
        last_crit = path[d];
    }
    cout << SZ(crit) << "\n";
    for(int c: crit) cout << c + 1 << " ";
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