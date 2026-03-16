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
    int n, k; cin >> n >> k;
    vec<vec<int>> g(n);
    L(i,1,n){
        int u, v; cin >> u >> v;
        u --; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vec<ll> c(k);
    ll c1 = 0, c2 = 0, v1, v2;
    map<ll, ll> M;
    L(i,0,k) {
        cin >> c[i];
        M[c[i]] ++;
    }
    auto it = begin(M);
    v1 = it->first;
    c1 = it->second;
    it = next(it);
    v2 = it->first;
    c2 = it->second;

    // cout << c1 << " " << v1 << "\n";
    // cout << c2 << " " << v2 << "\n";

    vec<int> par(n, - 1);
    vec<vec<ll>> dp(n, vec<ll>(2));
    vec<ll> diff(n);
    auto gdep = [&](auto && dfs, int u) -> void {
        int child = 0;
        dp[u][0] = v1;
        dp[u][1] = v2;
        vec<ll> cdiff;
        for (int v: g[u]) if (par[u] != v) {
            par[v] = u;
            child ++;
            dfs(dfs, v);
            cdiff.pb(diff[v]);
            dp[u][0] += dp[v][1];
            dp[u][1] += dp[v][1];
        }

        sort(ALL(cdiff));
        // cout << child << endl;
        if (child <= c1 - 1){
            L(i, 0, (ll)child){
                if (cdiff[i] >= 0) break;
                dp[u][0] += cdiff[i];
            }    
        } else {
            L(i, 0, c1 - 1){
            // if (cdiff[i] >= 0) break;
                dp[u][0] += cdiff[i];
            }
        }
        if (child <= c1) {
            L(i, 0, (ll)child){
                if (cdiff[i] >= 0) break;
                dp[u][1] += cdiff[i];
            }
        } else {
            L(i, 0, (ll)c1){
                // if (cdiff[i] >= 0) break;
                dp[u][1] += cdiff[i];
            }
        }
        
        diff[u] = dp[u][0] - dp[u][1];
    };
    gdep(gdep, 0);
    // int mx = *max_element(ALL(depth));
    cout << min(dp[0][0], dp[0][1]) << "\n";
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