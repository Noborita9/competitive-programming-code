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
    int n, m; cin >> n >> m;
    vec<ll> c(m);
    L(i,0,m) cin >> c[i];
    ll sm = 0;
    L(i,0,n){
        int t; ll mx; cin >> t >> mx;
        t --;
        sm += min(mx, c[t]);
        c[t] -= min(mx, c[t]);
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