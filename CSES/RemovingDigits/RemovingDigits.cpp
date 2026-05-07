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
    vec<int> dp(n + 1);
    const int oo = 1e9;
    L(i,1,n+1){
        dp[i] = oo;
        int x = i;
        while(x){
            int d = x % 10;
            x /= 10;
            dp[i] = min(dp[i], dp[i - d] + 1);
        }
    }
    cout << dp[n] << "\n";
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