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


struct ST {
    vec<int> st; vec<int> lz; int n;
    ST(int n_): st(4 * n_ + 5, 0), lz(4 *n_ + 5, 0), n(n_) {}
    void push(int v, int L, int R){
        if (lz[v]){
            if (R - L > 1) {
                int m = (L + R) / 2;
                int llen = m - L;
                int rlen = R - m;
                lz[2 * v] ^= lz[v];
                lz[2 * v + 1] ^= lz[v];
                st[2 * v] = llen - st[2 * v];
                st[2 * v + 1] = rlen - st[2 * v + 1];
            }
            lz[v] = 0;
        }
    }
    void upd(int v, int L, int R, int ql, int qr) {
        if (ql >= R || qr <= L) return;
        push(v, L, R);
        if (ql <= L && R <= qr) {
            lz[v] = 1;
            st[v] = (R - L) - st[v];
            return;
        }
        int m = (L + R) / 2;
        upd(2 * v, L, m, ql, qr);
        upd(2 * v + 1, m, R, ql, qr);
        st[v] = st[2*v] + st[2*v+1];
    }
    void upd(int l, int r){
        upd(1, 0, n, l, r);
    }
    int query(int v, int L, int R, int k){
        push(v, L, R);
        if (R - L == 1) return L;
        int m = (L + R) / 2;
        if (st[2 * v] >= k) return query(2 * v, L, m, k);
        return query(2 * v + 1, m, R, k - st[2 * v]);
    }
    int query(int k){
        return query(1, 0, n, k);
    }
    void print(int v, int L, int R) {
        push(v, L, R);
        if (R - L == 1) cout << st[v] << " ";
        else {
            int m = (L + R)/2;
            print(2 * v, L, m);
            print(2 * v + 1, m, R);
        }
    }
    void print() {
        print(1,0,n);
        cout << "\n";
    }
};

void solve()
{
    int n, q; cin >> n >> q;
    ST st(n);
    
    while(q--)
    {
        int op; cin >> op;
        if (op == 1){
            int l, r; cin >> l >> r;
            st.upd(l, r);
        } else {
            int k; cin >> k;
            cout << st.query(k + 1) << "\n";
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