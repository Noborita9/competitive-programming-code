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

const ll MOD = (ll)1e9 + 7;


void solve()
{
    int S, B; cin >> S >> B;
    int K = B - S;
    vec<vec<ll>> dp(S + 1, vec<ll>(K + 1, - 1));
    auto calc = [&](auto && rec, int s, int k) -> ll {
        if (s < 0) return 0;
        if (s == 0) return k == 0;
        if (k == 0) return 1;
        if (dp[s][k] != -1) return dp[s][k];
        dp[s][k] = 1; 
        for (int d = 2; d <= k; d ++){
            dp[s][k] += (rec(rec, s - d + 1, k / d) * rec(rec, s - d, k % d) % MOD);
            dp[s][k] %= MOD;
        }
        return dp[s][k];
    };
    ll ans = 0;
    for (int s = 0; s <= S; s ++){
        for (int k = K; k >= K - k; k --){
            ans += calc(calc, s, k) * calc(calc, S - s, K - k) % MOD;
            ans %= MOD;
        }
    }
    cout << ans << "\n";
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