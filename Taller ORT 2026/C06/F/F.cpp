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

using iii = tuple<ll, int, int>;

void solve()
{
    int n, m; cin >> n >> m;
    vec<iii> E;E.reserve(m);
    L(i,0,m){
        int u, v; ll w; cin >> u >> v >> w;
        E.eb(w, u - 1, v - 1);
    }
    sort(ALL(E));
    DSU dsk(n);
    vec<iii> rem; rem.reserve(m - n + 1);
    vec<iii> tree; tree.reserve(n);
    ll mst_cost = 0;
    for (const auto &[w, u, v]: E){
        if (ds.find(u) == ds.find(v)) {
            rem.eb(w, u, v);
            continue;
        }
        ds.join(u,v);
        tree.eb(w, u, v);
        mst_cost += w;
    }

    DSU dsr(n);
    

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