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
const int N = 3e5 + 10;
vec<int> g[N];
const int K = 20; // K should be (1<<K) > n
int up[K][N]; // Inicializar en -1
int depth[N]; // dist(u,v)=depth[u]+depth[v]-2*depth[lca]
void dfslca(int u, int p){
    for (int v: g[u]) if (v != p) {
        up[0][v] = u;
        L(i, 1, K) {
            if (up[i - 1][v] != -1) {
                up[i][v] = up[i - 1][up[i - 1][v]];
            }
        }    
        depth[v] = depth[u] + 1;
        dfslca(v, u);
    }
}
int LCA(int u, int v){
    if (depth[u] < depth[v]) swap(u, v); // Make u the deepest
    for (int i= K-1; i>=0; i--){ // make them same depth
        if (up[i][u] != -1 && depth[up[i][u]] >= depth[v]){ 
            u = up[i][u];
        }
    }
    if (u == v) return u; // u is parent of v
    for (int i= K-1; i>=0; i--){
        if (up[i][u] != up[i][v] && up[i][u] != -1 && up[i][v] != -1){
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}
int dist(int u, int v, int lca) {
    return depth[u] + depth[v] - 2 * depth[lca];
}
int jump(int u, int d){
    if (d <= 0) return u;
    for (int i= K-1; i>=0; i--){
        if (d & (1<< i)){
            u = up[i][u];
        }
    }
    return u;
}

using iii = tuple<int,int,int,int,int>;
// u, v, lca, cu, cv

void solve()
{
    int n; cin >> n;
    memset(up, -1, sizeof(up));
    L(i,1,n){
        int u, v; cin >> u >> v;
        u --; v --;
        g[u].eb(v); g[v].eb(u);
    }
    dfslca(0, -1);
    int q; cin >> q;
    vec<ll> dt(n);
    vec<vec<iii>> qs(n);
    vec<ll> cnt_a(n), tot_a(n);
    map<pair<ll,ll>, ll> h;
    L(i,0,q)
    {
        int u, v; cin >> u >> v;
        u --; v--;
        int t = LCA(u, v);
        dt[u] ++;
        dt[v] ++;
        dt[t] -= 2;
        int cu = jump(u, dist(u, t, t) - 1);
        int cv = jump(v, dist(v, t, t) - 1);
        qs[t].eb(u, v, t, cu, cv);
        if (t != u && t != v) h[{min(cu, cv), max(cu, cv)}] ++;
        tot_a[t] ++;
        if (t != u) cnt_a[cu] ++;
        if (t != v) cnt_a[cv] ++;
    }
    vec<ll> cnt_b(n);
    auto go = [&](auto && dfs, int u, int p = -1) -> void {
        for (int v: g[u]) if (v != p){
            dfs(dfs, v, u);
            cnt_b[u] += cnt_b[v];
        }
        cnt_b[u] += dt[u];
    };
    go(go, 0);
    ll ans = 0;
    L(i,0,n)
    {
        ll sma = 0;
        ll smb = 0;
        for (const auto &[u, v, t, cu, cv]: qs[i]) {
            sma += tot_a[i];
            smb += cnt_b[i];
            if (t != u && t != v) {
                sma += - cnt_a[cu] - cnt_a[cv] + h[{min(cu, cv), max(cu, cv)}];
                smb += - (cnt_b[cv] - cnt_a[cv]) - (cnt_b[cu] - cnt_a[cu]);
            } else if (t != u) {
                sma += - cnt_a[cu];
                smb += - (cnt_b[cu] - cnt_a[cu]);
            } else if (t != v) {
                sma += - cnt_a[cv];
                smb += - (cnt_b[cv] - cnt_a[cv]);
            }
            if (u == v) sma --;
        }
        ans += sma / 2;
        ans += smb;
    }
    // L(i,0,n) cout << cnt_b[i] << " "; cout << "\n";
    cout << ans << "\n";
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