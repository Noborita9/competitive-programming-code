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
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    vec<vec<ll>> dp(n, vec<ll>(2));
    dp[0][0] = a[0];
    ll ans = dp[0][0];
    L(i,1,n){
        dp[i][0] = max(dp[i-1][0] + a[i], a[i]);
        ans = max(ans, dp[i][0]);
    }
    L(i,1, k + 1) {
        int cur = i % 2;
        int prev = 1 - cur;
        // cout << prev << " " << cur << endl;
        dp[0][cur] = dp[0][prev];
        ans = max(dp[0][cur], ans);
        L(j,1,n)
        {
            ll keep = max(a[j], dp[j-1][cur] + a[j]);
            ll del  = dp[j-1][prev];
            dp[j][cur] = max(keep, del);
            ans = max(dp[j][cur], ans);
        }
    }
    // L(i,0,n) cout << dp[i][k%2] << " ";
    // cout << "\n";
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