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

using ii = pair<int,int>;
void solve()
{
    int n; cin >> n;
    vec<int> a(n); L(i,0,n) cin >> a[i];
    vec<ii> pts; pts.reserve(2 * n);
    L(i,0,n){
        // left
        int xl = i; // i - 1
        int yl = a[i] - (i + 1);
        if (xl >= 0 && yl >= 0) pts.eb(2 * xl + 1, yl * 2);
        // right
        int xr = a[i] + (i + 1) - n - 1;
        int yr = n - (i + 1);
        if (xr >= 0 && yr >= 0)  pts.eb(xr * 2, yr * 2 + 1);
    }
    if (pts.empty()) {
        cout << n << "\n";
        return;
    }
    sort(ALL(pts));
    vec<int> lis;
    for (auto [x, y]: pts) {
        // cout << x << " " << y << "\n";
        auto it = upper_bound(ALL(lis), y);
        if (it == end(lis)) lis.pb(y);
        else *it = y;
    }

    // for (int x: lis) cout << x << " "; cout << "\n";

    cout << n - SZ(lis) << "\n";
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