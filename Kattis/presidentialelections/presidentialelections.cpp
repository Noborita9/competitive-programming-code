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
    vec<ii> ps;
    ll gn = 0;
    ll dsm = 0;
    ll totD = 0;
    L(i,0,n){
        ll d, f, c, v; cin >> d >> f >> c >> v;
        totD += d;
        if (f + v > c) { // I have a change
            ll diff = f + v + c; // whole 
            ll dt = (diff/2 + 1) - f;
            if (dt > 0) {
                dsm += d;
                ps.eb(d, dt);
            } else if (dt <= 0) {
                gn += d;
            }
        }
    }
    n = SZ(ps);
    const ll oo = 1e18;
    vec<ll> dp(dsm + 1, oo);
    dp[0] = 0;
    for (auto [v, w]: ps) {
        for (int j = dsm; j >= v; j --){
            dp[j] = min(dp[j], dp[j - v] + w);
        }
    }
    ll ans = oo;
    L(i,0,dsm + 1) if (dp[i] != oo && gn + i > totD/2) ans = min(ans, dp[i]);
    if (ans == oo){
        cout << "impossible\n";
    } else {
        cout << ans << "\n";
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