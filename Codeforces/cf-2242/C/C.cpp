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
    int n, k; cin >> n >> k;
    map<int,int> h;
    int ans = 0;
    L(i,0,n) {
        int x; cin >> x; h[x] ++;
    }
    int ln = n;
    int sz = SZ(h);
    vec<int> d; d.reserve(sz);
    int lstSz = sz + 1;
    if (ln && ln <= k) {
        int dt = k - ln;
        if (dt % sz == 0) {
            lstSz = sz;
            ans ++;
        }
    }
    while(ln)
    {
        for (const auto &[ky, v]: h) {
            if (v == 1) d.pb(ky);
            h[ky] --;
        }
        ln -= sz;
        // cout << SZ(h) << endl;
        for (int di: d) h.erase(di);
        // cout << SZ(h) << endl;
        sz = SZ(h);
        d.clear();
        if (ln && ln <= k) {
            int dt = k - ln;
            if (dt % sz == 0 && sz < lstSz) {
                lstSz = sz;
                ans ++;
            }
        }
        // cout << ln << endl;
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