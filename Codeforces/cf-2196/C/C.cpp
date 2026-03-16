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
    vec<ll> a(n), b(n);
    L(i,0,n) cin >> a[i] >> b[i];
    vec<ll> d(n); L(i,0,n) d[i] = a[i] - b[i];
    vec<int> ord(n); iota(ALL(ord), 0);
    sort(ALL(ord), [&](int l, int r){return d[l] > d[r];});
    ll ans = accumulate(ALL(a), 0ll);
    L(i,0,k) ans -= d[ord[i]];
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