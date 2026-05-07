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
    vec<pair<int,int>> a(n);
    L(i,0,n) cin >> a[i].first;
    L(i,0,n) cin >> a[i].second;
    // L(i,0,n) cin >> a[i].first >> a[i].second;
    sort(ALL(a),[&](const pair<int,int> &lhs, const pair<int,int> & rhs) {
        return min(lhs.first,lhs.second) < min(rhs.first, rhs.second);
    });
    vec<vec<int>> dp(2, vec<int>(2));
    dp[0][0] = dp[1][1] = 1;
    L(i,1,n)
    {
        vec<vec<int>> ndp(2, vec<int>(2));
        if (a[i-1].first < a[i].first && a[i-1].second < a[i].second)
        {
            ndp[0][0] = dp[0][0];
            ndp[0][1] = dp[1][1];
            ndp[1][0] = dp[1][0];
            ndp[1][1] = dp[0][1];
        }
        if (a[i-1].second < a[i].first && a[i-1].first < a[i].second)
        {
            ndp[0][0] |= dp[0][1];
            ndp[0][1] |= dp[1][0];
            ndp[1][0] |= dp[1][1];
            ndp[1][1] |= dp[0][0];
        }
        dp.swap(ndp);
    }
    if (dp[0][0] || dp[0][1])
    {
        cout << "YES\n";
    } else cout << "NO\n";
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