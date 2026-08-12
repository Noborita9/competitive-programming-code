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
const int N = 1e5 + 10;

#define LC(v) (v<<1)
#define RC(v) ((v<<1)|1)
#define MD(L, R) (L+((R-L)>>1))
struct node { ll odd;ll even; };
struct ST {
    vec<node> st; vec<int> lz; int n;
    ST(int n_ = 1): st(4 * n_ + 10, node{0, 0}), lz(4 * n_ + 10, 0), n(n_) {}
    node merge(node a, node b){
        return node{a.odd + b.odd, a.even + b.even};
    }
    void apply(int v){
        swap(st[v].odd, st[v].even);
    }
    void push(int v, int L, int R){
        if (lz[v]){
            if (L != R){
                apply(LC(v));
                apply(RC(v));
                lz[RC(v)] ^= 1;
                lz[LC(v)] ^= 1;
            }
            lz[v] = 0;
        }
    }
    void update(int v, int L, int R, int ql, int qr, ll w){
        if (ql > R || qr < L) return;
        if (ql == L && qr == R){
            st[v].even += w; // Update acutal node
            return;
        }
        int m = MD(L, R);
        update(LC(v), L, m, ql, min(qr, m), w);
        update(RC(v), m + 1, R, max(m + 1, ql), qr, w);
        st[v] = merge(st[LC(v)], st[RC(v)]);
    }
    void updateXor(int v, int L, int R, int ql, int qr){
        if (ql > R || qr < L) return;
        push(v, L, R);
        if (ql == L && qr == R){
            apply(v);
            lz[v] ^= 1; // Add lazy
            return;
        }
        int m = MD(L, R);
        updateXor(LC(v), L, m, ql, min(qr, m));
        updateXor(RC(v), m + 1, R, max(m + 1, ql), qr);
        st[v] = merge(st[LC(v)], st[RC(v)]);
    }
    ll query(int v, int L, int R, int ql, int qr){
        if (ql > R || qr < L) return 0LL;
        push(v, L, R);
        if (ql == L && qr == R) return st[v].odd;
        int m = MD(L, R);
        return query(LC(v), L, m, ql, min(m, qr)) + query(RC(v), m + 1, R, max(m + 1, ql), qr);
    }
    ll query(int l, int r){return query(1, 0, n - 1, l, r);}
    void update(int l, int r, ll w){update(1, 0, n - 1, l, r, w);}
    void updateXor(int l, int r){updateXor(1, 0, n - 1, l, r);}
} st(N);


int ans[N], par[N], depth[N], head[N], pos[N];
vec<int> heavy(N, - 1);
int t = 0;
vec<pair<ll, int>> g[N];
int dfs(int u) {
    int size = 1;
    int max_size = 0;
    for (auto [w, v]: g[u]) if (v != par[u]) {
        par[v] = u;
        depth[v] = depth[u] + 1;
        int cur_size = dfs(v);
        size += cur_size;
        if (cur_size > max_size) {
            max_size = cur_size;
            heavy[u] = v; 
        }
    }
    return size;
}
void decompose(int u, int h){
    head[u] = h;
    pos[u] = t ++;
    if (heavy[u] != -1){ decompose(heavy[u], h); }
    for (auto [w, v]: g[u]) if (v != par[u] ) {
        if (v != heavy[u]) {
            decompose(v, v);
        }
        st.update(pos[v], pos[v], w);
    }
}
void query(int a, int b) {
    for (; head[a] != head[b]; b = par[head[b]]){ // Subi todo el heavy path y a su padre // Next
        if (depth[head[a]] > depth[head[b]]) swap(a, b);
        st.updateXor(pos[head[b]], pos[b]); // pos[head[b]] < pos[b]
    }
    if (depth[a] > depth[b]) swap(a, b); // Una vez misma path(head) entonces es una query [a,b]
    st.updateXor(pos[a]+ 1, pos[b]);
}


void solve()
{
    int n, m; cin >> n >> m;
    L(i,1, n){
        int u, v; ll w; cin >> u >> v >> w;
        u --; v -- ;
        g[u].eb(w, v);
        g[v].eb(w, u);
    }

    int root = 0;
    dfs(root);
    decompose(root, root);
    while(m--)
    {
        int u, v; cin >> u >> v;
        u --; v--;
        query(u, v);
        cout << st.query(0, N - 1) << "\n";
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