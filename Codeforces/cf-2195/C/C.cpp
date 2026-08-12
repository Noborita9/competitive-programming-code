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
    vec<int> s(n + 1); L(i,0,n) cin >> s[i + 1];
    const  int oo = 1e9;
    vec<vec<int>> dp(n + 1, vec<int>(7, oo));
    L(i,0,7) dp[0][i] = 0;
    L(i,1,n + 1){
        L(j,1,7)
        {
            L(k,1,7) if (k != j && k != (7 - j)) {
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + (s[i] != j));
            }
        }
    }
    int ans = oo;
    L(i,0,7) ans = min(ans, dp[n][i]);
    cout << ans << "\n";
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