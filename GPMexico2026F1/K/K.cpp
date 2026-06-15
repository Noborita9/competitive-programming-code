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

using iii = tuple<ll, ll, ll>;

void solve()
{
    int n; cin >> n;
    ll px, py; cin >> px >> py;
    vec<iii> circles; circles.reserve(n);
    L(i,0,n){
        ll x, y, r; cin >> x >> y >> r;
        circles.eb(x, y, r * r);
    }
    ll lo = 0; ld hi = (ll)1e18;
    ll ans = hi;
    while (lo <= hi) {
        ll md = (lo + hi) / 2;
        if (check(md)) {
            ans = md
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