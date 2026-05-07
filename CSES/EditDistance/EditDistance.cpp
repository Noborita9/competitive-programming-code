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
    string a, b; cin >> a >> b;
    int n = SZ(a);
    int m = SZ(b);
    vec<vec<int>> dp(n + 1, vec<int>(m + 1));
    L(i,0,n) dp[i+1][0] = i+1;
    L(i,0,m) dp[0][i+1] = i+1;
    L(i,1, n + 1){
        L(j,1, m + 1){
            dp[i][j] = min({dp[i][j - 1], dp[i - 1][j - 1], dp[i-1][j]}) + 1; // 
            if (a[i - 1] == b[j - 1]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        }
    }
    // L(i,0,n+1){
    //     L(j,0,m+1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[n][m] << '\n';
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