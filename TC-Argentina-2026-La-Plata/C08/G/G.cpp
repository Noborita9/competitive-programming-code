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
    vec<vec<int>> g(n);
    L(i,1,n){
        int u, v; cin >> u >> v;
        u --; v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    vec<int> dp(n);
    int ans = 1;
    auto go = [&](auto &&dfs, int u, int p) -> void {
        int mx1 = 0, mx2 = 0;
        int ch = 0;
        for (int v: g[u]) if (v != p) {
            ch ++;
            dfs(dfs, v, u);
            int mx3 = dp[v];
            if (mx3 > mx2) swap(mx3, mx2);
            if (mx2 > mx1) swap(mx2, mx1);
        }
        dp[u] = 1 + ch;
        if (mx1) dp[u] += mx1 - 1;
        ans = max(ans, dp[u]);
        int midPoint = mx1 + mx2 + ch + 1 + (p != -1);
        if (mx1) midPoint --;
        if (mx2) midPoint --;
        ans = max(ans, midPoint);
    };

    go(go, 0, -1);
    
    cout << ans << "\n";
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