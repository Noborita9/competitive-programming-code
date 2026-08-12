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
    int n, m; ll y; cin >> n >> m >> y;
    vec<vec<pair<ll, int>>> g(n + 2);
    L(i,0,m){
        int u, v; ll w; cin >> u >> v >> w;
        u --; v --;
        g[u].eb(w, v);
        g[v].eb(w, u);
    }
    g[n].eb(y, n + 1);
    g[n + 1].eb(y, n);
    L(i,0,n){
        ll x; cin >> x;
        g[i].eb(x, n);
        g[n + 1].eb(x, i);
    }
    const ll oo = 1e18;
    vec<ll> dist(n + 2, oo);
    dist[0] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({0ll, 0});
    while(SZ(pq)){
        auto [d, u] = pq.top(); pq.pop(); d = -d;
        if (dist[u] != d) continue;
        for (const auto &[w, v]: g[u]) if (dist[v] > d + w){
            dist[v] = d + w;
            pq.push({-dist[v], v});
        }
    }
    L(i,1,n) cout << dist[i] << " ";
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