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
    vec<int> raw; raw.reserve(2 * n);
    vec<int> a(n), b(n); vec<ll> p(n);
    L(i,0,n) {
        cin >> a[i] >> b[i] >> p[i];
        raw.pb(a[i]);
        raw.pb(b[i]);
    }
    raw.pb(0);
    sort(ALL(raw));
    raw.erase(unique(ALL(raw)),end(raw));
    auto idx = [&](int x){return lower_bound(ALL(raw), x) - begin(raw);};
    vec<vec<pair<int, ll>>> from(SZ(raw));
    L(i,0,n) from[idx(b[i])].eb(idx(a[i]), p[i]);
    vec<ll> dp(SZ(raw));
    L(i,1,SZ(raw)){
        dp[i] = dp[i - 1];
        for (auto &[v, pi]: from[i]) {
            dp[i] = max(dp[i], dp[v - 1] + pi);
        }
    }
    cout << dp.back() << "\n";

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