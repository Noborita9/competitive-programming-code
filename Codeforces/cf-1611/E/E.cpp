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

void solve()
{
    int n, k; cin >> n >> k;
    queue<int> q;
    vec<vec<int>> g(n);
    const int oo = 1e9;
    vec<int> dist(n, oo);
    L(i,0,k){
        int x; cin >> x;
        x --;
        q.push(x);
        dist[x] = 0;
    }
    L(i,1,n){
        int u, v; cin >> u >> v;
        u --; v--;
        g[u].eb(v);
        g[v].eb(u);
    }
    while(SZ(q)){
        int u = q.front(); q.pop();
        for (int v: g[u]) if (dist[v] >dist[u] + 1){
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    vec<int> vdist(n, oo);
    vdist[0] = 0;
    q.push(0);
    while(SZ(q)){
        int u = q.front(); q.pop();
        for (int v: g[u]) if (vdist[v] > vdist[u] + 1) {
            vdist[v] = vdist[u] + 1;
            q.push(v);
        }
    }
    L(i,1,n) if (SZ(g[i]) == 1 && vdist[i] < dist[i]) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}