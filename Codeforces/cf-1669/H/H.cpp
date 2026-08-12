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
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    ll ans = 0;
    for (int bit = 30; bit >= 0; bit --)
    {
        ll req = 0;
        L(i,0,n) {
            if (!(a[i] & (1LL << bit))) req ++;
        }

        if (req <= k){
            k -= req;
            ans += 1LL << bit;
        }
    }
    cout << ans << "\n";
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