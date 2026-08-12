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
    vec<int> c(n); L(i,0,n) cin >> c[i];
    int mx = 2 * c[n - 1];
    const int oo = 1e9;
    vec<int> dp1(mx + 1, oo), dp2(mx + 1, oo);
    int ix = 0;
    dp1[0] = dp2[0] = 0;
    bool cano = 1;
    L(p, 1, mx + 1) {
        while (ix < n - 1 && c[ix + 1] <= p) ix ++; // If I can improve
        // cout << p << " " << c[ix] << " " << ix << "\n";
        dp2[p] = 1 + dp2[p - c[ix]];
        for (int ci: c) {
            if (ci > p) break;
            dp1[p] = min(dp1[p], dp1[p - ci] + 1);
        }
        cano = cano && (dp2[p] == dp1[p]);
    }
    // L(i,0,mx+1) cout << dp1[i] << " "; cout << "\n";
    // L(i,0,mx+1) cout << dp2[i] << " "; cout << "\n";

    if (!cano) cout << "non-";
    cout << "canonical\n";
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