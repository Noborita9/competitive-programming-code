#include <bits/stdc++.h>
#include <cassert>
using namespace std;

#define L(i, j, n) for (int i = (j); i < (int)n; i ++)
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define vec vector
#define pb push_back
#define eb emplace_back

using ll = long long;
using ld = long double;

void solve()
{
    int n, m; cin >> n >> m;
    vec<vec<int>> g(n);
    L(i,0,m){
        int u, v; cin >> u >> v;
        u --; v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    vec<int> ci(n);
    vec<bool> vis(n);
    auto mark = [&](auto && dfs, int u, int cc, int &sz) -> void {
        vis[u] = 1;
        sz ++;
        ci[u] = cc;
        for (int v: g[u]) if (!vis[v]) dfs(dfs, v, cc, sz);
    };
    int cn = 0;
    vec<int> csz;
    L(i,0,n) if (!vis[i]){
        csz.pb(0);
        mark(mark, i, cn ++, csz.back());
    }
    const int oo = 1e9;
    vec<int> mx(n);
    vec<int> mxc(cn, oo);
    vec<int> mxci(cn, -1);
    L(i,0,n){
        vec<int> dist(n);
        vis.assign(n, 0);
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        dist[i] = 0;
        while(SZ(q)) {
            int u = q.front(); q.pop();
            for (int v: g[u]) if (!vis[v]) {
                vis[v] = 1;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        mx[i] = *max_element(ALL(dist));
        if (mx[i] < mxc[ci[i]]) {
            mxc[ci[i]] = mx[i];
            mxci[ci[i]] = i;
        }
    }
    int mp = mxci[0];
    assert(mp != -1);
    vec<pair<int,int>> e;
    L(i,1,cn) {
        if (mxc[ci[mp]] < mxc[ci[mxci[i]]]) {
            mp = mxci[i];
        }
    }
    L(i,0,cn)if (mxci[i] != mp) {
        int cp = mxci[i];
        assert(cp != -1);
        g[mp].eb(cp);
        g[cp].eb(mp);
        e.eb(mp, cp);
    }

    vec<int> dist(n);
    vis.assign(n, 0);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    dist[0] = 0;
    while(SZ(q)) {
        int u = q.front(); q.pop();
        for (int v: g[u]) if (!vis[v]) {
            vis[v] = 1;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    int j = max_element(ALL(dist)) - begin(dist);
    dist.assign(n, 0);
    vis.assign(n, 0);
    q.push(j);
    vis[j] = 1;
    dist[j] = 0;
    while(SZ(q)) {
        int u = q.front(); q.pop();
        for (int v: g[u]) if (!vis[v]) {
            vis[v] = 1;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    int diam = *max_element(ALL(dist));
    cout << diam << "\n";
    for (auto [u, v]: e) cout << u + 1 << " " << v + 1 << "\n";
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