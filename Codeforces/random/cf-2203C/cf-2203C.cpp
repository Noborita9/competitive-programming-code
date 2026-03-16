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
    ll s, m; cin >> s >> m;
    // ahora necesito poder simular el robo con un binaria, nadie mas de x
    auto balance = [&](ll t) -> bool {
        ll k = s;
        for (int bit = 61; bit >= 0; bit --){
            if (m & (1ll<<bit)) {
                ll times = min(k / (1ll<<bit), t);
                k -= times * (1ll<<bit);
            }
        }
        return k == 0;
    };
    ll ans = -1;
    ll lo = 0;
    ll hi = s;
    while (lo <= hi) {
        ll md = (lo + (hi - lo)/2ll);
        if (balance(md)){
            ans = md;
            hi = md - 1;
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
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}