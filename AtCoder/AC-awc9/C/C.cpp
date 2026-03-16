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
    int n; ll t, k; cin >> n >> t >> k;
    vec<ll> h(n); L(i,0,n) cin >> h[i];
    ll mn = *min_element(ALL(h));
    L(i,0,n) h[i] -= mn - 1;
    int r = 0;
    L(i,0,n) r += h[i] <= t + k;
    cout << r  << "\n";
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