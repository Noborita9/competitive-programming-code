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

using iii = tuple<int, int, int>;

void solve()
{
    int n, l, r, t; cin >> n >> l >> r >> t;
    vec<iii> c; c.reserve(n);
    L(i,0,n){
        int p, s; cin >> p >> s;
        c.eb(p, -s, i);
    }
    sort(ALL(c));

    for (auto [p, s, i]: c) {
        s *= -1;
        if (p < l || p > r) continue;
        if (s < t) continue;
        cout << i + 1 << "\n";
        return;
    }
    cout << "-1\n";
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