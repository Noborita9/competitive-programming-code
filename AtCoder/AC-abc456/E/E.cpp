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
        u --; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    int w; cin >> w;
    vec<vec<bool>> h(n, vec<bool>(w));
    L(i,0,n){
        g[i].pb(i);
        L(j,0,w){
            char c; cin >> c;
            if (c == 'o') h[i][j] = 1;
        }
    }
    const int WHITE = 0;
    const int GRAY = 1;
    const int BLACK = 2;
    vec<vec<int>> vis(n,vec<int>(w, WHITE));
    // vis[u][wi]
    bool cyc = false;
    auto fnd = [&](auto && dfs, int u, int wi) -> void {
        if (vis[u][wi]) return;
        if (!h[u][wi]) {
            vis[u][wi] = BLACK;
            return;
        }
        vis[u][wi] = GRAY;
        int nwi = wi + 1;
        if (nwi == w) nwi = 0;
        for (int v: g[u]) {
            if (vis[v][nwi] == WHITE) dfs(dfs, v, nwi);
            else if (vis[v][nwi] == GRAY){
                cyc = 1;
                return;
            }
            if (cyc) return;
        }
        vis[u][wi] = BLACK;
    };
    L(i,0,n) if (h[i][0] && !vis[i][0] && !cyc)
    {
        fnd(fnd, i, 0);
    }
    if (cyc) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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