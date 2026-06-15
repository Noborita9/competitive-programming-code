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
    vec<pair<ll, ll>> pts; pts.reserve(n);
    L(i,0,n){
        ll x, t; cin >> t >> x;
        pts.eb(t - x, t + x);
    }
    sort(ALL(pts));
    vec<int> lds;
        for (auto [u, v]: pts) {
        auto it = lower_bound(ALL(lds), -v);
        if (it == end(lds)) lds.pb(-v);
        else *it = -v;
    }
    // cout << "\n";
    cout << SZ(lds) << "\n";
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