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

const ll mod = 1e9 + 7;

inline ll modsum(ll a, ll b){a += b; if (a >= mod) return a - mod; return a;}


void solve()
{
    int n, m; cin >> n >> m;
    int masks = 1 << n;

    vec<vec<ll>> dp(m+2, vec<ll>(masks));
    dp[0][0] = 1;
    auto build = [&](auto && back, int c, int ix, int mask, int nmask) -> void {
        if (ix == n) {
            dp[c + 1][nmask] = modsum(dp[c + 1][nmask], dp[c][mask]);
            return;
        }
        if (mask & (1<<ix)) back(back, c, ix + 1, mask, nmask);
        else {
            back(back, c, ix + 1, mask, nmask | (1<<ix)); // make it horizontal
            if (ix + 1 < n && (mask & (1<<(ix+1)))==0) {
                back(back, c, ix + 2, mask, nmask);
            }
        }
    };
    L(c,0,m+1)
    {
        L(mask,0,masks) if (dp[c][mask]) // O(m * (2 ** n))
        {
            build(build, c, 0, mask, 0);
        }
    }
    // cout << m-1 << " " << bitset<4>(masks-1) << "\n";
    cout << dp[m][0] << "\n";
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