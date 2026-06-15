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
    int n, m; cin >> n >> m;
    vec<vec<ll>> d(m, vec<ll>(n));
    L(i,0,n)
    {
        L(j,0,m)
        {
            cin >> d[j][i];
        }
    }
    ll ans = 0;
    L(j,0,m)
    {
        sort(ALL(d[j]));
        auto &x = d[j];
        ll sm = 0;
        L(i,0,n)
        {
            sm += (x[i] - x[0]);
        }
        ans += sm;
        L(i,1,n)
        {
            sm = sm - (ll)(n - i)*(x[i] - x[i - 1]);
            ans += sm;
        }
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