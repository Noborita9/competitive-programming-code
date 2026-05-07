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
    int n, m; cin >> n >> m;
    vec<int> a(n); L(i,0,n) cin >> a[i];
    vec<vec<ll>> dp(n, vec<ll>(m+1));
    if (a[0] == 0) {
        L(i,0,m+1)dp[0][i]=1;
    } else dp[0][a[0]] = 1;
    L(i,1,n){
        int x = a[i];
        if (x == 0) {
            L(j,1,m+1){
                for (auto k: {-1, 0, 1}) {
                    int d = j + k;
                    if (d >= 1 && d <= m) {
                        (dp[i][j] += dp[i - 1][d]) %= MOD;
                    }
                }
            }
        } else {
            for (auto k: {-1, 0, 1}) {
                int d = x + k;
                if (d >= 1 && d <= m) {
                    (dp[i][x] += dp[i - 1][d]) %= MOD;
                }
            }
        }
    }
    ll ans = 0;
    L(i,1,m+1) (ans += dp[n-1][i]) %= MOD;
    cout << ans << '\n';
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