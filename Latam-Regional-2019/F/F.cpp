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

const ll mod = (ll)1e9 + 7ll;

void solve()
{
    int S, B; cin >> S >> B;
    int K = B - S;
    if (K == 0){
        cout << "1\n";
        return;
    }
    vec<vec<ll>> dp(S + 1, vec<ll>(K + 1));
    vec<vec<ll>> sm(S + 1, vec<ll>(K + 1));
    vec<vec<ll>> ac(S + 1, vec<ll>(K + 1));
    for (int k = 1; k <= K; k ++){ // Blocks
        for (int i = 1; i <= S; i ++){ // Widht
            if (i == k){
                dp[i][k] = 1;
            } else if (k > i) {
                dp[i][k] = ac[i][k - i];
            }
            sm[i][k] = (sm[i - 1][k] + dp[i][k]) % mod;
            ac[i][k] = (ac[i - 1][k] + sm[i][k]) % mod;
        }
    }
    ll ans = 0;
    L(i,1,S + 1){
        ans += ((S - i + 1) * dp[i][K]) % mod;
        ans %= mod;
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