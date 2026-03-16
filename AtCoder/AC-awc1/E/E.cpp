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
    int n, k; cin >> n >> k;
    multiset<ll> ms;
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    L(i,0,k) ms.insert(a[i]);
    ll best = *rbegin(ms) - *begin(ms);
    L(i,k,n) {
        ms.erase(ms.find(a[i-k]));
        ms.insert(a[i]);
        best = max(best,*rbegin(ms) - *begin(ms));
    }
    cout << best << "\n";
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