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
    vec<int> a;
    while (cin.good() && !cin.eof()) {
        int x; cin >> x;
        a.pb(x);
    }
    int n = SZ(a);
    vec<int> LIS;
    LIS.pb(0);
    vec<int> prev(n, - 1);
    L(i,1,n){
        if (a[i] > a[LIS.back()]) {
            prev[i] = LIS.back();
            LIS.pb(i);
            continue;
        }
        int lo = 0;
        int hi = SZ(LIS) - 1;
        int ix = 0;
        while (lo <= hi){
            int m = (lo + hi) / 2;
            if (a[i] <= a[LIS[m]]) {
                ix = m;
                hi = m - 1;
            } else lo = m + 1;
        }
        // cout << a[i] << " < " << a[LIS[ix]] << "\n";
        if (ix > 0) prev[i] = LIS[ix - 1];
        // cout << "Prev: " << prev[i] << "\n";
        if (a[i] <= a[LIS[ix]]) {
            LIS[ix] = i;
        }
    }
    // L(i,0,n) cout << prev[i] << "\n";
    // for (int l: LIS) cout << l << " " ; cout << "\n";
    cout << SZ(LIS) << "\n";
    cout << "-\n";
    int it = LIS.back();
    vec<int> ans;
    while (it != -1) {
        ans.pb(a[it]);
        it = prev[it];
    }
    reverse(ALL(ans));
    for (int an: ans) cout << an << "\n";
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