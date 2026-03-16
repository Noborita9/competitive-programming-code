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
    int n; ll t; cin >> n >> t;
    vec<ll> h(n), c(n); L(i,0,n) cin >> h[i]; L(i,0,n) cin >> c[i];
    ll sm = 0;
    L(i,0,n){
        if (h[i] <= t) sm += c[i];
    }
    cout << sm << "\n";
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