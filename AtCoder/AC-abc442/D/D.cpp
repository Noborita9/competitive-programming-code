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
    int n, q; cin >> n >> q;
    vec<ll> a(n + 1); L(i,0,n) cin >> a[i + 1];
    vec<ll> pref(n + 1);
    partial_sum(ALL(a), begin(pref));
    while( q--)
    {
        int op; cin >> op;
        if (op == 2) {
            int l, r; cin >> l >> r;
            cout << pref[r] - pref[l - 1] << "\n";
        } else {
            int x; cin >> x;
            swap(a[x], a[x + 1]);
            pref[x] = pref[x - 1] + a[x];
            pref[x + 1] = pref[x] + a[x + 1];
        }
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