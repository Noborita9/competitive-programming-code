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
    string s, t; cin >> s >> t;
    ll n = SZ(s);
    ll m = SZ(t);
    ll tot = 0;
    vec<ll> dp(m + 1, 0);
    // dp[0] = 1;
    L(i,1,n + 1){
        dp[0] += 1;
        for (int j = m - 1; j >= 0; j --){
            if (s[i-1]==t[j]) {
                dp[j+1]+=dp[j]; // they all move up
                dp[j] = 0;
            }
        }
        // L(j,0,m) tot += dp[j];
        tot += accumulate(begin(dp), begin(dp) + m, 0ll);
    }
    cout << tot << "\n";
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