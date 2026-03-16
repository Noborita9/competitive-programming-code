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
    int n, k, m; cin >> n >> k >> m;
    ll sm = 0;
    vec<ll> e, ne;
    L(i,0,n){
        int is; ll x; cin >> is >> x;
        if (is) e.pb(x);
        else ne.pb(x);
    }

    if (k - m > SZ(ne) || m > SZ(e)){
        cout << "-1\n";
        return;
    }
    
    sort(ALL(e),greater<ll>());
    sort(ALL(ne),greater<ll>());
    L(i,0,k - m) sm += ne[i];
    L(i,0,m) sm += e[i];
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