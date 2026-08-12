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
    vec<int> st, lz_mx, lz_mn; int n;
    ST(int n_): st(4 * n + 5), lz_mx(4 * n + 5, -1), lz_mn(4 * n + 5, -1) {}
    // Implement Lazy
    void push(int v, int L, int R) {

    }
    
    void upd_mx(int v, int L, int R, int ql, int qr, int w) {}
    void upd_mn(int v, int L, int R, int ql, int qr, int w) {}
    
    // End of impl
    void upd_mx(int l, int r, int w){
        upd_mx(1,0,n,l,r,w);
    }
    void upd_mn(int l, int r, int w){
        upd_mn(1,0,n,l,r,w);
    }
    void print(int v, int L, int R){
        push(v, L, R);
        if (R - L == 1) cout << st[v] << "\n"; 
        else {
            int m = (L + R) / 2;
            print(2 * v, L, m);
            print(2 * v + 1, m, R);
        }
    }
    void print(){
        print(1,0,n);
    }
};


void solve()
{
    int n, q; cin >> n >> q;
    ST st(n);
    while(q--)
    {
        int op, l, r, h; cin >> op >> l >> r >> h;
        l --;
        if (op == 1) st.upd_mx(l, r, h);
        else st.upd_mn(l, r, h);
    }

    st.print();
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