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

struct node {
    ll sm, ans, cnt;
};

node merge(node a, node b) {
    return node{a.sm + b.sm, a.ans + b.ans + b.sm * a.cnt, a.cnt + b.cnt};
}

struct ST {
    vec<node> st; vec<ll> lz; int n;
    ST(const vec<ll> &a): st(4 * SZ(a)), lz(4 * SZ(a) + 5), n(SZ(a)) {build(1,0,n,a);}
    void build(int v, int L, int R, const vec<ll> &a){
        if (R - L == 1){
            st[v] = {a[L], a[L], 1};
        } else {
            int m = (L + R)/ 2;
            build(2 * v, L, m, a);
            build(2 * v + 1, m, R, a);
            st[v] = merge(st[2 * v], st[ 2 * v + 1]);
        }
    }
    void apply(int v, ll lv) {
        ll cnt = st[v].cnt;
        ll delta = ((cnt * (cnt + 1))/2) * lv;
        st[v] = {st[v].sm + lv * cnt, st[v].ans + delta, cnt};
    }
    
    void push(int v, int L, int R){
        if (lz[v]){
            if (R - L > 1) {
                lz[2 * v] += lz[v];
                lz[2 * v + 1] += lz[v]; // simple enough
                apply(2 * v, lz[v]);
                apply(2 * v + 1, lz[v]);
                // ll lcnt = st[2 * v].cnt;
                // ll ldelta = ((lcnt * (lcnt + 1)) / 2) * lz[v];
                // st[2 * v] = {st[2 * v].sm + lz[v], st[2 * v].ans + ldelta, st[2 * v].cnt};

                // ll rcnt = st[2 * v + 1].cnt;
                // ll rdelta = ((rcnt * (rcnt + 1)) / 2) * lz[v];
                // st[2 * v + 1] = {st[2 * v + 1].sm + lz[v], st[2 * v + 1].ans + rdelta, st[2 * v + 1].cnt};
            }
            lz[v] = 0;
        }
    }
    void upd(int v, int L, int R, int ql, int qr, ll w){
        if (ql >= R || qr <= L) return;
        push(v, L, R);
        if (ql <= L && R <= qr) {
            lz[v] += w;
            apply(v, w);
            return;
        }
        int m = (L + R) / 2;
        upd(2 * v, L, m, ql, qr, w);
        upd(2 * v + 1, m, R, ql, qr, w);
        st[v] = merge(st[2 * v], st[2 * v + 1]);
    }
    void upd(int l, int r, ll w){
        upd(1,0,n,l,r,w);
    }
    node query(int v, int L, int R, int ql, int qr) {
        if (ql >= R || qr <= L) return node{0,0,0};
        push(v, L, R);
        if (ql <= L && R <= qr) return st[v];
        int m = (L + R) / 2;
        return merge(query(2 * v, L, m, ql, qr), query(2 * v + 1, m, R, ql, qr));
    }
    ll query(int l, int r){
        return query(1,0,n,l,r).ans;
    }
};

void solve()
{
    int n, q; cin >> n >> q;
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    ST st(a);
    while(q--)
    {
        int op; cin >> op;
        if (op == 1){
            int l, r; ll w; cin >> l >> r >> w;
            l --;
            st.upd(l, r, w);
        } else {
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