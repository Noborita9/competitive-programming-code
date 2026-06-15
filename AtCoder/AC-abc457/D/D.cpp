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
    int n; ll k; cin >> n >> k;
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    auto check = [&](ll t) -> bool {
        ll ops = 0;
        L(i,0,n) {
            if (a[i] >= t) continue;
            ll df = t - a[i];
            ll ix = i + 1;
            ll nops = (df + ix - 1) / ix;
            if (ops> k - nops) {
                return false;
            }
            ops += nops;
        }

        return ops <= k;

    }; // check if min(ALL(a)) >= t
    ll lo = 1;
    ll hi = (ll)2e18;
    ll ans = 1;
    while (lo <= hi) {
        ll m = lo + (hi - lo)/2ll;
        if (check(m)){
            ans = m;
            lo = m + 1;
        } else {
            hi = m - 1;
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