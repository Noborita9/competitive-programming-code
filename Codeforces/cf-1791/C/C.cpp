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
    int n; cin >> n;
    vec<int> a(2 * n + 1);
    vec<int> f(n, -1), s(n, - 1);
    vec<ll> dp(2 * n + 1);
    L(i,1,2 * n + 1) {
        cin >> a[i];
        a[i] --;
        if (f[a[i]] != -1) s[a[i]] = i;
        else f[a[i]] = i;
    }
    // L(i,0,n) dp[f[a[i]]] = -oo; // can't take those
    L(i,1,2 * n + 1) {
        dp[i] = dp[i - 1] + 1;
        if (i == s[a[i]]) {
            ll dx = i - f[a[i]] + 1;
            dp[i] = max(dp[i], dp[f[a[i]] - 1] + dx*dx);
        }
    }
    // L(i,0,2*n + 1) cout << dp[i] << " ";
    // cout << "\n";
    cout << dp[2 * n] << "\n";
    
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