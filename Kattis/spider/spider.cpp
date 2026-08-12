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

struct DSU {
    vec<int> par, sz; int n;
    DSU(int n_ = 1): par(n_), sz(n_, 1), n(n_) { iota(ALL(par), 0); }
    int find(int a){return a == par[a] ? a : par[a] = find(par[a]);}
    bool join(int a, int b){
        a=find(a);b=find(b);
        if (a == b) return false;
        if (sz[b] > sz[a]) swap(a,b);
        par[b] = a; sz[a] += sz[b];
        return true;
    }
};


int n, m;
using iii = tuple<ll, int, int>;
vec<iii> E; 
const int N = 1005;
ll dist[N][N];

void solve()
{
    E.clear();
    L(i,0,m){
        int u, v; ll w; cin >> u >> v >> w;
        u --; v --;
        E.eb(w, u, v);
    }
    sort(ALL(E));
    DSU ds(n);
    int cc = n;
    ll cost = 0;
    vec<vec<pair<ll, int>>> g(n);
    ll mx = 0;
    for (const auto &[w, u, v]: E) {
        if (ds.join(u, v)) {
            cost += w;
            g[u].eb(w, v);
            g[v].eb(w, u);
            mx = max(mx, w);
            if (--cc == 1) break;
        }
    }
    if (cc != 1) {
        cout << "disconnected\n";
        return;
    }
    auto calc = [&](auto && dfs, int u, int p, int root) -> void {
        for (const auto &[w, v]: g[u]) if (v != p){
            dist[root][v] = max(dist[root][u], w);
            dfs(dfs, v, u, root);
        }
    };
    L(i,0,n) {
        dist[i][i] = 0;
        calc(calc, i, -1, i);
    }
    reverse(ALL(E));
    ll ans = cost - 2 * mx;
    for (const auto &[w, u, v]: E) {
        if (w < mx) break;
        ll ncost = cost - (w + dist[u][v]);
        ans = min(ans, ncost);
    }
    cout << ans << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    //cin >> TT;
    E.reserve(1'000'000);
    while (1)
    {
        if (!cin.good() || cin.eof()) break;
        cin >> n;
        if (!cin.good() || cin.eof()) break;
        cin >> m;
        solve();
    }
}