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
    int n; ll c; cin >> n >> c;
    vec<ll> a(n); 
    L(i,0,n) {
        cin >> a[i];
    }

    sort(ALL(a));
    ll ans = accumulate(ALL(a), 0ll) - (n * c);
    L(i,0,n / 2){
        if (c - a[i] > 0) ans += c-a[i]; 
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