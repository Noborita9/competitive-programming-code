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
    int n, k; ll p, q; cin >> n >> k >> p >> q;
    vec<ll> a(n), U(n), V(n), best(n);
    L(i,0,n){
        cin >> a[i];
        U[i] = a[i] % p;
        V[i] = (a[i] % q) % p;
        best[i] = min(U[i], V[i]);
    }
    ll sm = accumulate(ALL(best), 0ll);
    const ll oo = (ll)4e18;
    ll ans = oo;
    ll uw = 0;
    ll vw = 0;
    ll rw = 0;
    L(i,0,k) {
        uw += U[i];
        vw += V[i];
        rw += best[i];
    }
    ans = min(ans, min(sm - rw + uw, sm - rw + vw));
    L(i,k,n) {
        uw += U[i] - U[i - k];
        vw += V[i] - V[i - k];
        rw += best[i] - best[i - k];
        ans = min(ans, min(sm - rw + uw, sm - rw + vw));
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