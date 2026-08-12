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
    vec<ll> st; vec<ll> lz; int n;
    ST(int n_): st(4 * n_ + 5, 0), lz(4 *n_ + 5, 0), n(n_) {}
    void push(int v, int L, int R){
        if (lz[v]){
            if (R - L > 1) {
                lz[2 * v] += lz[v];
                lz[2 * v + 1] += lz[v];
                st[2 * v] += lz[v];
                st[2 * v + 1] += lz[v];
            }
            lz[v] = 0;
        }
    }
    void upd(int v, int L, int R, int ql, int qr, ll w) {
        if (ql >= R || qr <= L) return;
        push(v, L, R);
        if (ql <= L && R <= qr) {
            lz[v] = w;
            st[v] += w;
            return;
        }
        int m = (L + R) / 2;
        upd(2 * v, L, m, ql, qr, w);
        upd(2 * v + 1, m, R, ql, qr, w);
        st[v] = max(st[2*v], st[2*v+1]);
    }
    void upd(int l, int r, ll w){
        upd(1, 0, n, l, r, w);
    }
    int query(int v, int L, int R, int ql, ll x){
        push(v, L, R);
        if (st[v] < x) return -1;
        if (R <= ql) return -1; // out of bounds
        if (R - L == 1) return L; // Found my ans

        int m = (L + R) / 2;
        int qla = query(2 * v, L, m, ql, x);
        if (qla != -1) return qla;
        return query(2 * v + 1, m, R, ql, x);
    }
    int query(int l, ll x){
        return query(1, 0, n, l, x);
    }
    void print(int v, int L, int R){
        push(v, L, R);
        if (R - L == 1) cout << st[v] << " ";
        else {
            int m = (L + R) / 2;
            print(2 * v, L, m);
            print(2 * v + 1, m, R);
        }
    }
    void print(){
        print(1,0, n);
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
            int l, r; ll v; cin >> l >> r >> v; 
            st.upd(l, r, v);
            // st.print();
        } else {
            int x, l; cin >> x >> l;
            cout << st.query(l, x) << "\n";
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