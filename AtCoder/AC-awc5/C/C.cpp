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
    int n; ll k; cin >> n >> k;
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    vec<ll> low(ALL(a));
    L(i,1,n) low[i] = max(a[i], low[i - 1] - k); // 
    for (int i = n - 2; i >= 0; i --) low[i] = max(low[i], low[i + 1] - k);
    ll ans = 0;
    L(i,0,n) ans += low[i] - a[i];
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