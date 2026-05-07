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
    int n; ll d; int s, t; cin >> n >> d >> s >> t;
    vec<ll> x(n), y(n);
    L(i,0,n) cin >> x[i] >> y[i];
    d *= d; // d ^ 2
    vec<vec<int>> g(n);
    L(i,0,n){
        L(j,i+1,n){
            ll dx = x[i] - x[j];
            ll dy = y[i] - y[j];
            if (dx * dx + dy * dy <= d) {
                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }
    vec<int> dist(n, n + 10);
    s --; t --;
    dist[s] = 0;
    vec<int> q;
    q.pb(s);
    L(i,0,SZ(q)){
        int u = q[i];
        for (int v: g[u]) if (dist[v] > dist[u] + 1){
            dist[v] = dist[u] + 1;
            q.pb(v);
        }
    }
    // L(i,0,n) cout << dist[i] << " "; cout << "\n";
    cout << (dist[t] == n + 10 ? -1: dist[t]) << "\n";
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