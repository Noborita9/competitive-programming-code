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
    vec<ll> w(n+1), v(n + 1);
    L(i,0,n) cin >> w[i+1] >> v[i + 1];
    // dp[i]
    vec<vec<ll>> dp(n + 1, vec<ll>(m + 5));
    L(i,1,n+1){
        L(j,0,m+1){
            dp[i][j] = dp[i-1][j];
            if (w[i]<=j){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    vec<vec<ll>> dp2(n + 2, vec<ll>(m + 5));
    for (int i = n; i > 0; i --){
        L(j,0,m+1){
            dp2[i][j] = dp2[i+1][j];
            if (w[i]<=j){
                dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - w[i]] + v[i]);
            }
        }
    }
    ll mx = dp[n][m];
    L(i,1,n+1){
        ll tg = mx - v[i];
        bool pos = 0;
        ll nm = m - w[i];
        L(j,0,nm+1){
            pos = pos || (dp[i-1][j]+dp2[i+1][nm-j]==tg);
        }
        cout << (pos ? "Yes" : "No") << "\n";
    }
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