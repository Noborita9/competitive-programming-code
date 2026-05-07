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
    int n, x; cin >> n >> x;
    vec<int> h(n), s(n);
    L(i,0,n) cin >> h[i];
    L(i,0,n) cin >> s[i];
    vec<int> dp(x + 1);
    L(i,0,n){
        int w = h[i];
        int v = s[i];
        for (int j = x; j >= w; j --) dp[j] = max(dp[j], dp[j - w] + v);
    }
    cout << dp[x] << "\n";
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