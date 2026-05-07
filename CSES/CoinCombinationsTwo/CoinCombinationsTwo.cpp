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

const ll MOD = (ll)1e9 + 7ll;

void solve()
{
    int n, x; cin >> n >> x;
    vec<int> c(n); L(i,0,n) cin >> c[i];
    sort(ALL(c));
    vec<ll> dp(x + 1);
    dp[0] = 1;
    for (int k: c) {
        L(i,k,x+1){
            dp[i] += dp[i - k];
            if (dp[i] >= MOD) dp[i] -= MOD;
        }
    }
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