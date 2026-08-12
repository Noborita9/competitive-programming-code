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
    int r, c, n, m; cin >> r >> c >> n >> m;
    vec<ll> a(n), b(m);
    L(i,0,n) cin >> a[i];
    L(i,0,m) cin >> b[i];
    reverse(ALL(a));
    reverse(ALL(b));
    r = min(r, n);
    c = min(c, m);
    ll sma = accumulate(begin(a), begin(a) + r, 0LL);
    ll smb = accumulate(begin(b), begin(b) + c, 0LL);
    ll ans = max({sma, smb, sma + smb - b[c - 1], sma + smb - a[r - 1]});
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