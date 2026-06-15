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
    int n; ll k; int q; cin >> n >> k >> q;
    vec<ll> a(n + 1);
    L(i,0,n) cin >> a[i + 1];
    partial_sum(ALL(a), begin(a));
    // L(i,0,n +1) cout << a[i] << " ";
    // cout << "\n";
    vec<ll> f(n + 1);
    L(i,0,n)
    {
        f[i + 1] = f[i] + (upper_bound(ALL(a), a[i] + k) - begin(a)); // has 1 more index
        if (a[i] + k >= a.back()) f[i + 1] --;
        // cout << f[i + 1] << " "; cout << "\n";
    }
    // cout << "\n";
    L(i,0,q)
    {
        int l, r; cin >> l >> r;
        cout << f[r] - f[l - 1] << "\n";
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