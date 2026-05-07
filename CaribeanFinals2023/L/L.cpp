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
    ll n; int k; cin >> n >> k;
    vec<ll> a(k + 2);
    L(i,1,k+1) cin >> a[i];
    a[0] = 1;
    a[k+1] = 0;
    ll sm = accumulate(ALL(a), 0ll);
    if (sm > n) {
        cout << "-1\n";
        return;
    }
    n -= sm;
    ll edges = 0;
    L(i,0,k) edges += a[i] * a[i+1];
    ll ans = edges;
    L(i,1,k+1){
        edges -= a[i - 1] * a[i] + a[i] * a[i + 1]; // erase current
        a[i] += n;
        edges += a[i - 1] * a[i] + a[i] * a[i + 1]; // increase i

        ans = max(ans, edges);
        // cout << ans << "\n";
        edges -= a[i - 1] * a[i] + a[i] * a[i + 1]; // decreace i
        a[i] -= n;
        edges += a[i - 1] * a[i] + a[i] * a[i + 1]; // restore original
    }

    auto c = [&](int i) -> ll {
        return a[i - 1] * a[i];
    };

    auto eval = [&](ll x, ll a1, ll a2) -> ll {
        return -(x * x) + x * a1 + a2;
    };

    L(i,1,k) {
        ll a1 = -a[i] + a[i + 1] + n;
        ll a2 = a[i] * a[i + 1];
        ll p1 = a1 / 2;
        ll cpi1 = max(0ll, min(eval(p1, a1, a2), n)); // Quantities to add to ai
        ll cpin2 = n - cpi1; // add to ai+1
        cout << "i: " << i << " -> " << cpi1 << " " << cpin2 << "\n";
        ll nedges = a[i - 1] * cpi1 + a[i]*cpin2 + a[i+1]*cpi1 + a[i + 2] * cpin2;
        // ll nedges = a[i - 1] * cpi1 + cpi1 * cpin2  + a[i + 2] * cpin2;
        ans = max(ans, edges + nedges);
        p1 ++;
        cpi1 = max(0ll, min(eval(p1, a1, a2), n)); // Quantities to add to ai
        cpin2 = n - cpi1; // add to ai+1
        cout << "i: " << i << " -> " << cpi1 << " " << cpin2 << "\n";
        nedges = a[i - 1] * cpi1 + a[i]*cpin2 + a[i+1]*cpi1 + a[i + 2] * cpin2;
        ans = max(ans, edges + nedges);
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