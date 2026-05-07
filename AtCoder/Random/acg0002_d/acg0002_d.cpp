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

struct DSU {
    vec<int> par, sz;
    DSU(int n): par(n), sz(n, 1) {iota(ALL(par), 0);}
    int find(int a){return a == par[a] ? a : par[a] = find(par[a]);}
    void join(int a, int b){
        a=find(a);b=find(b);
        if (a==b)return;
        if(sz[b]>sz[a])swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
    }
};

struct query {
    int l, r, x, y, z, ix;
};


void solve()
{
    int n, m; cin >> n >> m;
    vec<pair<int,int>> edges; edges.reserve(m+1); edges.eb(-1,-1);
    L(i,0,m){
        int u, v; cin >> u >> v;
        u --; v --;
        edges.eb(u, v);
    }    
    int q; cin >> q;
    vec<query> qs(q);
    vec<int> ans(q);
    L(i,0,q){
        int x, y, z; cin >> x >> y >> z;
        qs[i] = {1, m, x - 1, y - 1, z, i};
    }
    int k = 1;
    while((1<<k)<=m)k++;
    L(it_,0,k) {
        DSU ds(n);
        sort(ALL(qs), [](const query &lhs, const query &rhs) {
            return (lhs.l + lhs.r) / 2 < (rhs.l + rhs.r) / 2;
        });
        int i_q = 0;
        L(i_e,1,m+1){
            ds.join(edges[i_e].first, edges[i_e].second);
            while (i_q < q && (qs[i_q].l + qs[i_q].r)/2 == i_e) {
                int px = ds.find(qs[i_q].x);
                int szi = ds.sz[px];
                int py = ds.find(qs[i_q].y);
                if (py != px) szi += ds.sz[py];
                if (szi >= qs[i_q].z) qs[i_q].r = (qs[i_q].l + qs[i_q].r) / 2;
                else qs[i_q].l = ((qs[i_q].l + qs[i_q].r) / 2) + 1;
                i_q ++;
            }
        }
    }
    // L(i,0,q) cout << qs[i].l << " " << qs[i].r << "\n";
    L(i,0,q) ans[qs[i].ix] = qs[i].l;
    L(i,0,q) cout << ans[i] << "\n";
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