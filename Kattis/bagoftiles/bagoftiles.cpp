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

ll c[50][50];

void solve()
{
    int n, m, t; cin >> m;
    vec<int> x(m);
    L(i,0,m) cin >> x[i];
    cin >> n >> t;
    vec<vec<ll>> dp(n + 1, vec<ll>(t + 1));
    dp[0][0] = 1;
    for (int xi: x) {
        if (xi == 0) continue;
        for (int ci = n; ci >= 1; ci --){
            for (int p = t; p >= xi; p --){
                dp[ci][p] += dp[ci - 1][p - xi];
            }
        }
    }
    ll a = dp[n][t];
    ll b = c[m][n] - dp[n][t];

    cout << a << " : " << b <<"\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);

    c[0][0] = 1;
    L(i,1,31) {
        c[i][0] = 1;
        L(j,1,i + 1) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    // L(i,0,31){
    //     L(j,0,31){
    //         cout << c[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    int TT = 1;
    cin >> TT;
    L(t,1,TT + 1)
    {
        cout << "Game " << t << " -- ";
        solve();
    }
}