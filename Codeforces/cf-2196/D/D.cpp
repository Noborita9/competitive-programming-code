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
    int n, k; ll m; cin >> n >> k >> m;
    vec<ll> a(n + 1), pref(n + 1);
    L(i, 0, n) {
        cin >> a[i + 1];
        pref[i + 1] += pref[i] + a[i + 1];
    }
    ll ans = 0;
    L(i,1,n + 1){
        if (i + k - 1 > n) break;
        ll need = pref[i - 1] + m; // need this at least
        auto it = lower_bound(ALL(pref), need);
        ll maxWin = n - (i + k - 2);
        ans += min(maxWin, (ll)(end(pref) - it));
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