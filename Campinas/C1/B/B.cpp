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
    vec<int> p(n), q(n), q_to_p(n);
    L(i,0,n) {cin >> p[i]; p[i]--;}
    L(i,0,n) {cin >> q[i]; q[i]--; q_to_p[q[i]] = p[i];}
    vec<vec<ll>> c(3, vec<ll>(n));
    L(j,0,3){
        L(i,0,n) {
            cin >> c[j][i];
        }
    }
    
    vec<vec<int>> cycs;
    vec<int> vis(n);
    L(i,0,n) if (!vis[i]) {
        int u = i;
        cycs.pb({});
        while(!vis[u]) {
            vis[u] = 1;
            cycs.back().pb(u);
            u = q_to_p[u];
        } 
    }
    ll ans = 0;
    auto cost = [&](int i, int prev, int next) {
        return c[(next) + (1 - prev)][i];
    };
    const ll oo = (ll)1e18;
    for (const auto &P: cycs){
        int ln = SZ(P);
        if (ln == 1) {
            ans += c[1][P[0]];
            continue;
        }
        auto eval = [&](int ldir) -> ll {
            vec<vec<ll>> dp(ln, vec<ll>(2, -oo));
            dp[0][0] = cost(P[0], ldir, 0);
            dp[0][1] = cost(P[0], ldir, 1);
            for (int i = 1; i < ln; i ++){
                L(j,0,2) if (dp[i-1][j] != -oo ) {
                    dp[i][0] = max(dp[i][0], dp[i - 1][j] + cost(P[i], j, 0));
                    dp[i][1] = max(dp[i][1], dp[i - 1][j] + cost(P[i], j, 1));
                }
            }
            return dp[ln - 1][ldir];
        };
        ans += max(eval(0), eval(1));
    }
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