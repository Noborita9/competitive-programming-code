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
    int W = 30 * (n + 1);
    vec<int> dp(W + 1);
    L(i,0,n){
        int p, w; cin >> p >> w;
        for (int j = W; j >= w; j --) {
            dp[j] = max(dp[j], dp[j - w] + p);
        }
    }
    int q; cin >> q;
    ll sm = 0;
    while(q--)
    {
        int x; cin >> x;
        sm += dp[min(W, x)];
    }
    cout << sm << "\n";
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