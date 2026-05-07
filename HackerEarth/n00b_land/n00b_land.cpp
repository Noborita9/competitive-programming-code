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
    vec<ll> st; int k;
    ST(int n): k(1) {
        while(k<=n)k<<=1;
        st.assign(2*k, 0);
    }
    void upd(int l, int r, ll w) {
        for (l += k, r += k; l < r; l >>= 1, r >>= 1){
            if (l & 1) st[l++] += w;
            if (r & 1) st[--r] += w;
        }
    }
    ll query(int x) {
        ll sm = 0;
        for (x += k; x; x >>= 1) sm += st[x];
        return sm;
    }
};

void solve()
{
    int n, m; cin >> n >> m;
    vec<vec<int>> g(n);
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
    vec<int> ans(m, -1);

    vec<int> eul, pos(n), sz(n); vec<ll> depth(n);
    eul.reserve(n);
    auto euler = [&](auto && dfs, int u) -> void {
        pos[u] = SZ(eul);
        eul.pb(u);
        sz[u] = 1;
        for (int v: g[u]) {
            depth[v] = depth[u] + 1LL;
            dfs(dfs, v);
            sz[u] += sz[v];
        }
    };
    euler(euler, 0);
    ST st(n), stm(n);
    // solve here
    int t_cur = 0;
    auto t_upd = [&](int i_q, ll mp) {
        int u = F[i_q]-1;
        int l = pos[u];
        int r = l + sz[u];
        st.upd(l, r, (X[i_q] - depth[u] * D[i_q]) * mp); // to add/erase
        stm.upd(l, r, mp * D[i_q]);
    };
    auto t_query = [&](int x) {
        int v = pos[x];
        ll base = st.query(v);
        ll mp = stm.query(v);
        return base + depth[x]*mp;
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
                sm += t_query(w);
                if (sm >= need[o]) break;
            }
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