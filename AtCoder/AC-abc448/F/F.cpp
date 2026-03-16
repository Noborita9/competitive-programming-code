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

using U64 = uint64_t;
struct query {int l, r, id;U64 order;};
U64 hilbertorder(U64 x, U64 y) {
    const U64 logn = 25; // Fixed global grid size!
    const U64 maxn = (1ull << logn) - 1;
    U64 res = 0;
    for (U64 s = 1ull << (logn - 1); s; s >>= 1) {
        bool rx = x & s, ry = y & s;
        res = (res << 2) | (rx ? ry ? 2 : 1 : ry ? 3 : 0);
        if (!rx) {
            if (ry) x ^= maxn, y ^= maxn;
            swap(x, y);
        }
    }
    return res;
} // sort by this order


void solve()
{
    int n; cin >> n;
    vec<pair<ll, int>> a(n);
    L(i,0,n) {
        ll x, y; cin >> x >> y;
        a[i] = {hilbertorder(x, y), i};
    }
    sort(ALL(a));
    int pos0 = 0;
    L(i,0,n) if (a[i].second == 0) pos0 = i;
    rotate(begin(a), begin(a) + pos0, end(a));
    L(i,0,n) cout << a[i].second + 1 << " ";
    cout << "\n";
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