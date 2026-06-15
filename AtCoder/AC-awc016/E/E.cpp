#include <bits/stdc++.h>
using namespace std;

#define L(i,j,n) for (int i = (j); i < (int)n; i ++)
#define vec vector
#define pb push_back
#define ALL(x) begin(x),end(x)
#define SZ(x) int(x.size())
#define eb emplace_back

using ll = long long;

using ii = pair<ll, int>;
using iii = tuple<ll, int, int>;

void solve()
{
    int n, m; cin >> n >> m;
    vec<ll> p(n);
    L(i,0,n) cin >> p[i];
    int s, t; cin >> s >> t; s --; t --;
    vec<vec<ii>> g(n);
    L(i,0,m)
    {
        int u, v; ll w; cin >> u >> v >> w;
        u --; v --;
        g[u].eb(w, v);
        g[v].eb(w, u);
    }
    int masks = 1 << n;
    const ll oo = 1e18;
    vec<vec<ll>> best(masks, vec<ll>(n, -oo));
    best[1 << s][s] = p[s];
    priority_queue<iii> pq;
    pq.push({p[s], 1 << s, s});
    ll ans = -oo;
    while(SZ(pq)) {
        auto [d, mask, u] = pq.top(); pq.pop();
        if (best[mask][u] != d) continue;
        if (u == t){
            ans = max(ans, d);
        }
        for (const auto &[w, v]: g[u]) {
            ll ndist = d - w;
            if ((mask & (1 << v)) == 0) {
                ndist += p[v];
            }
            int nmask = mask | (1 << v);
            if (best[nmask][v] < ndist) {
                best[nmask][v] = ndist;
                pq.push({ndist, nmask, v});
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}