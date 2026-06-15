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

using ii = pair<ll, ll>;

void solve()
{
    int n; cin >> n;
    ll s_x, s_y, e_x, e_y; cin >> s_x >> s_y >> e_x >> e_y;
    if (n == 0){
        cout << "0\n";
        return;
    }
    vec<ii> pts; pts.reserve(n);
    L(i,0,n){
        int x, y; cin >> x >> y;
        pts.eb(x, y);
    }
    if (e_x < s_x) {
        swap(e_x, s_x);
        swap(e_y, s_y);
    }
    if (e_y < s_y) {
        for (auto &[x, y]: pts) {
            // y rotation
            ll delta = y - s_y;
            y = s_y - delta;
        }
        e_y = s_y - (e_y - s_y);
    }
    vec<ii> fpts; fpts.reserve(n);
    for (auto [x, y]: pts) {
        if (x >= s_x && x <= e_x && y >= s_y && y <= e_y) {
            fpts.eb(x, y);
            // cout << x << " " << y << "\n";
        }
    }
    sort(ALL(fpts));
    vec<ll> lnds;
    for (auto [x, y]: fpts){ 
        auto it = upper_bound(ALL(lnds), y);
        if (it == end(lnds)) lnds.pb(y);
        else *it = y;
    }
    cout << SZ(lnds) << "\n";
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