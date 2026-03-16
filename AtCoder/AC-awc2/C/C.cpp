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
    int n; ll m; cin >> n >> m;
    vec<ll> a(n), b(n);
    L(i,0,n) cin >> a[i] >> b[i];
    auto check = [&](ll t) -> bool {
        L(i,0,n) if (a[i]+t*b[i] < m) return false;
        return true;
    };
    ll lo = 0;
    ll hi = m;
    ll ans = 0;
    while (lo <= hi){
        ll md = (lo + (hi - lo)/2ll);
        if (check(md)) {
            hi = md - 1;
            ans = md;
        } else {
            lo = md + 1;
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