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
    int n; ll w; cin >> n >> w;
    vec<ll> W(n);
    L(i,0,n) cin >> W[i];
    int masks = (1<<n);
    const ll oo = (ll)1e18;
    vec<pair<int, ll>> dp(masks, {30, oo});
    dp[0] = {1, 0ll};
    L(mask, 0, masks) {
        auto [p, k] = dp[mask];
        int cmask = ~mask;
        L(bit,0,n) if (cmask & (1<<bit)) {
            // could add this bit
            int np = p;
            int nk = k;
            nk += W[bit];
            if (nk > w) {
                nk = W[bit];
                np ++;
            }
            int nmask = mask | (1<<bit);
            dp[nmask] = min(dp[nmask], pair{np, (ll)nk});
        }
    }
    cout << dp[masks - 1].first << "\n";
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