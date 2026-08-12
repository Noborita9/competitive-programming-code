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

const int oo = 1e9;
const int N = 2e5 + 5;
struct ST {
    vec<pair<int,int>> st; int k;
    ST(int n): k(1){
        while(k<n)k<<=1;
        st.assign(2*k, {oo, oo});
    }
    void upd(int i, int w, int ix){
        st[i += k] = {w, ix};
        while(i>>=1)st[i]=min(st[2*i],st[2*i+1]);
    }
    pair<int,int> query(int l, int r){
        pair<int,int> ans = {oo, oo};
        for(l+=k, r+=k; l< r; l>>=1,r>>=1){
            if(l&1)ans=min(ans,st[l++]);
            if(r&1)ans=min(ans,st[--r]);
        }
        return ans;
    }
} st(N*2);

struct LCA {
    vec<int> depth, in, tin, tout, sz, euler;
    vec<vec<int>> g, st;
    int K, n, t;
    inline int Min(int i, int j) {return depth[i] <= depth[j] ? i : j;}
    void dfs(int u, int p) {
        tin[u] = t ++;
        in[u] = SZ(euler);
        sz[u] = 1;
        euler.pb(u);
        for (int v: g[u]) if (v != p){
            depth[v] = depth[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
            euler.pb(u);
        }
        tout[u] = t ++;
    }
    LCA(int n_): depth(n_), in(n_), tin(n_), tout(n_), sz(n_, 0), g(vec<vec<int>>(n_)), K(0), n(n_), t(0) { euler.reserve(2 * n); }
    void add_edge(int u, int v) {g[u].pb(v);}
    void build(int root){
        dfs(root, -1);
        int ln = SZ(euler);
        while((1<<K)<=ln)K++;
        st = vec<vec<int>> (K, vec<int>(ln));
        L(i,0,ln) st[0][i] = euler[i];
        for (int i = 1; (1 << i) <= ln; i ++) {
            for (int j = 0; j + (1<<i) <= ln; j ++) {
                st[i][j] = Min(st[i-1][j], st[i-1][j + (1<<(i-1))]);
            }
        }
    }
    int get(int u, int v) {
        int su = in[u];
        int sv = in[v];
        if (sv < su) swap(sv, su);
        int bit = log2(sv - su + 1);
        return Min(st[bit][su], st[bit][sv - (1<<bit) + 1]);   
    }
} lca(N);

const int K = 18;
int up[K][N];

struct STS {
    vec<int> st; int k;
    STS(int n): k(1){
        while(k<n)k<<=1;
        st.assign(2*k, 0);
    }
    void upd(int i, int w){
        st[i += k] += w;
        while(i>>=1)st[i]=st[2*i]+st[2*i+1];
    }
    int query(int l, int r){
        int ans = 0;
        for(l+=k, r+=k; l< r; l>>=1,r>>=1){
            if(l&1)ans+=st[l++];
            if(r&1)ans+=st[--r];
        }
        return ans;
    }
};

using iii = tuple<int, int, int, int, int>;
// {x, IN | BUS | OUT, l, r, ix}

void solve()
{
    const int IN = 0;
    const int BUS = 1;
    const int OUT = 2;
    int n; cin >> n;
    vec<int> p(n, -1);
    vec<vec<int>> ch(n);
    memset(up, -1, sizeof(up));
    L(i,1,n){
        cin >> p[i]; p[i] --;
        ch[p[i]].eb(i);
        lca.add_edge(p[i], i);
    }
    // LCA around here
    lca.build(0);
    
    int m; cin >> m;
    vec<int> mn(n, -1);
    vec<set<int>> popu(n);
    vec<pair<int,int>> buses; buses.reserve(m);
    L(i,0,m)
    {
        int u, v; cin >> u >> v;
        u --; v--;
        buses.eb(u, v);
        int tg = lca.get(u, v);
        int dp = lca.depth[tg];
        if (mn[u] == -1) {
            mn[u] = tg;
            popu[tg].insert(u);
        }
        else if (lca.depth[mn[u]] > dp) {
            popu[mn[u]].erase(u);
            mn[u] = tg;
            popu[tg].insert(u);
        }
        if (mn[v] == -1) {
            mn[v] = tg;
            popu[tg].insert(v);
        }
        else if (lca.depth[mn[v]] > dp) {
            popu[mn[v]].erase(v);
            mn[v] = tg;
            popu[tg].insert(v);
        }
    }
    
    auto go = [&](auto && dfs, int u) -> void {
        for (int v: ch[u]) {
            dfs(dfs, v);
        }
        if (mn[u] != -1) // enter node
        {
            st.upd(lca.tin[u], lca.depth[mn[u]], mn[u]);
        }
        // query
        auto [bdp, bix] = st.query(lca.tin[u], lca.tout[u]);
        if (bdp != oo) {
            up[0][u] = bix;
        }
        // erase ending here
        for (int pu: popu[u]) st.upd(lca.tin[pu], oo, oo);
    };
    go(go, 0);
    
    L(bit, 1, K){
        L(j,0,n) {
            if (up[bit-1][j] == -1) continue;
            up[bit][j] = up[bit-1][up[bit-1][j]];
        }
    }    
    int q; cin >> q;
    vec<int> ans(q, -1);
    STS sts(lca.t + 5);
    // Puedo ir con un solo bondi desde u a v ?
    vec<iii> E; E.reserve(2 * q + m);
    L(i,0,m)
    {
        E.eb(lca.tin[buses[i].first], BUS, lca.tin[buses[i].second], -1, -1);
        E.eb(lca.tin[buses[i].second], BUS, lca.tin[buses[i].first], -1, -1);
    }
    L(i,0,q)
    {
        int u, v; cin >> u >> v; u --; v--;
        int target = lca.get(u, v);
        bool ulca = target == u;
        bool vlca = target == v;
        int ansU = 0;
        for (int bit = K - 1; bit >= 0; bit --) 
        if (up[bit][u] != u && up[bit][u] != -1 && lca.depth[up[bit][u]] > lca.depth[target])
        {
            ansU += 1 << bit; 
            u = up[bit][u];
        }
        int ansV = 0;
        for (int bit = K - 1; bit >= 0; bit --) 
        if (up[bit][v] != v && up[bit][v] != -1 && lca.depth[up[bit][v]] > lca.depth[target])
        {
            ansV += 1 << bit; 
            v = up[bit][v];
        }
        if (ulca) {
            if (up[0][v] == -1 || up[0][v] == v) {
                continue;
            }
            ans[i] = ansV + 1;
            continue;
        } else if (vlca){
            if ((up[0][u] == -1 || up[0][u] == u)) {
                continue;
            }
            ans[i] = ansU + 1;
            continue;
        }
        // Now they are both 1 bus away
        if (u != target && (up[0][u] == -1 || up[0][u] == u)) continue; // u can't reach target
        if (v != target && (up[0][v] == -1 || up[0][v] == v)) continue; // v can't reach target
        // both can reach
        ans[i] = ansU + ansV + 2; 
        if (lca.tin[u] < lca.tin[v]) {
            E.eb(lca.tin[u], IN, lca.tin[v], lca.tout[v], i);
            E.eb(lca.tout[u], OUT, lca.tin[v], lca.tout[v], i);
        } else {
            E.eb(lca.tin[v], IN, lca.tin[u], lca.tout[u], i);
            E.eb(lca.tout[v], OUT, lca.tin[u], lca.tout[u], i);
        }
        // Add the query to check if they can share the last bus
    }
    sort(ALL(E));
    vec<int> qup(q);
    for (const auto &[x, ev, l, r, ix]: E) {
        if (ev == BUS) {
            sts.upd(l, 1);
        } else if (ev == IN) {
            qup[ix] -= sts.query(l, r);
        } else if (ev == OUT) {
            qup[ix] += sts.query(l, r);
        }
    }

    // update ans by -1 if can share last bus
    
    L(i,0,q) cout << ans[i] - (qup[i] > 0) << "\n";
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