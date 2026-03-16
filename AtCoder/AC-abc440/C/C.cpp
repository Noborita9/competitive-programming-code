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
    int n, w; cin >> n >> w;
    vec<ll> c(n);
    L(i,0,n) cin >> c[i];
    vec<ll> a(2 * w);
    L(i,0,n){
        a[i % (2 * w)] += c[i];
    }
    ll acc = 0;
    L(i,0,w) acc += a[i];
    ll ans = acc;
    // L(i,0,2 * w) cout << a[i] << " ";
    // cout << "\n";
    L(i,0,2 * w) {
        acc += a[(w + i) % (2 * w)] - a[i % (2 * w)];
        ans = min(ans, acc);
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