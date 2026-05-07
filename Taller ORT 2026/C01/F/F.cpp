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
    vec<pair<int,int>> songs;
    songs.reserve(n);
    map<string, int> ix;
    auto gix = [&](const string &s) -> int {
        if (ix[s]) return ix[s] - 1;
        int sz = SZ(ix);
        ix[s] = sz;
        return sz - 1;
    };
    auto add = [&](const string &g, const string &r) -> void {
        songs.eb(gix(g), gix(r));
    };
    L(i,0,n){
        string g, r; cin >> g >> r;
        add(g, r);
    }
    vec<vec<int>> g(n, vec<int>(n));
    L(i,0,n) {
        auto [gi, ri] = songs[i];
        L(j,i + 1, n){
            auto [gj, rj] = songs[j];
            if (gi == gj || ri == rj) {
                g[i][j] = g[j][i] = 1;
                // cout << i << " -> " << j << "\n";
            }
        }
    }
    int best = n - 1;
    int masks = 1<<n; // 0101 -> 0100 e ir al 4 o 0001 e ir al 2   
    vec<vec<int>> dp(masks, vec<int>(n)); // (2 ^ n) * n;
    L(i,0,n) dp[1<<i][i] = 1;
    L(mask, 0, masks) {
        L(bit, 0, n) if (mask & (1<<bit)) {
            int nmask = mask ^ (1<<bit); // I want to know if I come from there
            L(j,0,n) if (nmask & (1<<j) && g[bit][j]) {
                dp[mask][bit] |= dp[nmask][j];
            }
            if (dp[mask][bit]) best = min(best, n - __builtin_popcount(mask));
        }
    }
    
    
    cout << best << "\n";
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