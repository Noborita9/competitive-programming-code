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
    vec<ll> a(n);
    L(i,0,n) cin >> a[i];
    sort(ALL(a));
    const ll oo = 1e18;
    ll ans = 1;
    // cout << "N: " << n  << endl;
    L(i,0,5) ans *= a[n - 1 - i ]; // take the 5 biggest
    // cout << "Here" << endl;
    vec<ll> neg;
    L(i,0,n) if (a[i] < 0) neg.pb(a[i]);
    if (SZ(neg) >= 2) {
        ll pot = 1;
        L(i,0,3) pot *= a[n - 1 - i]; // take the 3 biggest
        pot *= neg[0] * neg[1];
        ans = max(ans, pot);
    }
    if (SZ(neg) >= 4) {
        ll pot = 1;
        L(i,0,1) pot *= a[n - 1 - i]; // take the 1 biggest
        pot *= neg[0] * neg[1] * neg[2] * neg[3];
        ans = max(ans, pot);
    }
    cout << ans <<"\n";
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