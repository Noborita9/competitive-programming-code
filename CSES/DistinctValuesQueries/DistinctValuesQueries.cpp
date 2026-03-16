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

#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
template<typename Key, typename Val=null_type>
using indexed_set = tree<Key, Val, less<Key>, rb_tree_tag,
                         tree_order_statistics_node_update>;
// indexed_set<char> s;
// char val = *s.find_by_order(0); // acceso por indice
// int idx = s.order_of_key('a'); // busca indice del valor
template<class Key,class Val=null_type>using htable=gp_hash_table<Key,Val>;
// como unordered_map (o unordered_set si Val es vacio), pero sin metodo count


const int BLOCK_SIZE = 450; using U64 = uint64_t;
struct query {int l, r, id;U64 order;
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
    int n, q; cin >> n >> q;
    vec<query> qs(q);
    vec<int> raw(n);
    vec<int> a(n);
    L(i,0,n) {cin >> a[i]; raw.pb(a[i]);}
    L(i,0,q){
        int l, r; cin >> l >> r;
        qs[i] = {l -1 , r-1, i, 0};
    }
    sort(ALL(qs));
    sort(ALL(raw));
    raw.erase(unique(ALL(raw)),end(raw));
    auto idx=[&](int x){return lower_bound(ALL(raw), x)-begin(raw);};
    L(i,0,n)a[i]=idx(a[i]);
    vec<int> freq(SZ(raw));
    int dist = 0;
    auto add = [&](int ix) { 
        if (++freq[a[ix]] == 1) {
            dist ++;
        }
    };
    auto rem = [&](int ix) { 
        if (--freq[a[ix]] == 0) {
            dist --;
        }
    };
    int c_l = 0, c_r = -1; // Cursors [0,-1] so r add 0 on first q
    vec<int> ans(q);
    for(const auto &qr: qs){
        while(c_l > qr.l) add(--c_l);
        while(c_r < qr.r) add(++c_r);
        while(c_l < qr.l) rem(c_l++);
        while (c_r > qr.r) rem(c_r--);
        ans[qr.id] = dist;
    }
    L(i,0,q) cout << ans[i] << "\n";
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