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

struct edge {
    int v, ix;
    edge(int v_=-1, int ix_=-1): v(v_), ix(ix_) {}
};

void solve()
{
    int n, m; cin >> n >> m;
    vec<vec<edge>> g(n), bg(n);
    L(i,0,m){
        int u, v; cin >> u >> v;
        u --; v--;
        g[u].eb(v, i);
        g[v].eb(u, i);
    }
    vec<int> bd(m), comp(n);
    vec<int> dfs_low(n, -1), dfs_num(n, -1);
    int dfs_c = 0;
    auto tarj = [&](auto && dfs, int u, int p) -> void {
        dfs_num[u] = dfs_low[u] = dfs_c ++;
        for (auto [v, ix]: g[u]) if (v != p){
            if (dfs_num[v] == -1){
                dfs(dfs, v, u);
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
                if (dfs_low[v] > dfs_num[u]) {
                    // It cant' reach an ancestor
                    bd[ix] = 1;
                }
            } else dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    };
    tarj(tarj, 0, -1);
    int ccn = 1;
    auto build = [&](auto && dfs, int u, int cc) -> void {
        comp[u] = cc;
        for (auto [v, ix]: g[u]) if (!comp[v]) {
            if (bd[ix]) {
                ccn ++; // Increment over bridge
                bg[comp[u]-1].eb(ccn-1, ix);
                bg[ccn-1].eb(comp[u]-1, ix);
                dfs(dfs, v, ccn);
            } else dfs(dfs, v, cc); // keep on component
        }
    };
    build(build, 0, 1);
    L(i,0,n) comp[i]--;
    // Tengo un tree sobre bg
    vec<int> D(n);
    auto dist = [&](auto && dfs, int u, int p, int d) -> void {
        D[u] = d;
        for (auto [v, ix]: bg[u]) if (v != p) {
            dfs(dfs, v, u, d + 1);
        }
    };
    dist(dist, 0, -1, 0);
    int l = max_element(ALL(D)) - begin(D);
    dist(dist, l, -1, 0);
    int diam = *max_element(ALL(D));
    cout << diam << "\n";
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