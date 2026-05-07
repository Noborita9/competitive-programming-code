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

const ll MOD = (ll)1e9 + 7;


void solve()
{
    int n; cin >> n;
    vec<ll> dp(n + 1);
    dp[0] = 1;
    L(i,1,n+1){
        L(j,1,7) if (i - j >= 0) {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }
    cout << dp[n];
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