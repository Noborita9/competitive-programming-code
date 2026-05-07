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
    int n; cin >> n;
    vec<ll> a(n);
    L(i,0,n) cin >> a[i];
    int masks = 1<<n;
    int ans = 0;
    L(mask, 0, masks) {
        ll pos = 1;
        int times = 0;
        L(bit,0,n) {
            if (mask & (1<<bit)) {
                ll npos = pos + a[bit];
                times += (pos <= 0 && npos > 0);
                pos = npos;
            } else {
                ll npos = pos - a[bit];
                times += (pos > 0 && npos <= 0);
                pos = npos;
            }
        }    
        ans = max(ans, times);
    }
    cout << ans << "\n"; // Jesus help me 
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