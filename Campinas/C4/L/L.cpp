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

const int K = 5000;

void solve()
{
    int n; cin >> n;
    vec<ll> a(n), b(n);
    L(i,0,n) cin >> a[i];
    L(i,0,n) cin >> b[i];
    const ll oo = (ll)1e18;
    vec<ll> dp(K + 1, -oo); 
    dp[0] = 0;
    ll ans = 0;
    L(i,0,n){
        vec<ll> ndp(K + 1, -oo);
        L(j,0,K + 1) {
            if (i + j >= n) break;
            if (dp[j] == -oo) continue;
            ndp[j] = dp[j] + a[i+j]*b[i];
        }
        L(j,0,K) {
            if (i + j + 1 >= n) break;
            if (ndp[j] == -oo) continue;
            ndp[j + 1] = max(ndp[j + 1], ndp[j] - (a[i + j] * b[i]) + (a[i + j + 1] * b[i]));
        }
        dp = move(ndp);
        L(j,0,K+1)ans=max(ans,dp[j]);
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