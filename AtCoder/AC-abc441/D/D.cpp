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
    int n, m, l; ll s, t; cin >> n >> m >> l >> s >> t;
    vec<vec<ii>> g(n);
    L(i,0,m){
        int u, v; ll w; cin >> u >> v>> w;
        u -- ; v--;
        g[u].eb(w, v);
    }
    vec<ii> cur;
    cur.pb({0, 0});
    L(j,0,l) {
        vec<ii> nxt;
        nxt.reserve(SZ(cur) * 4);
        for (const auto &[d, u]: cur) {
            for (const auto [w, v]: g[u]) {
                if (d + w > t) continue;
                nxt.eb(d + w, v); 
            }
        }
        cur.swap(nxt);
    }
    vec<int> ans(n);
    for (const auto [d, v]: cur) if (d >= s) {
        ans[v] = 1;
    }
    L(i,0,n) if(ans[i]) cout << i + 1 << " ";
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