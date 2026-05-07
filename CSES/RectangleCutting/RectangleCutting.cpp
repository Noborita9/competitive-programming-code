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
    int a, b; cin >> a >> b;
    const int oo = (int)1e9;
    vec<vec<int>> dp(a + 1, vec<int>(b + 1, oo));
    
    L(i,1,a+1) dp[i][1] = i - 1;
    L(i,1,b+1) dp[1][i] = i - 1;
    L(i,1,min(a,b)+1) dp[i][i] = 0;
    
    L(i,1,a+1){
        L(j,1,b+1) if (dp[i][j] == oo) {
            L(k,1, i) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
            L(k,1,j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    cout << dp[a][b] << '\n';
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