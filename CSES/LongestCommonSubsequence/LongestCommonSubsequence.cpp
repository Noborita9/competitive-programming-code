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
    int n, m; cin >> n >> m;
    vec<int> a(n), b(m);
    L(i,0,n) cin >> a[i];
    L(i,0,m) cin >> b[i];
    vec<vec<int>> dp(n + 1, vec<int>(m + 1));
    L(i,1,n+1){
        L(j,1,m+1){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (a[i-1]==b[j-1]) dp[i][j]=max(dp[i][j], dp[i-1][j-1]+1);
        }
    }
    cout << dp[n][m] << "\n";
    int i = n;
    int j = m;
    vec<int> st;
    while (i > 0 && j > 0) {
        if (dp[i][j] == 0) break;
        if (dp[i][j] == dp[i][j-1]) j --;
        else if (dp[i][j] == dp[i-1][j]) i --;
        else {
            st.pb(a[i-1]);
            i--;
            j--;
        }
    }
    reverse(ALL(st));
    for (int e: st) cout << e << " ";
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