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
    int n; cin >> n;
    vec<ll> f(n); L(i,0,n) cin >> f[i];
    vec<ll> a(n);
    L(i,1,n - 1)
    {
        a[i] = (f[i - 1] - (2LL * f[i]) + f[i + 1]) / 2;
    }
    ll sm = 0;
    L(i,1,n - 1) sm += a[i] * i;
    a[n - 1] = (f[0] - sm) / (n - 1);
    sm = 0;
    L(i,1,n-1) sm += a[n - 1 - i] * (n - (n - i));
    a[0] = (f[n - 1] - sm) / (n - 1);

    L(i,0,n) cout << a[i] << " ";
    cout << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}