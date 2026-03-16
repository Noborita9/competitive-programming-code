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
    int n, k; cin >> n >> k;
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    auto check = [&](ll t) -> bool {
        ll used = 0;
        ll load = 0;
        L(i,0,n) {
            load += a[i];
            if (load > t) {
                load = 0;
                used ++;
            } else if (load == t) {
                used ++;
                load = 0;
            }
        }
        // cout << "t: " << t << " => " << used << " " << load << "\n";
        return used >= k;
    };
    ll lo = 0;
    ll hi = accumulate(ALL(a), 0ll);
    ll ans = 0;
    while (lo <= hi){
        ll md = (lo + (hi - lo)/2ll);
        if (check(md)){
            ans = md;
            lo = md + 1;
        } else {
            hi = md - 1;
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