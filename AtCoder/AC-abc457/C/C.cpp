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
    vec<vec<ll>> a(n);
    L(i,0,n){
        int m; cin >> m;
        a[i] = vec<ll>(m);
        L(j,0,m) cin >> a[i][j];
    }
    vec<ll> c(n);
    L(i,0,n) cin >> c[i];
    L(i,0,n){
        ll ci = c[i] * (ll)SZ(a[i]);
        if (ci < k) {
            k -= ci;
        } else {
            // it's on a[i]
            k --;
            k %= (ll)SZ(a[i]);
            cout << a[i][k] << "\n";
            break;
        }
    }    
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