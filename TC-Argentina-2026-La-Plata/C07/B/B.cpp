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
    L(i,1,n) {
        int p; cin >> p;
        p --;
        g[p].pb(i);
    }
    vec<int> depth(n);
    const int oo = 1e9;
    vec<int> dp(n), mindep(n, oo), rep(n);
    auto go = [&](auto && dfs, int u) -> void {
        if (g[u].empty()) dp[u] = 1, rep[u] = 1, mindep[u] = depth[u];
        for (int v: g[u]){
            depth[v] = depth[u] + 1;
            dfs(dfs, v);
            mindep[u] = min(mindep[u], mindep[v]);
            int PreCommit = dp[u];
            int Commit = rep[u] + dp[v];
            if (mindep[v] - depth[u] <= k) {
                rep[u] += rep[v]; // all of this is free
                PreCommit += rep[v];
            }
            int NoCommit = rep[u];
            dp[u] = max({dp[u], PreCommit, NoCommit, Commit});
        }
    };
    
    go(go, 0);

    cout << max(dp[0], rep[0]) << "\n";
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