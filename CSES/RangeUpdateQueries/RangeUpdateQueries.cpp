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

struct ST {
    vec<ll> st; int n;
    ST(vec<ll> &a): st(4 * SZ(a) + 5), n(SZ(a)) {
        build(1,0, n, a);
    }
    void build(int v, int L, int R, vec<ll>&a){
        if (R - L == 1){
            st[v] = a[L];
        } else {
            int m = (L + R) / 2;
            build(2 * v, L, m, a);
            build(2 * v + 1, m, R, a);
            // st[v] = st[2 * v] ^ st[2 * v + 1];
        }
    }
    void upd(int v, int L, int R, int ql, int qr, ll w) {
        if (qr <= L || ql >= R) return;
        if (ql <= L && R <= qr) {
            st[v] += w;
            return;
        }
        int m = (L + R) / 2;
        upd(2 * v, L, m, ql, qr, w);
        upd(2 * v + 1, m, R, ql, qr, w);
    }
    ll query(int v, int L, int R, int pos){
        if (R - L == 1){return st[v];}
        int m = (L + R) / 2;
        if (pos < m) return st[v] + query(2 * v, L, m, pos);
        return st[v] + query(2 * v + 1, m, R, pos);
    }
    void upd(int l, int r, ll w){
        upd(1, 0, n, l, r, w);
    }
    ll query(int x){
        return query(1, 0, n,x);
    }
};

void solve()
{
    int n, q; cin >> n >> q;
    vec<ll> a(n);
    L(i,0,n) cin >> a[i];
    ST st(a);
    while(q--)
    {
        int op; cin >> op;
        if (op == 2){
            int x; cin >> x;
            // cout << "Pre Q" << endl;
            cout << st.query(x - 1) << "\n";
            // cout << "Post Q" << endl;
        } else {
            int l, r; ll w; cin >> l >> r >> w;
            // cout << "Pre U" << endl;
            st.upd(l - 1, r, w);
            // cout << "Post U" << endl;
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