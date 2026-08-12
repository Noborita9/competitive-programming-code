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
    int n; cin >> n;
    vec<vec<int>> g(n + 1);
    L(i,1,n) {
        int u, v; cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }
    g[0].eb(1);
    vec<int> euler; euler.reserve(n);
    vec<int> par(n + 1);
    auto go = [&](auto && dfs, int u, int p = -1) -> void {
        for (int v: g[u]) if (v != p) {
            par[v] = u;
            dfs(dfs, v, u);
        }
        euler.eb(u);
    };
    go(go, 0, -1);
    vec<int> ans(n + 1, 1);
    vec<int> dp(n + 2), mx1(n + 2), mx2(n + 2);
    auto eval = [&](int k) -> int {
        if (k == 1) return n;
        int paths = 0;
        L(i,0,n+1) mx1[i] = mx2[i] = 0;

        L(i,0,n){
            int u = euler[i];
            if (mx1[u] + mx2[u] >= k - 1) {
                paths ++;
                dp[u] = 0;
            } else dp[u] = mx1[u] + 1;
            if (dp[u] > mx1[par[u]]) {
                mx2[par[u]] = mx1[par[u]];
                mx1[par[u]] = dp[u];
            } else if (dp[u] > mx2[par[u]]) mx2[par[u]] = dp[u];
        }
        return paths;
    };
    
    auto dac = [&](auto && rec, int l, int r, int ansl, int ansr) -> void {
        if (ansl == ansr) {
            for (int x = l; x <= r; x ++) ans[x] = ansl;
            return;
        }
        if (l > r) return;
        int md = (l + r) / 2;
        int ansmd = eval(md);
        ans[md] = ansmd;
        rec(rec, l, md - 1, ansl, ansmd);
        rec(rec, md + 1, r, ansmd, ansr);
    };
    dac(dac, 1, n, n, eval(n));
    L(i,1,n+1) cout << ans[i] << "\n";
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