#include <bits/stdc++.h>
using namespace std;

#define L(i,j,n) for (int i = (j);i<(int)n; i ++)
#define pb push_back
#define vec vector
#define SZ(x) int(x.size())
#define ALL(x) begin(x),end(x)
#define eb emplace_back

using ll = long long;
using ld = long double;


void solve()
{
    int n, m, t; cin >> n >> m >> t;
    vec<vec<int>> g(n);
    set<int> in;
    L(i,0,m){
        int u, v; cin >> u >> v;
        if (v == t) in.insert(u);
        else g[u].pb(v);
    }
    vec<set<int>> cg(n), rcg(n); // only once each edge
    vec<int> dfs_low(n, -1), dfs_num(n, -1), in_stack(n);
    vec<int> st;
    int dfs_c = 0;
    vec<int> group(n, - 1);
    vec<vec<int>> gcount(n);
    int gn = 0;
    auto tj = [&](auto && dfs, int u, int p) -> void {
        dfs_low[u] = dfs_num[u] = dfs_c ++;
        st.pb(u);
        in_stack[u] = 1;
        for (int v: g[u]) {
            if (v == p) continue;
            if (dfs_num[v] == -1){
                dfs(dfs, v, u);
                dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            } else if (in_stack[v]) dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
        if (dfs_low[u] == dfs_num[u]){
            while(1){
                int v = st.back();
                if (in.find(v) != end(in)) gcount[gn].pb(v);
                group[v] = gn;
                in_stack[v] = 0;
                st.pop_back();
                if (v == u) break;                
            }
            gn ++;
        }
    };
    L(i,0,n) if (i != t && dfs_num[i] == -1){
        tj(tj, i, -1);
    }
    L(u,0,n) if (group[u] != -1){
        for (int v: g[u]) if (group[v] != -1) {
            cg[group[u]].insert(group[v]);
            rcg[group[v]].insert(group[u]);
            // cout << "rev: " << group[v] << " -> " << group[u] << "\n";
        }
    }
    vec<int> topo;
    topo.reserve(n);
    vec<int> vis(n);
    auto dfs1 = [&](auto && dfs, int u) -> void {
        vis[u] = 1;
        for (int v: cg[u]) if (!vis[v]) {
            dfs(dfs, v);
        }
        topo.pb(u);
    };
    L(i,0,n) if (group[i] != -1 && i != t && !vis[group[i]]){
        dfs1(dfs1, group[i]);
    }
    // L(i,0,n) cout << group[i] << " "; cout << endl;
    // cout << "Here topo" << endl;
    vec<int> cproc(n);
    // reverse(ALL(topo));
    // L(i,0,SZ(topo)){
    //     cout << topo[i] << endl;
    // }
    // L(i,0,n)if(group[i] != -1){
    //     cout << i << " -> " << group[i] << ":\n";
    //     for (int v: gcount[group[i]]) cout << v << " ";
    //     cout << "\n";
    // }
    set<int> out;
    L(i,0,SZ(topo)){
        int u = topo[i];
        // cout << "I am on: " << u << " being " << cproc[u] << "\n";
        if (cproc[u]) {
            for (int v: rcg[u]) {
                cproc[v] = 1; // keep expanding the processed chain
            }
            continue;
        }
        if (SZ(gcount[u])) {
            // cout << "Found: " << SZ(gcount[u]) << " w " << gcount[u].back() << "\n";
            cproc[u] = 1;
            for (int v: rcg[u]) {
                cproc[v] = 1;
            }
            if (SZ(gcount[u]) == 1){
                out.insert(gcount[u].back());
            }
        }
    }
    // cout << "\n";
    cout << SZ(out) << "\n";
    for (int o: out){
        cout << o << "\n";
    }
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    // cin >> TT;
    while(TT--){
        solve();
    }
}