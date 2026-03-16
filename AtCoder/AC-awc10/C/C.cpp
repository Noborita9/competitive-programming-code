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
    int n, q; ll k; cin >> n >> k >> q;
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    vec<int> h(n, - 1);
    h[0] = 0;
    L(i,1,n){
        if (abs(a[i] - a[i - 1]) <= k) h[i] = h[i - 1];
        else h[i] = h[i - 1] + 1;
    }
    while(q--)
    {
        int l, r; cin >> l >> r;
        l -- ; r--;
        cout << (h[l] == h[r] ? "Yes" : "No") << "\n";
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