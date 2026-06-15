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
    vec<ll> st, lz_d, lz_c; int n;
    ST(const vec<ll> &a): st(4 * SZ(a) + 5), lz_d(4 * SZ(a) + 5), lz_c(4 * SZ(a) + 5), n(SZ(a)) {
        build(1, 0, n, a);
    }
    void build(int v, int L, int R, const vec<ll> &a) {
        if (R - L == 1) st[v] = a[L];
        else {
            int m = (L + R) / 2;
            build(2 * v, L, m, a);
            build(2 * v + 1, m, R, a);
            st[v] = st[2 * v] + st[2 * v + 1];
        }
    }
    void apply(int v, int L, int R) {

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
        int op, l, r; cin >> op>> l >> r;
        if (op == 2){
            cout << st.query(l - 1, r) << "\n";
        } else {
            st.update(l - 1,r - 1);
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