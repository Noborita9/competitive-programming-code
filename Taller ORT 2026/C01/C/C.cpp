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
    ll h; cin >> h;
    vec<ll> a(n);
    L(i,0,n) cin >> a[i];
    sort(ALL(a), greater<>());
    ll mx = a[0];
    ll mn = a[1];
    ll sm = mx + mn;
    ll times = h / sm;
    ll ops = times * 2;
    h -= times * sm;
    if (h > 0) ops ++, h -= mx;
    if (h > 0) ops ++;
    cout << ops << "\n";
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