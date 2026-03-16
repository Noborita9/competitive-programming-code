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
    vec<ll> a(n);
    vec<ll> b(n);
    L(i,0,n) cin >> a[i];
    L(i,0,n) cin >> b[i];
    sort(ALL(a));
    L(i, 1, n) b[i] += b[i - 1];
    ll bs = 0;
    L(i,0,n) {
        // cout << b[i] << " ";
        ll rem = n - i;
        auto it = upper_bound(ALL(b), rem);
        bs = max(bs, a[i] * (ll)(it - begin(b)));
    }
    // cout << "\n";
    cout << bs << "\n";
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