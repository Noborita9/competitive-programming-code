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
    ll k; int n; cin >> k >> n;
    vec<ll> l(n), r(n); L(i,0,n) cin >> l[i] >> r[i];
    vec<int> ord(n);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&](int a, int b){
        if (l[a] != l[b]) return l[a] < l[b];
        return r[a] < r[b];
    });
    ll last = 0; // last day rained

    ll ans = -1;
    
    for (int i: ord) {
        if (l[i] - 1 <= last){
            last = max(last, r[i]);
        } else {
            // last is disconnected with l[i]
            ll gap = l[i] - last - 1;
            if (gap < k) k -= gap;
            else {
                ans = last + k;
                k = 0;
                break;
            }
            last = r[i];

        }
    }
    if (k > 0) ans = last + k;
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