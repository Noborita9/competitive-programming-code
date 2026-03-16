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
            st[v] = st[2 * v] + st[2 * v + 1];
        }
    }
    ll query(int v, int L, int R, int ql, int qr){
        if (qr <= L || ql >= R) return 0ll;
        if (ql <= L && R <= qr) return st[v];
        int m = (L + R) / 2;
        return query(2 * v, L, m, ql, qr) + query(2 * v + 1, m, R, ql, qr);
    }
    ll query(int l, int r){
        return query(1, 0, n, l, r);
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
        int l, r; cin >> l >> r;
        l --; r --;
        cout << st.query(l, r + 1) << "\n";
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