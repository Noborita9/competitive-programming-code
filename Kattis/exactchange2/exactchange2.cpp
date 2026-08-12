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
    int v; cin >> v;
    int n; cin >> n;
    vec<int> c(n); L(i,0,n) cin >> c[i];
    int maxV = 20000;
    const int oo = 1e9;
    vec<int> dp(maxV + 1, oo);
    dp[0] = 0;
    sort(ALL(c));
    for (int ci: c) {
        for (int p = maxV; p >= ci; p --){
            dp[p] = min(dp[p], dp[p - ci] + 1);
        }
    }
    L(i,v,maxV + 1) if (dp[i] != oo){
        cout  << i << " " << dp[i] << "\n";
        break;
    }
    
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