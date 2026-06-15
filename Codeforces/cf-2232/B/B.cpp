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
    vec<ll> h(n); L(i,0,n) cin >> h[i];

    cout << h[0] << " ";

    ll sm = h[0];
    ll exc = 0;
    ll top = h[0];

    L(i,1,n)
    {
        sm += h[i];
        if (h[i] >= top)
        {
            exc += h[i] - top;
        } else {
            ll lo = h[i];
            ll hi = top;

            ll ans = lo;

            while (lo <= hi) {
                ll m = (lo + hi) / 2;
                ll nd = (ll)(i + 1) * m;
                ll nexc = sm - nd;
                if (nexc < 0){
                    hi = m - 1;
                } else {
                    lo = m + 1;
                    ans = m;
                }
            }

            top = ans;
            exc = sm - (ll)(i + 1)*top;
        }   
        cout << top << " ";
    }

    cout << "\n";
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