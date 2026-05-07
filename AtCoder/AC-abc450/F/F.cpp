#include <bits/stdc++.h>
using namespace std;

#define L(i,j,n) for (int i = (j); i < (int)n; i ++)
#define pb push_back
#define vec vector
#define SZ(x) int(x.size())
#define ALL(x) begin(x),end(x)

using ll = long long;
using ld = long double;

const ll mod = 998'244'353LL;

inline ll modsum(ll a, ll b){
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

inline ll modmul(ll a, ll b){
    return (a * b) % mod;
}

struct ST {
    vec<ll> st; vec<ll> lz;
    int n;
    ST(int n_): st(4 * n_ + 5), lz(4 * n_ + 5, 1), n(n_) {}
    void push(int v, int L, int R){
        if (lz[v] > 1) {
            if (R - L > 1) {
                st[2 * v] = modmul(st[2 * v], lz[v]);
                st[2 * v + 1] = modmul(st[2 * v + 1], lz[v]);
                lz[2 * v] = modmul(lz[2 * v], lz[v]);
                lz[2 * v + 1] = modmul(lz[2 * v + 1], lz[v]);
            }
            lz[v] = 1;
        }
    }
    void updPt(int v, int L, int R, int pos, ll w) {
        if (R - L == 1){
            st[v] = modsum(st[v], w);
            return;
        }
        push(v, L, R);
        int m = (L + R) / 2;
        if (pos < m) updPt(2 * v, L, m, pos, w);
        else updPt(2 * v + 1, m, R, pos, w);
        st[v] = modsum(st[2 * v], st[2 * v + 1]);
    }
    void updMul(int v, int L, int R, int ql, int qr, ll w){
        if (qr <= L || R <= ql) return;
        if (ql <= L && R <= qr) {
            st[v] = modmul(st[v], w);
            lz[v] = modmul(lz[v], w);
            return;
        }
        push(v, L, R);
        int m = (L + R) / 2;
        updMul(2 * v, L, m, ql, qr, w);
        updMul(2 * v + 1, m, R, ql, qr, w);
        st[v] = modsum(st[2 * v], st[2 * v + 1]);
    }
    ll query(int v, int L, int R, int ql, int qr){
        push(v, L, R);
        if (qr <= L || R <= ql) return 0ll;
        if (ql <= L && R <= qr) return st[v];
        int m = (L + R) / 2;
        return modsum(query(2 * v, L, m, ql, qr), query(2 * v + 1, m, R, ql, qr));
    }
    void updPt(int x, ll w){
        updPt(1,0,n,x,w);
    }
    void updMul(int l, int r, ll w){
        updMul(1,0,n,l,r,w);
    }
    ll query(int l, int r) {
        return query(1, 0, n, l, r);
    }
};


void solve()
{
    int n, m; cin >> n >> m;
    vec<pair<int, int>> E;
    E.reserve(m);
    L(i,0,m){
        int u, v; cin >> u >> v;
        E.emplace_back(u, v);
    }
    sort(ALL(E));
    ST st(n + 5);
    st.updPt(1, 1);
    for (const auto [x, y]: E) {
        st.updMul(y + 1, n + 1, 2);
        st.updPt(y, st.query(x, y + 1));
    }
    cout << st.query(n, n + 1) << "\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}