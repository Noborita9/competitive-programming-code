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
    int ans = 0;

    vec<vec<int>> dp(n+1, vec<int>(n+1, -1));
    auto ask = [&](int i, int j) -> bool {
        if (i == j) return dp[i][j] = 1;
        if (dp[i][j] != -1) return dp[i][j];
        cout << "? " << i << " " << j << endl;
        string A; cin >> A;
        return (dp[i][j] = (int)(A == "Yes"));
    };
    int i = 1;
    int j = 2;
    while(i <= n) {
        while (j <= n && ask(i, j)) j++;
        ans += j - i - 1;
        i ++;
    }

    cout << "! " << ans << endl;
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