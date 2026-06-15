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

const ll oo = (ll)1e18;

struct ST {
    vec<ll> st, lz_sum, lz_set; int n;
    ST(const vec<ll> &a): st(SZ(a) * 4 + 5), lz_sum(SZ(a) * 4 + 5), lz_set(SZ(a) * 4 + 5, oo), n(SZ(a)) {
        build(1, 0, n, a);
    }
    void build(int v, int L, int R, const vec<ll> &a) {
        if (R - L == 1) st[v] = a[L];
        else {
            int m = (L + R) / 2;
            build(v * 2, L, m, a);
            build(v * 2 + 1, m, R, a);
            st[v] = st[2 * v] + st[2 * v + 1];
        }
    }
    
    void push(int v, int L, int R){
        if (R - L > 1) {
            int lc = 2 * v;
            int rc = 2 * v + 1;
            ll m = (L + R) / 2;
            ll lh = m - L;
            ll rh = R - m;
            if (lz_set[v] != oo) {
                st[lc] = lh * lz_set[v];
                lz_set[lc] = lz_set[v];
                lz_sum[lc] = 0;
                st[rc] = rh * lz_set[v];
                lz_set[rc] = lz_set[v];
                lz_sum[rc] = 0;
            }
            if (lz_sum[v] > 0) {
                st[lc] += lh * lz_sum[v];
                st[rc] += rh * lz_sum[v];

                if (lz_set[lc] != oo) {
                    lz_set[lc] += lz_sum[v];
                } else lz_sum[lc] += lz_sum[v];
                
                if (lz_set[rc] != oo) {
                    lz_set[rc] += lz_sum[v];
                } else lz_sum[rc] += lz_sum[v];
            }
            lz_set[v] = oo;
            lz_sum[v] = 0;
        }
    }
    ll query(int v, int L, int R, int ql, int qr){
        if (qr <= L || R <= ql) return 0LL;
        push(v, L, R);
        if (ql <= L && R <= qr) return st[v];
        int m = (L + R) / 2;
        return query(2 * v, L, m, ql, qr) + query(2 * v + 1, m, R, ql, qr);
    }
    ll query(int l, int r){
        return query(1, 0, n, l, r);
    }
    void update_set(int v, int L, int R, int ql, int qr, ll w){
        if (qr <= L || R <= ql) return;
        push(v, L, R);
        if (ql <= L && R <= qr) {
            st[v] = (ll)(R - L) * w;
            lz_set[v] = w;
            return;
        }
        int m = (L + R) / 2;
        update_set(2 * v, L, m, ql, qr, w);
        update_set(2 * v + 1, m, R, ql, qr, w);
        st[v] = st[2 * v] + st[2 * v + 1];
    }
    void update_set(int l, int r, ll w){
        update_set(1, 0, n, l, r, w);
    }

    void update_sum(int v, int L, int R, int ql, int qr, ll w){
        if (qr <= L || R <= ql) return;
        push(v, L, R);
        if (ql <= L && R <= qr) {
            st[v] += (ll)(R - L) * w;
            lz_sum[v] = w;
            return;
        }
        int m = (L + R) / 2;
        update_sum(2 * v, L, m, ql, qr, w);
        update_sum(2 * v + 1, m, R, ql, qr, w);
        st[v] = st[2 * v] + st[2 * v + 1];
    }
    void update_sum(int l, int r, ll w){
        update_sum(1, 0, n, l, r, w);
    }
};


void solve()
{
    int n, q; cin >> n >> q;
    vec<ll> a(n);
    L(i,0,n) cin >> a[i];
    ST st(a);
    L(i,0,q)
    {
        int op; cin >> op;
        if (op == 1)
        {
            int l, r; ll w; cin >> l >> r >> w;
            st.update_sum(l - 1, r, w);
        } else if (op == 2)
        {
            int l, r; ll w; cin >> l >> r >> w;
            st.update_set(l - 1, r, w);
        }
        else if (op == 3)
        {
            int l, r; cin >> l >> r;
            cout << st.query(l - 1, r) << "\n";
        }
    }
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