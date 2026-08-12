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
    int n; ll k; cin >> n >> k;
    vec<int> b(n + 1);
    vec<int> a(n); L(i,0,n){cin >> a[i]; b[a[i]] = i + 1;}
    b[n] = 0;
    vec<int> o(n + 1);
    int it = 0;

    L(i,1,n){
        if (b[a[i - 1] + 1] > b[a[i] + 1]) it ++;
        o[i] = it;
    }
    if (it >= k) {
        cout << "0\n";
        return;
    }
    // L(i,0,n) cout << o[i] << " ";
    // cout << "\n";
    vec<vec<ll>> dp(n + 1, vec<ll>(k + 2, 0));
    k -= it;
    L(i,0,k) dp[n][i] = 1;
    o[n] = o[n - 1];
    const ll mod = 998244353;
    for (int i = n - 1; i >= 0; i --)
    {
        for (int j = k - 1; j >= 0; j --){
            dp[i][j] += dp[i][j + 1];
            dp[i][j] %= mod;
            dp[i][j] += dp[i + 1][j];
            dp[i][j] %= mod;
        }
        // for (int j = o[i]; j < k; j ++) {
            
        //     for (int p = j; p < k; p ++){
        //     }
        // }
    }
    // for (int i = k - 1; i >= 0; i --){
    //     L(j,0,n){
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << "\n";
    // }
    ll ans = dp[0][0];
    // L(i,0,k){
    //     ans += dp[0][i];
    //     ans %= mod;
    // }
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