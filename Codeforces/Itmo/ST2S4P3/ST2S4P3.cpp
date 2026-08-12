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

const int N = 1e6 + 5;

struct node {
    int pref, suff, sm, seg;
    node(int c): pref(c), suff(c), sm(c), seg(c) {}
    node(int pref_, int suff_, int sm_, int seg_): pref(pref_), suff(suff_), sm(sm_), seg(seg_) {}
};

node merge(node a, node b) {
    return node{
        a.pref,
        b.suff, 
        a.sm + b.sm, 
        a.seg + b.seg - ((a.suff == b.pref && a.suff == 1) ? 1 : 0)
    };
}

struct ST {
    vec<node> st; vec<int> lz; int n;
    ST(int n_): st(4 * n_ + 5, node(0)), lz(4 * n_ + 5, - 1), n(n_) {}
    void push(int v, int L, int R){
        if (lz[v] != -1) {
            if (R - L > 1) {
                lz[2 * v] = lz[v];
                lz[2 * v + 1] = lz[v];
                int m = (L + R) / 2;
                int llen = m - L;
                int rlen = R - m;
                st[2 * v] = node(lz[v], lz[v], lz[v] ? llen : 0, lz[v] ? 1 : 0);
                st[2 * v + 1] = node(lz[v], lz[v], lz[v] ? rlen : 0, lz[v] ? 1 : 0);
            }
            lz[v] = -1;
        }
    }
    void upd(int v, int L, int R, int ql, int qr, int c) {
        if (ql >= R || qr <= L) return;
        push(v, L, R);
        if (ql <= L && R <= qr) {
            lz[v] = c;
            if (c) {
                st[v] = node{c, c, R - L, 1};
            } else {
                st[v] = node{c, c, 0, 0};
            }
            return;
        }
        int m = (L + R) / 2;
        upd(2 * v, L, m, ql, qr, c);
        upd(2 * v + 1, m, R, ql, qr, c);
        st[v] = merge(st[2 * v], st[2 * v + 1]);
    }
    void upd(int l, int r, int c){
        upd(1, 0, n, l, r, c);
    }
};


void solve()
{
    int n; cin >> n;
    ST st(N);
    L(i,0,n)
    {
        char c; int x, l; cin >> c >> x >> l;
        x += 500'000;
        int r = l + x;
        // cout << x << " " << r << c << "\n";
        st.upd(x, r, c == 'B');
        cout << st.st[1].seg << " " << st.st[1].sm << "\n";
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