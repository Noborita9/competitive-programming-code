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
    vec<pair<int, int>> c; c.reserve(n);
    L(i,0,n)
    {
        int l, r; cin >> l >> r;
        c.eb(r, l);
    }
    sort(ALL(c));
    auto check = [&](int x) -> bool {
        int choose = 0;
        int last = -1;
        for (const auto &[r, l]: c) {
            if (l > last) {
                last = r + x - 1;
                choose ++;
            }
        }
        return choose >= k;
    };
    int lo = 1;
    int hi = 1e9;
    int ans = -1;
    while(lo <= hi) {
        int m = (lo + hi) / 2;
        if (check(m)){
            ans = m;
            lo = m + 1;
        } else hi = m - 1;
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