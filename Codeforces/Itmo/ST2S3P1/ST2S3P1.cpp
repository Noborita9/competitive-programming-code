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

const ll oo = (ll)2e9;
struct node {
    ll sm, pref, suff, ans;
    node(ll x): sm(x) {
        pref = suff = ans = max(0ll, x);
    }
    node(ll sm_, ll pref_, ll suff_, ll ans_): sm(sm_), pref(pref_), suff(suff_), ans(ans_) {}
};

node merge(node a, node b) {
    ll pref = max(a.pref, a.sm + b.pref);
    ll suff = max(a.suff + b.sm, b.suff);
    ll ans = max({a.ans, b.ans, a.suff + b.pref});
    ll sm = a.sm + b.sm;
    return node{sm, pref, suff, ans};
};

struct ST {
    vec<node> st; vec<ll> lz; int n;
    ST(int n_): st(4 * n_ + 5, node(0)), lz(4 *n_ + 5, oo), n(n_) {}
    void push(int v, int L, int R){
        if (lz[v] != oo){
            if (R - L > 1) {
                lz[2 * v] = lz[v];
                lz[2 * v + 1] = lz[v];
                ll m = (L + R) / 2;
                ll llen = m - L;
                ll rlen = R - m;
                st[2 * v] = node(llen * lz[v]);
                st[2 * v + 1] = node(rlen * lz[v]);
            }
            lz[v] = oo;
        }
    }
    void upd(int v, int L, int R, int ql, int qr, ll w) {
        if (ql >= R || qr <= L) return;
        push(v, L, R);
        if (ql <= L && R <= qr) {
            lz[v] = w;
            st[v] = node((ll)(R - L) * w);
            return;
        }
        int m = (L + R) / 2;
        upd(2 * v, L, m, ql, qr, w);
        upd(2 * v + 1, m, R, ql, qr, w);
        st[v] = merge(st[2 * v], st[2 * v + 1]);
    }
    void upd(int l, int r, ll w){
        upd(1, 0, n, l, r, w);
    }
};

void solve()
{
    int n, q; cin >> n >> q;
    ST st(n);
    
    while(q--)
    {
        int l, r; ll v; cin >> l >> r >> v;
        st.upd(l, r, v);
        cout << st.st[1].ans << "\n";      
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