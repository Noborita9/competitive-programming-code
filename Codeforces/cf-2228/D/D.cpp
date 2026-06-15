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
    ll n; cin >> n;
    map<int,ll> x, y;

    vec<pair<ll,ll>> pts;
    L(i,0,n){
        int X, Y; cin >> X >> Y;
        x[Y] ++;
        x[Y] ++;
        pts.eb(X, Y);
    }
    ll ans = 0;
    for (auto [X, Y]: pts) {
        ll otherX = n - x[X];
        ll otherY = n - y[Y];
        ans += otherX + otherY;
    }
    cout << ans / 8 << "\n";
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