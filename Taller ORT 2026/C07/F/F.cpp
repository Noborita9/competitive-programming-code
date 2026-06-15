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

using ii = pair<int, int>;

const int BLOCK_SIZE = 550;

void solve()
{
    int n, k, s, q; cin >> n >> k >> s >> q;
    vec<vec<int>> g(n);
    L(i,1,n)
    {
        int u, v; cin >> u >> v; u --; v --;
        g[u].pb(v);
        g[v].pb(u);
    }
    vec<vec<int>> c(n);
    vec<vec<int>> nodes(k);
    vec<int> par(n, - 1);
    auto rec = [&](auto && dfs, int u, int p) -> void {
        par[u] = p;
        for (int v: g[u]) if (v != p) dfs(dfs, v, u);
    };
    rec(rec, 0, - 1);
    L(i,0,s)
    {
        int u, x; cin >> u >> x;
        u --; x --;
        c[u].pb(x);
        nodes[x].pb(u);
    }
    L(i,0,n)sort(ALL(c[i]));

    vec<vec<int>> c_x(n);
    vec<bool> active(n);
    vec<int> dsu(n), sz(n, 1); iota(ALL(dsu), 0);
    auto find = [&](auto &&f, int u) -> int {return u == dsu[u] ? u : dsu[u] = f(f, dsu[u]);};
    auto join = [&](int u, int v){ u = find(find, u), v = find(find,v); if (u == v) return; if (sz[v]>sz[u]) swap(u, v); dsu[v] = u; sz[u] += sz[v];};
    L(i,0,k)
    {
        for (int u: nodes[i]) {
            active[u] = 1;
        }
        for (int u: nodes[i]) {
            if (par[u] != -1 && active[par[u]])
            {
                join(u, par[u]);
            }
        }
        for (int u: nodes[i]) {
            c_x[u].eb(find(find,u));
        }
        for (int u: nodes[i]) {
            dsu[u] = u;
            sz[u] = 1;
            active[u] = 0;
        }
        
    }
    vec<vec<ii>> qs(n);
    vec<int> ans(q);
    L(i,0,q){
        int u, v; cin >> u >> v; u --; v --;
        if (SZ(c[v]) >= BLOCK_SIZE) swap(u, v);
        if (SZ(c[u]) >= BLOCK_SIZE) {
            qs[u].eb(v, i);
        } else {
            // Means it's light to light
            int pu = 0;
            int pv = 0;
            while (pu < SZ(c[u]) && pv < SZ(c[v])) {
                if (c[u][pu] == c[v][pv]){
                    ans[i] += c_x[u][pu] == c_x[v][pv];
                    pu ++;
                    pv ++;
                } else if (c[u][pu] < c[v][pv]) pu ++;
                else pv ++;
            }
            
        }
    }

    vec<vec<int>> qg(n);

    vec<int> freq(k);
    auto hdfs = [&](auto && dfs, int u, int d, int p) -> void {
        int ansu = 0;
        for (int ki: c[u]) {
            if (++freq[ki] == d) {
                ansu ++;
            }
        }
        for (int qi: qg[u]) ans[qi] = ansu;
        qg[u].clear();
        for (int v: g[u]) if (v != p) dfs(dfs, v, d + 1, u);
        for (int ki: c[u]) {
            --freq[ki];
        }
        

    };

    L(i,0,n) if (SZ(qs[i])) {
        for (auto [v, ix]: qs[i]) qg[v].pb(ix);
        hdfs(hdfs, i, 1, -1);
    }


    L(i,0,q)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
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