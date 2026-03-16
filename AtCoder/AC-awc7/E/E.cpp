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

struct pt {
    ll x, y;
};
void imp(pt a){
    cout << a.x <<" " << a.y << endl;
}
const int N = 17; // M=15 + begin + end

ll dist(pt l, pt r){
    return abs(l.x - r.x) + abs(l.y - r.y);
}

void solve()
{
    ll n; int m; cin >> n >> m;
    auto toPt = [&](ll t) {
        ll c = t % n;
        if (c == 0) c = n;
        ll r = (t - c)/n + 1;
        return pt{r, c};
    };
    ll s, t; cin >> s >> t;
    int ln = m + 2; // I need to consider the last point too and the first one?
    vec<pt> p(ln);
    p[0]=(toPt(s));
    p[1]=(toPt(t));
    L(i,0,m){
        ll x; cin >> x;
        p[i+2] = toPt(x);
    }
    const ll oo = (ll)1e18;
    const int bm = 1<<ln;
    vec<vec<ll>> dp(bm, vec<ll>(ln, oo));
    dp[1][0] = 0; // initial position 
    L(mask, 0, bm){
        if ((mask & 1) == 0) continue; // must contain beginning
        // cout << "Mask: " << bitset<5>(mask) << "\n";
        L(l, 0, ln) if (mask & (1<<l)) {
            int next_mask = mask ^ (1<<l);
        // cout << "NextMask: " << bitset<5>(next_mask) << "\n";
            L(r, 0, ln) if (next_mask & (1<<r)) {
                // I want to go yo my mask from that mask ending in l
                // cout << "Try: " << r << " -> " << l << " with " << (dp[next_mask][r] + dist(p[r], p[l])) << "\n";
                dp[mask][l] = min(dp[mask][l], dp[next_mask][r] + dist(p[r], p[l]));
            }
        }
    }
    // cout << bm << " -> " << bitset<5>(bm) << "\n";
    cout << dp[bm-1][1] << "\n"; // Ending Position
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