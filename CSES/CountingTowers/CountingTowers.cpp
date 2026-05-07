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

const ll mod = (ll)1e9 + 7ll;


void solve()
{
    int t; cin >> t;
    const int n = 1e6;
    vec<ll> dp(n + 1), dpi(n+1), dpj(n+1);
    dp[1] = 2;
    dpi[1] = 1;
    dpj[1] = 1;
    L(i,2,n+1){
        dpi[i] = (4*dpi[i-1]+dpj[i-1])%mod;
        dpj[i] = (2*dpj[i-1]+dpi[i-1])%mod;
        dp[i] = (dpi[i] + dpj[i])%mod;
    }

    L(i,0,t){
        int x; cin >> x;
        cout << dp[x] << '\n';
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