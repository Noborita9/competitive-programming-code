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
    string s, t; cin >> s >> t;
    int n = SZ(s);
    int m = SZ(t);
    vec<vec<int>>  dp(n + 1, vec<int>(m + 1));
    vec<int> ps(n + 1), pt(m + 1);
    L(i,0,n) ps[i + 1] = (ps[i] + (s[i] - '0')) % 10;
    L(i,0,m) pt[i + 1] = (pt[i] + (t[i] - '0')) % 10;
    if (ps[n] != pt[m]) {
        cout << "-1\n";
        return;
    }
    L(i,1,n + 1)
    {
        L(j,1,m + 1)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (ps[i - 1] == pt[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][ j - 1] + 1);
        }
    }
    cout << dp[n][m] << "\n";
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