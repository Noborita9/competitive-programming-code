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
    vec<ll> a(n);
    L(i,0,n) cin >> a[i];
    ll mx = *max_element(ALL(a));
    ll mn = *min_element(ALL(a));
    if (mn >= 0) {
        cout << 2 * mx << "\n";
    } else if (mx <= 0) {
        cout << 2 * abs(mn) << "\n";
    } else {
        ll mxmn = 2 * mx + 2 * abs(mn);
        ll mnmx = 2 * abs(mn) + 2 * mx;
        cout << min(mxmn, mnmx) << "\n";
    }
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