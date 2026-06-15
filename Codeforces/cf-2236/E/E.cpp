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
    vec<int> a(n);
    L(i,0,n) {cin >> a[i]; a[i] --;}

    vec<vec<bool>> dp(n, vec<bool>(n));

    L(i,0,n){
        vec<bool> seen(n);
        int mn = a[i];
        int mx = a[i];
        for (int j = i; j >= 0; j --){
            if (seen[a[j]]) break;
            seen[a[j]] = 1;
            mn = min(mn, a[j]);
            mx = max(mx, a[j]);
            // cout << i << ": " << j << " " << mn << " " << mx << "\n";
            if (mx - mn == i - j) {
                dp[mn][mx] = 1;
            }
        }
    }

    int ans = 0;
    L(len, 1, (n / 2) + 1){
        L(i,0,n){
            if (i + len - 1 >= n) break;
            if (dp[i][i + len - 1]) {
                int j = i + len;
                if (j + len - 1 >= n) break;
                if (dp[j][j + len - 1]) {
                    ans= len;
                    break;
                }
            }
        }
    }
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