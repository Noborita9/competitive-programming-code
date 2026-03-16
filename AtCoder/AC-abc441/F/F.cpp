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

const int N = 1005;
const int M = 5e4 + 10;
ll dp[N][M], dp2[N][M];

void solve()
{
    int n, m; cin >> n >> m;
    vec<int> p(n + 1); vec<ll> v(n + 1);
    L(i,0,n) cin >> p[i + 1] >> v[i + 1];
    L(i,1,n + 1){
        L(j,0,m + 1){
            dp[i][j] = dp[i - 1][j];
            if (p[i] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - p[i]] + v[i]);
            }
        }
    }
    ll x = dp[n][m];
    for (int i = n; i >= 1; i --){
        L(j,0,m + 1) {
            dp2[i][j] = dp2[i + 1][j];
            if (p[i] <= j) {
                dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - p[i]] + v[i]);
            }
        }
    }
    L(i,1,n + 1){
        ll bestWithout = 0;
        ll bestUsing = 0;
        L(j,0,m + 1){
            bestWithout = max(bestWithout, dp[i - 1][j] + dp2[i + 1][m - j]);
            if (m - p[i] - j >= 0){
                bestUsing = max(bestUsing, dp[i - 1][j] + dp2[i + 1][m - p[i] - j]);
            }
        }
        if (bestWithout == x) {
            // Does not need to appear
            if (bestUsing == x - v[i]) {
                // But It can be used
                cout << "B";
            } else {
                cout << "C";
            }
        } else {
            if (bestUsing == x - v[i]) {
                cout << "A";
            } else {
                cout << "C";
            }
        }
    }
    cout << "\n";
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