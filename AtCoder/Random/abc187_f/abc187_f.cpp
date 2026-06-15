
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
    int n, m; cin >> n >> m;
    vec<vec<int>> g(n, vec<int>(n));

    L(i,0,m){
        int u, v; cin >> u >> v;
        u --; v--;
        g[u][v] = g[v][u] = 1;
    }
    int masks = 1 << n;
    const int oo = 1e9;
    vec<int> dp(masks, oo);
    dp[0] = 0;
    L(mask, 0, masks) {
        bool pos = 1;
        int msk = mask;
        while (pos && msk) {
            int lso = (msk & -(msk));
            int y = __builtin_ctz(lso);
            msk -= lso;
            int sbmasks = msk;
            while(pos && sbmasks){
                int lsox = (sbmasks & -(sbmasks));
                int x = __builtin_ctz(lsox);
                // cout << y << " " << x << endl;
                sbmasks -= lsox;
                pos = pos && g[x][y];
            }
        }
        if (pos) {
            dp[mask] = 1;
            continue;
        }
        for (int nmask = mask; nmask; nmask = (nmask - 1) & mask) {
            int cmask = mask ^ nmask;
            dp[mask] = min(dp[mask], dp[nmask] + dp[cmask]);
        }
    }
    cout << dp[masks - 1] << "\n";
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