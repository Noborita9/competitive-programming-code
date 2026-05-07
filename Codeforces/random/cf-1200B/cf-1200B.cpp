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
    int n; ll m,  k; cin >> n >> m >> k;
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    m += a[0];
    int i = 1;
    while (i < n){
        if (m >= a[i] - k) {
            m -= max(0ll, a[i] - k);
            m += a[i];
        } else break;
        i ++;
    }
    cout << (i == n ? "YES" : "NO") << "\n";
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