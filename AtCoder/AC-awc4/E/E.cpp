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
    map<ll, ll> M;
    ll ans = 0;
    ll acc = 0;
    M[0] = 1;
    L(i,0,n){
        acc += a[i];
        ans += M[acc - k];
        M[acc] ++;
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