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
    ll a, b; cin >> a >> b;
    ll t = a - 2LL * ((-b + 2LL * a)/3);
    ll f = (-b + 2LL * a) / 3;
    
    if (f >= 0 && t >= 0 && 2 * f + t == a && f + 2 * t == b) cout << "YES\n";
    else cout << "NO\n";
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