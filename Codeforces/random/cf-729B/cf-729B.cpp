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
    vec<vec<int>> a(n, vec<int>(m));
    L(i,0,n) L(j,0,m) cin >> a[i][j];
    ll ans = 0;
    L(i,0,n) {
        bool pl = 0;
        L(j,0,m){
            if (!a[i][j] && pl) ans ++;
            pl = pl || a[i][j];
        }
        bool pr = 0;
        for (int j = m - 1; j >= 0; j --){
            if (!a[i][j] && pr) ans ++;
            pr = pr || a[i][j];
        }
    }
    L(j,0,m){
        bool dl = 0;
        L(i,0,n){
            if (!a[i][j] && dl) ans ++;
            dl = dl || a[i][j];
        }
        bool dr = 0;
        for (int i = n - 1; i >= 0; i --) {
            if (!a[i][j] && dr) ans ++;
            dr = dr || a[i][j];
        }
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