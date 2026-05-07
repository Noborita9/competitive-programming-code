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
    int n, x; cin >> n >> x;
    vec<int> c(n); L(i,0,n) cin >> c[i];
    vec<ll> dp(x + 1);
    dp[0] = 0;
    sort(ALL(c));
    L(i,1,x+1){
        dp[i] = MOD;
        for (int c_i: c) {
            if (i - c_i < 0) break;
            dp[i] = min(dp[i], dp[i - c_i] + 1);
        }
    }
    if (dp[x] == MOD) dp[x] = -1;
    cout << dp[x] << "\n";
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