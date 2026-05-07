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
    int n, l, r; cin >> n >> l >> r;
    string s; cin >> s;
    vec<vec<int>> c(26);
    ll ans = 0;
    L(i,0,n) {
        int k = s[i] - 'a';
        c[k].pb(i);
        int lo = i - l;
        int hi = i - r;
        auto hit = lower_bound(ALL(c[k]), hi);
        auto bit = upper_bound(ALL(c[k]), lo);
        ans += (ll)(bit-hit);
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