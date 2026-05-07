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

struct node {
    ll len, ans, delta, x;
};

node merge(node a, node b){
    node n = node{
        a.len + b.len,
        b.ans + a.ans  + (a.delta * b.len),
        a.delta + b.delta,
        a.x + b.x
    };
    return n;
}

const int N = 5e5 + 10;


struct ST {
    vec<node> st; int k;
    ST(int n): k(1){
        while(k<=n)k<<=1;
        st.assign(k*2,{1,0,0,0}); // only 3 data points
        // cout << k << "\n";
        for (int i = k - 1; i > 0; i--) st[i] = merge(st[2*i], st[2*i + 1]);
    }
    void upd(int i, ll x, ll d) {
        i += k;
        st[i].x += x;
        st[i].delta += d;
        st[i].ans += x;
        while(i >>= 1) st[i] = merge(st[2*i], st[2* i + 1]);
    }
    ll query(int l, int r, ll len){
        node ql = {0,0,0,0};
        node qr = {0,0,0,0};
        for (l += k, r += k; l < r; l >>= 1, r >>= 1){
            if (l & 1) ql = merge(ql, st[l++]);
            if (r & 1) qr = merge(st[--r], qr);
        }
        // cout << "QL: " << ql.len << " " << ql.ans << " " << ql.delta << " " << ql.x << "\n";
        // cout << "QR: " << qr.len << " " << qr.ans << " " << qr.delta << " " << qr.x << "\n";
        ql = merge(ql, qr);
        // cout << "QL: " << ql.len << " " << ql.ans << " " << ql.delta << " " << ql.x << "\n";
        return ql.ans + ql.delta * len;
    }
} st(N);

int par[N], depth[N], head[N], pos[N];
vec<int> heavy(N, - 1);
int t = 0;
vec<int> g[N];
int dfs(int u) {
    int size = 1;
    int max_size = 0;
    for (int v: g[u]) if (v != par[u]) {
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
    for (int v: g[u]) if (v != par[u] && v != heavy[u]) {
        decompose(v, v);
    }
}

ll query(int a) {
    int rt = a;
    int b = 0; // root always
    ll resp = 0;
    ll len = 0;
    for (; head[a] != head[0]; a = par[head[a]]){ // Subi todo el heavy path y a su padre // Next
        len = depth[rt] - depth[a];
        // cout << "IN: "<< len << " " << depth[rt] << " " << depth[a] << "\n";
        resp = resp + st.query(pos[head[a]], pos[a] + 1, len); // pos[head[b]] < pos[b]
    }
    // cout << a << " " << rt << "\n";
    len = depth[rt] - depth[a];
    // cout << len << " " << depth[rt] << " " << depth[a] << "\n";

    // cout << "STQ: " << 0 <<", " << pos[a] << "\n";
    resp = resp + st.query(0, pos[a] + 1, len);
    return resp;
}

void solve()
{
    int n, m; cin >> n >> m;
    L(i,1,n){
        int p; cin >> p; p --;
        g[p].pb(i);
    }
    vec<vec<int>> who(n);
    L(i,0,n){
        int p; cin >> p;
        who[p-1].pb(i);
    }
    vec<ll> need(n);
    L(i,0,m) cin >> need[i];
    int q; cin >> q;
    vec<ll> F(q+1), X(q+1), D(q+1);
    L(i,0,q) cin >> F[i+1] >> X[i+1] >> D[i+1];
    int root = 0;
    dfs(root);
    decompose(root, root);
    vec<int> ans(n, -1);
    // L(i,0,n) {
    //     cout << pos[i] << " " << head[i] << "\n";
    // }

    // solve here
    int t_cur = 0;
    auto t_upd = [&](int i_q, ll mp) {
        // cout << "Update: " << F[i_q] << " " << pos[F[i_q]-1] << "\n";
        st.upd(pos[F[i_q]-1], X[i_q] * mp, D[i_q] * mp);
        // cout << "Cur tree: " << t_cur << "\n";
        // ll qv = query(2);
        // cout << "Q(2): " << qv << "\n";
    };
    auto calc = [&](auto && rec, int low, int high, vec<int> &own) -> void {
        if (own.empty()) return;
        int mid = (low + high) / 2;
        while (t_cur < mid) t_upd(++t_cur, 1);
        while (t_cur > mid) t_upd(t_cur--, -1);
        vec<int> left, right;
        for (int o: own){
            ll sm = 0;
            for (int w: who[o]) {
                sm += query(w);
                if (sm >= need[o]) break;
            }
            // cout << sm << "\n";
            if (sm >= need[o]) {
                left.pb(o);
                ans[o] = mid;
            } else right.pb(o);
        }
        own.clear();
        if (low < high){
            rec(rec, low, mid, left);
            rec(rec, mid + 1, high, right);
        }
    };
    vec<int> owners(m);
    iota(ALL(owners), 0);
    calc(calc, 1, q, owners);
    // cout << "Cur tree: " << t_cur << "\n";
    ll qv = query(2);
    // cout << "Q(2): " << qv << "\n";
    L(i,0,m) {
        if (ans[i] == -1) cout << "rekt\n";
        else cout << ans[i] << "\n";
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