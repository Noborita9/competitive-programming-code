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

const ll oo = 1e18;
struct ST { // max st with 0s as defualt
    int n;vec<ll> st, lz;
    ST(int n_): n(n_), st(4*n+5, oo), lz(4*n+5) {}
    void push(int v, int L, int R){
        if (lz[v]) {
            if (R - L > 1) {
                st[2 * v] += lz[v];
                st[2 * v + 1] += lz[v];
                lz[2 * v] += lz[v];
                lz[2 * v + 1] += lz[v];
            }
            lz[v] = 0;
        }
    }
    void upd(int v, int L, int R, int ql, int qr, ll w) {
        if (qr <= L || ql >= R) return;
        push(v, L, R);
        if (ql <= L && R <= qr){
            lz[v] = w;
            st[v] += w;
            return;
        } 
        int m = (L + R) / 2;
        upd(2 * v, L, m, ql, qr, w);
        upd(2 * v + 1, m, R, ql, qr, w);
        st[v] = min(st[2*v], st[2*v+1]);
    }
    void updPos(int v, int L, int R, int x, ll w) {
        push(v, L, R);
        if (R - L == 1){
            st[v] = w;
            return;
        }
        int m = (L + R) / 2;
        if (x < m) {
            updPos(2 * v, L, m, x, w);
        }
        else {
            updPos(2 * v + 1, m, R, x, w);
        }
        
        st[v] = min(st[2*v], st[2*v+1]);
    }
    ll query(int v, int L, int R, int ql, int qr) {
        if (ql >= R || qr <= L) return oo;
        push(v, L, R);
        if(ql <= L && R <= qr) return st[v];
        int m = (L + R) / 2;
        return min(query(2 * v, L, m, ql, qr), query(2 * v + 1, m, R, ql, qr));
    }
    void upd(int l, int r, ll w){return upd(1,0,n,l,r,w);}
    void updPos(int x, ll w){return updPos(1,0,n,x,w);}
    ll query(int l, int r){return query(1,0,n,l,r);}
};



void solve()
{
    int n, q; cin >> n >> q;
    vec<vec<pair<ll, int>>> g(n);
    L(i,1,n)
    {
        int p; ll w; cin >> p >> w;
        p --;
        g[p].eb(w, i);
    }
    vec<vec<tuple<int,int,int>>> qs(n);
    vec<ll> ans(q);
    L(i,0,q)
    {
        int v, l, r; cin >> v >> l >> r;
        l --; v --;
        qs[v].eb(l, r, i);
    }

    vec<int> euler, out(n); euler.reserve(n);
    vec<int> ids(n);
    vec<ll> dist(n);
    ST st(n);
    auto build = [&](auto && dfs, int u) -> void {
        ids[u] = SZ(euler);
        euler.pb(u);
        for (const auto &[w, v]: g[u]) {
            dist[v] = dist[u] + w;
            dfs(dfs, v);
        }
        out[u] = SZ(euler);
        if (SZ(g[u]) == 0) st.updPos(ids[u], dist[u]);
    };
    build(build, 0);
    
    auto go = [&](auto && dfs, int u) -> void {
        for (const auto &[l, r, i]: qs[u]) {
            ans[i] = st.query(l, r);
        }
        for (const auto &[w, v]: g[u]) {
            st.upd(0, ids[v], w);
            st.upd(out[v], n, w);
            st.upd(ids[v], out[v], -w);
            dfs(dfs, v);
            st.upd(0, ids[v], -w);
            st.upd(out[v], n, -w);
            st.upd(ids[v], out[v], w);
        }
    };
    go(go, 0);
    L(i,0,q)
    {
        cout << ans[i] << "\n";
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