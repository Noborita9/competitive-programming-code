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

const ll mod = (ll)1e9 + 7ll;
const int N = 8010;
const int BLOCK_SIZE = 350;

inline ll modsum(ll a, ll b){
    a += b;
    if (a >= mod) return a - mod;
    if (a < 0) return a + mod;
    return a;
}
inline ll modmul(ll a, ll b){
    a *= b;
    if (a >= mod) a %= mod;
    return a;
}

ll c[N][N];

void solve()
{
    int n; cin >> n;
    vec<ll> b(n);
    L(i,0,n) cin >> b[i];
    int m; cin >> m;
    vec<vec<int>> g(n);
    L(i,0,m){
        int u, v; cin >> u >> v;
        u --; v--;
        g[u].pb(v);
    }

    L(i,0,n){
        L(j,0,n)c[i][j] = -1;
        auto calc = [&](auto && dfs, int u) -> void {
            if (c[i][u] != -1) return;
            c[i][u] = 0;
            for (int v: g[u]) {
                if (c[i][v] == -1) dfs(dfs, v);
                c[i][u] = modsum(c[i][u], c[i][v]);
            }
            if (u == i) c[i][u] = 1; 
        };
        L(j,0,n) if (c[i][j] == -1) calc(calc, j);
    }
    vec<int> topo;
    topo.reserve(n);
    vec<bool> vis(n);
    auto tps = [&](auto && dfs, int u) -> void {
        if (vis[u]) return;
        vis[u] = 1;
        for (int v: g[u]) if(!vis[v]) dfs(dfs, v);
        topo.pb(u);
    };
    L(i,0,n) if (!vis[i]) tps(tps, i);
    vec<ll> dp(n);
    vec<ll> base_b(ALL(b));

    vec<ll> delta(n);
    vec<int> is_changed(n);
    vec<int> changed;
    changed.reserve(BLOCK_SIZE);
    auto updateDP = [&]() -> void {
        for (int i: changed){
            base_b[i] = modsum(delta[i], base_b[i]);
            delta[i] = 0;
            is_changed[i] = 0;
        }
        changed.clear();
        L(i,0,n) dp[i] = base_b[i];
        L(i,0,n){
            int u = topo[i];
            for (int v: g[u]) {
                dp[u] = modsum(dp[u], dp[v]);
            }
        }
    };
    updateDP();
    ll ans = 0;
    int q; cin >> q;
    ll qc = 0;
    L(k, 1, q + 1){
        char op; cin >> op;
        if (op == 'Q'){
            int ix; cin >> ix;
            qc ++;
            ix --;
            ll val = dp[ix];
            for (int i: changed)  {
                val = modsum(val, modmul(delta[i], c[i][ix]));
            }
            ans = modsum(ans, modmul(qc, val));
        } else {
            int ix; ll v; cin >> ix >> v;
            ix --;
            delta[ix] = modsum(v ,- base_b[ix]);
            b[ix] = v;
            if (!is_changed[ix]) {
                changed.pb(ix);
                is_changed[ix] = 1;
            }
            if (SZ(changed) == BLOCK_SIZE) updateDP();
        }
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