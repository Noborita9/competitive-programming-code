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
    vec<ll> a(n);
    L(i,0,n) cin >> a[i];
    vec<vec<int>> g(n);
    L(i, 1, n){
        int u, v; cin >> u >> v;
        u --; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    if (n == 2){
        cout << a[0]+a[1] << "\n";
        return;
    }
    vec<ll> d(n);
    vec<int> prev(n, - 1);
    auto cdist = [&](auto && dfs, int u, int p) -> void {
        for (int v: g[u]) if (v != p) {
            prev[v] = u;
            d[v] = d[u] + a[v];
            dfs(dfs, v, u);
        }
    };
    cdist(cdist, 0, -1);
    int l = max_element(ALL(d)) - begin(d);
    d[l] = 0; prev[l] = -1;
    cdist(cdist, l, - 1);
    int r = max_element(ALL(d)) - begin(d);
    vec<int> path;
    for (int x = r; x != -1; x = prev[x]) path.pb(x);
    reverse(ALL(path));
    int ln = SZ(path);
    // L(i,0,ln) cout << path[i] << " "; cout << "\n";
    vec<ll> mx(ln);
    mx[0] = a[l];
    mx[ln-1]= a[r];
    ll ans = 0;
    vec<ll> ddp(n), dhdp(n);
    L(i,1,ln-1){
        mx[i]=a[path[i]];
        auto croot = [&](auto &&dfs, int u, int p) -> ll {
            ll best = 0;
            for (int v: g[u]) if (v != p && v != path[i - 1] && v != path[i + 1]) {
                best = max(best, dfs(dfs, v, u));
            } 
            return a[u] + best;
        };
        mx[i] = croot(croot, path[i], -1);
        auto pwc = [&](auto && dfs, int u, int p) -> void {
            ll best = a[u];
            ll p1 = 0; ll p2 = 0;
            for (int v: g[u]) if (v != p) {
                dfs(dfs, v, u);
                ll h = dhdp[v];
                ddp[u] = max(ddp[u], ddp[v]);
                if (p2 < h) swap(p2, h);
                if (p1 < p2) swap(p1, p2);
            }
            dhdp[u] = p1 + a[u];
            ddp[u] = max(ddp[u], p1 + p2 + a[u]);
        };
        for (int v: g[path[i]]) if (v != path[i - 1] && v != path[i + 1]){
            // diameter here of component
            pwc(pwc, v, path[i]);
            ans = max(ans, d[r] + a[l] + ddp[v]);
        }
        // ans = max(ans, d[r] + mx[i] - a[path[i]] + a[l]);
    }
    vec<ll> dp(ln);
    dp[ln - 1] = a[r];
    // L(i,0,ln) cout << d[path[i]] << " "; cout << "\n";
    for (int i = ln - 2; i >= 0; i --) {
        dp[i] = max(dp[i + 1], d[r] - d[path[i]] + mx[i]);
    }
    // L(i,0,ln) cout << dp[i] << " "; cout << "\n";
    ll best = a[l];
    L(i, 0, ln) {
        best = max(best, a[l] + d[path[i]] + mx[i] - a[path[i]]);
        // cout << best << " " << dp[i + 1] << "\n";
        if (i + 1 >= ln) ans = max(ans, best);
        else ans = max(ans, best + dp[i + 1]);
    }
    cout << ans << "\n";
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