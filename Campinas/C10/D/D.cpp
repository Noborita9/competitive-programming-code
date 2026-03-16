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

using iii = tuple<int,int,int>;

void solve()
{
    int n, m; cin >> n >> m;
    vec<vec<int>> g(n);
    const int WHITE = 0;
    const int GRAY = 1;
    const int BLACK = 2;
    vec<int> c(n, WHITE);
    L(i,0,m){
        int u, v; cin >> u >> v;
        u --; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vec<iii> out;
    auto go = [&](auto && dfs, int u, int p) -> int {
        vec<int> opts;
        c[u] = GRAY;
        for (int v: g[u]) {
            if (c[v] == WHITE) {
                int o = dfs(dfs, v, u);
                if (o) {
                    opts.pb(v);
                }
            } else if (c[v] == GRAY && v != p) {
                opts.pb(v);
            }
        }
        c[u] = BLACK;
        while (SZ(opts) >= 2) {
            int x = opts.back();
            opts.pop_back();
            int z = opts.back();
            opts.pop_back();
            int y = u;
            out.eb(x,y,z);
        }
        if (SZ(opts) > 0 && p != -1){
            int x = p;
            int y = u;
            int z = opts.back();
            opts.pop_back();
            out.eb(x, y, z);
            return 0;
        } else return SZ(opts) == 0;
    };
    L(u,0,n) if (c[u] == WHITE) {
        go(go, u, - 1);
    }
    cout << SZ(out) << "\n";
    for (auto &[x,y,z]: out) {
        x++;y++;z++;
        cout << x << " " << y << " " << z << "\n";
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