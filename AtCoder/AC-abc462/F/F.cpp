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
    string s; cin >> s;
    int n = SZ(s);
    int k; cin >> k;
    const int oo = 1e9;
    vec<vec<int>> dp(n + 1, vec<int>(k + 1, oo));
    L(i,0,n + 1)dp[i][0] = 0; // Default array does not increase anything
    L(i,3,n + 1){
        int ops = s[i - 1] != 'C';
        ops += s[i - 2] != 'B';
        ops += s[i - 3] != 'A';
        L(ki, 1, k + 1) {
            dp[i][ki] = dp[i - 1][ki];
            if (s[i - 1] == 'C' && s[i - 2] == 'B' && s[i - 3] == 'A') {
                continue; // We could never increase it here
            }
            dp[i][ki] = min(dp[i][ki], dp[i - 3][ki - 1] + ops);
        }
    }
    L(ki,0,k+1){
        L(i,0,n+1){
            cout << dp[i][ki] << " ";
        }
        cout << "\n";
    }

    if (dp[n][k] == oo) dp[n][k] = -1;
    cout << dp[n][k] << "\n";
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
