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
    int n, q; cin >> n >> q;
    vec<ll> a(n), b(n);
    L(i,0,n) cin >> a[i];
    L(i,0,n) cin >> b[i];
    for (int i = n - 1; i >=0; i --){
        a[i] = max({a[i], b[i], (i + 1) < n ? a[i + 1] : 0});
    }
    L(i,1,n) a[i] += a[i - 1];
    L(i,0,q){
        int l, r; cin >> l >> r;
        l --; r --;
        ll ans = a[r];
        if (l > 0) ans -= a[l - 1];
        cout << ans << " ";
    }
    cout << "\n";
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