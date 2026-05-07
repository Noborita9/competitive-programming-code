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
    int n, m;ll k; cin >> n >> m >> k;
    vec<ll> c(n), p(n); L(i,0,n) cin >> c[i] >> p[i];
    vec<vec<int>> g(n, vec<int>(n, 0));
    L(i,0,m) {
        int u, v; cin >> u >> v;
        u --; v --;
        g[u][v] = g[v][u] = 1;
    }
    
    ll bp = 0;
    int masks = 1<<n;
    L(mask, 1, masks) {
        ll pf = 0;
        ll ct = 0;
        bool pos = 1;
        L(bit,0,n) if (mask & (1<<bit)) {
            ct += c[bit];
            pf += p[bit];
            L(nbit,0,n) if (g[bit][nbit] && (mask & (1<<nbit))) {
                pos = 0;
                break;
            }
            if (!pos) break;
        }
        if (!pos) continue;
        if (ct > k) continue;
        bp = max(bp, pf);
    }


    cout << bp << "\n";
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