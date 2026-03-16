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

const int BLOCK_SIZE = 2e7/250; using U64 = uint64_t;
struct query {ll l, r, id;U64 order;
bool operator<(const query& o) const {
    if (l / BLOCK_SIZE != o.l / BLOCK_SIZE) return l < o.l;
    return (l / BLOCK_SIZE & 1) ? r < o.r : r > o.r;
} // If short implementation needed
};
U64 hilbertorder(U64 x, U64 y) { // If Efficient impl needed
    const U64 logn = 21;
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
    vec<query> p(n);
    L(i,0,n){
        ll x, y; cin >> x >> y;
        p[i] = {x, y, i, 0};
    }
    sort(ALL(p));
    int pos0 = 0;
    while (p[pos0].id != 0) pos0 ++;
    rotate(begin(p), begin(p) + pos0, end(p));
    L(i,0,n) cout << p[i].id + 1 << " ";
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