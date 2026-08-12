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
using ii = pair<ll, ll>;

void solve()
{
    int n; ll m; cin >> n >> m;
    vec<ll> c(n), w(n);
    L(i,0,n) cin >> c[i];
    L(i,0,n) cin >> w[i];
    set<ii> S;
    vec<ll> a(n);
    vec<ll> b(n);
    ll dis = 0;
    L(i,0,n)
    {
        // cout << i << endl << "\n";
        ll t = c[i] / 100;
        a[i] = t;
        if (c[i] % 100 == 0) continue;
        a[i] ++;
        m += 100 - (c[i] % 100); // gano estas monedas
        // Now I need to force
        m -= 100;
        a[i] --;
        b[i] = c[i] % 100;
        S.insert({(100 - (c[i] % 100)) * w[i], i}); // genere esa insatisfaccion
        while (m < 0) {
            auto [ig, ix] = *begin(S);
            m += 100;
            a[ix] ++;
            b[ix] = 0;
            dis += ig;
            S.erase(begin(S));
        }
    }

    cout << dis << "\n";
    L(i,0,n) cout << a[i] << " " << b[i] << "\n";
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