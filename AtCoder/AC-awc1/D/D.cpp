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
    int n, m, K; cin >> n >> m >> K;
    vec<ll> a(n + 1), b(n + 1);
    L(i,1,n + 1) cin >> a[i] >> b[i];
    const ll oo = (ll)1e18;
    vec<vec<ll>> dp(n + 1, vec<ll>(m + 1, -oo));
    ll ans = 0;
    L(i,1,n + 1)
    {
        L(j,0,m + 1)
        {
            if (j >= b[i]) {
                dp[i][j] = a[i];
                L(k,1,K+1) {
                    if (i - k <= 0) break;
                    if (dp[i - k][j - b[i]] != -oo && a[i] + dp[i - k][j - b[i]] > dp[i][j]) {
                        dp[i][j] = a[i] + dp[i - k][j - b[i]];
                    }
                }
                ans = max(ans, dp[i][j]);
            }
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