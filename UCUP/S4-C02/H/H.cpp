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
    int n, d; cin >> n >> d;
    vec<ll> h(n); L(i,0,n) cin >> h[i];
    vec<int> li(n); iota(ALL(li), 0);
    vec<int> ri(n); iota(ALL(ri), 0);
    ll k = accumulate(ALL(h), 0LL) / n;
    int ix = 0;
    int cix = 0;
    ll acc = 0;
    while (ix < n) 
    {
        acc += h[i];
        while (acc >= k) {
            ri[cix] = ix;
        }
    }


    int ans = 0;
    L(i,0,n) ans = max(ans, max((i - li[i] + d - 1)/ d, (ri[i] - i + d - 1) / d));

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