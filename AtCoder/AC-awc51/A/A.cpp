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
    int n, m, k; cin >> n >> m >> k;
    vec<ll> p(n); L(i,0,n) cin >> p[i];
    sort(ALL(p));
    vec<ll> l(m); L(i,0,m) cin >> l[i];
    vec<ll> u(k); L(i,0,k) cin >> u[i];
    L(i,0,k) u[i] = l[u[i]-1];
    int mx = *max_element(ALL(u));
    ll sm = 0; L(i,0,n) if (mx >= p[i]) sm += p[i];
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