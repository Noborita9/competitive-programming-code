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
    int n, k; ll x; cin >> n >> k >> x;
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    sort(ALL(a), greater());
    ll ans = n - k;
    ll acc = 0;
    L(i,n - k,n){
        ans ++;
        acc += a[i];
        if (acc >= x) break;
    }
    if (acc < x) return void(cout << "-1\n");
    cout << ans <<"\n";
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