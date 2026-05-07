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
    int n, m, k; ll T; cin >> n >> m >> k >> T;
    vec<vec<pair<int, ll>>> g(n);
    L(i,0,m){
        int u, v; ll w; cin >> u >> v >> w; 
        u --; v--;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }
    vec<bool> flood(n);
    L(i,0,k) {
        int x; cin >> x;
        flood[x - 1] = 1;
    }
    priority_queue<pair<ll, int>, vec<pair<ll, int>>, greater<pair<ll,int>>>pq;
    const ll oo = 1e18;
    vec<ll> dist(n, oo);
    auto fcost = [&](int x, ll w) -> ll {
        if (flood[x]) return T + w;
        return w;
    };
    dist[0] = fcost(0, 0);
    pq.push({dist[0], 0});
    while(SZ(pq)){
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w]: g[u]) if (dist[v] > fcost(v, d + w)) {
            dist[v] = fcost(v, d + w);
            pq.push({dist[v], v});
        }
    }
    cout << dist[n - 1] << "\n";
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