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

const int NO_UPD = 0;
const int SET = 1;
const int SUM = 2;
const int oo = 2e9 + 10;

struct ST {
    vec<int> st, lz, lzs; int n;
    ST(int n_): st(4 * n_ + 5, oo), lz(4 * n_ + 5), lzs(4 * n_ + 5), n(n_) {}
    void push(int v, int L, int R){
        if (lzs[v])
        {
            if (R - L > 1) {
                int lc = 2 * v;
                int rc = 2 * v + 1;
                if (lzs[v] == SET) {
                    lzs[lc] = lzs[rc] = SET;
                    st[lc] = st[rc] = lz[lc] = lz[rc] = lz[v];
                } else {
                    st[lc] += lz[v];
                    st[rc] += lz[v];
                    lz[lc] += lz[v];
                    lz[rc] += lz[v];
                    if (lzs[lc] == NO_UPD) lzs[lc] = SUM;
                    if (lzs[rc] == NO_UPD) lzs[rc] = SUM;
                }
            }
            lzs[v] = NO_UPD;
            lz[v] = 0;
        }
    }
    int query(int v, int L, int R, int pos) {
        push(v, L, R);
        if (R - L == 1) return st[v];
        int m = (L + R) / 2;
        if (pos < m) return query(2 * v, L, m, pos);
        return query(2 * v + 1, m, R, pos);
    }
    int query(int pos){
        return query(1, 0, n, pos);
    }
    void update_set(int v, int L, int R, int l, int r, int k){
        if (l >= R || r <= L) return;
        push(v, L, R);
        if (l <= L && R <= r) {
            // I can get the whole segment
            st[v] = k;
            lz[v] = k;
            lzs[v] = SET;
            return;
        }
        int m = (L + R) / 2;
        update_set(2 * v, L, m, l, r, k);
        update_set(2 * v + 1, m, R, l, r, k);
        st[v] = max(st[2 * v], st[2 * v + 1]);
    }
    void update_set(int l, int r, int k){
        update_set(1, 0, n , l, r, k);
    }
    void update_sum(int v, int L, int R, int l, int r, int k){
        if (l >= R || r <= L) return;
        push(v, L, R);
        if (l <= L && R <= r) {
            // I can get the whole segment
            st[v] += k;
            lz[v] = k;
            lzs[v] = SUM;
            return;
        }
        int m = (L + R) / 2;
        update_sum(2 * v, L, m, l, r, k);
        update_sum(2 * v + 1, m, R, l, r, k);
        st[v] = max(st[2 * v], st[2 * v + 1]);
    }

    void update_sum(int l, int r, int k){
        update_sum(1, 0, n, l, r, k);
    }

    int index_of(int v, int L, int R, int k) {
        if (R - L == 1) return L;
        push(v, L, R);
        int m = (L + R) / 2;
        if (st[2 * v] >= k) return index_of(2 * v, L, m, k);
        return index_of(2 * v + 1, m, R, k);
    }
    int index_of(int k){
        return index_of(1, 0, n, k);
    }
};

void solve()
{
    int n, q, d; cin >> n >> q >> d;
    vec<int> h(n); L(i,0,n) cin >> h[i];
    ST st(n);
    vec<vec<pair<int,int>>> qs(n);
    L(i,0,q)
    {
        int l, r; cin >> l >> r;
        qs[r - 1].eb(l - 1, i);
    }
    vec<int> ans(q);

    L(i,0,n)
    {
        // Update segment tree
        int lth = st.index_of(h[i]); // 
        int gth = st.index_of(2 * h[i]);
        st.update_set(lth, gth, h[i] - 1);
        st.update_sum(gth, i, -h[i]);
        st.update_set(i,i + 1, min(d,max(h[i] - 1, d - h[i])));

        for (auto [l, ix]: qs[i]) {
            ans[ix] = st.query(l);
        }
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