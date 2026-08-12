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
    int n; ll x; cin >> n >> x;
    map<ll, ll> h;
    ll ans = 0;
    ll acc = 0;
    h[0] = 1;
    L(i,0,n)
    {
        ll d; cin >> d;
        acc += d;
        ans += h[acc - x];
        h[acc] ++;
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