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


using ii = pair<ll, int>;
void solve()
{
    int n, m, k; cin >> n >> m >> k;
    vec<ll> toll(n);
    vec<vec<ii>> g(n);
    L(i,0,m){
        int u, v; ll w; cin >> u >> v >> w;
        u --; v--;
        g[u].eb(w, v);
        g[v].eb(w, u);
    }
    L(i,0,k){
        int x; ll w; cin >> x >> w;
        toll[x - 1] = w;
    }
    const ll oo = 1e18;
    vec<ll>dist(n, oo);
    dist[0] = toll[0];
    priority_queue<ii, vec<ii>, greater<ii>> pq;
    pq.push({toll[0], 0});
    while(SZ(pq)){
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [w, v]: g[u]) if (dist[v] > d + w + toll[v]) {
            dist[v] = d + w + toll[v];
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