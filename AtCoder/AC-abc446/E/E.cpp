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
    int m, a, b; cin >> m >> a >> b;
    queue<int> q;
    vec<int> vis(m * m);
    vec<vec<int>> edges(m * m);
    L(i,0,m){
        L(j,0,m){
            // (i, j) -> (j, A*i + B*j)//(j,k)
            int k = (b*i + a*j) % m;
            edges[j * m + k].pb(i * m + j);
            if (i == 0 || j == 0){
                vis[i * m + j] = 1;
                q.push(i * m + j);
            }
        }
    }
    while(SZ(q)){
        int u = q.front(); q.pop();
        for (int v: edges[u]){
            if (!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    int ans = 0;
    L(i,0,m * m){
        if (!vis[i]) ans ++;
    }
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