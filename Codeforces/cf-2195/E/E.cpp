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

const ll mod =(ll)1e9+7LL;
inline ll modsum(ll a, ll b) {
    a += b;
    if (a>=mod) a-= mod;
    return a;
}

void solve()
{
    int n; cin >> n;
    vec<vec<int>> g(n + 1);
    int ln = n + 1;
    g[0].pb(1);
    L(i,1,ln) {
        int l, r; cin >> l >> r;
        if (l != 0) g[i].pb(l);
        if (r != 0) g[i].pb(r);
    }
    // cout << "Read" << endl;
    vec<int> sz(ln);
    vec<ll> dpu(ln, 1LL);
    auto szdfs = [&](auto && dfs, int u) -> void {
        sz[u] = 1;
        for (int v: g[u]) {
            dfs(dfs, v);
            sz[u] += sz[v];
            dpu[u] = modsum(dpu[u], modsum(1LL, dpu[v]));
        }
    };
    // cout << "PREDFS "<<endl;
    szdfs(szdfs, 0);
    dpu[0] = 0;
    // cout << "POST DFS "<<endl;
    // L(i,0,ln) cout << dpu[i] << " "; cout << "\n";
    vec<ll> ans(ln);
    auto go = [&](auto && dfs, int u, ll acc) -> void {
        ans[u] = modsum(acc, dpu[u]);
        for (int v: g[u]) {
            dfs(dfs, v, ans[u]);
        }
    };  
    go(go, 0, 0LL);
    L(i,1,ln) cout << ans [i] << " ";
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