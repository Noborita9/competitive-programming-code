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
    if (b - a >= 5) cout << "0\n";
    else if (a == b) {
        cout << 1 << "\n";
    }
    else {
        ll nm = (a + 1) % 10LL;
        // cout << b - a << "\n";
        for (ll j = a + 2; j <= b; j ++){

            nm *= (j) % 10LL;
            nm %= 10LL;
        }
        cout << nm % 10 << "\n";
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