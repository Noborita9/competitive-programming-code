#include <bits/stdc++.h>
using namespace std;

#define L(i,j,n) for (int i = (j); i < (int)n; i ++)
#define pb push_back
#define vec vector
#define ALL(x) begin(x),end(x)
#define SZ(x) int(x.size())
#define eb emplace_back

using ll = long long;
using ld = long double;

const ld EPS = 1e-6;

void solve()
{
    ld X, Y; cin >> X >> Y;
    ll n; cin >> n;
    vec<ld> x(n), y(n);
    L(i,0,n) cin >> x[i] >> y[i];
    ld lo = 0;
    ld hi = 1e9;
    auto dist = [&](ld x1, ld y1, ld x2, ld y2) -> ld {
        ld dx = x1 - x2;
        ld dy = y1 - y2;
        return sqrt(dx * dx + dy * dy);
        // return hypot(x1 - x2, y1 - y2);
    };
    
    auto check = [&](ld t) -> bool {
        vec<vec<int>> g(n);
        vec<int> comp(n);
        L(i,0,n)
        {
            if (dist(0, 0, x[i], y[i]) < t) return false;
            if (dist(X, Y, x[i], y[i]) < t) {return false;}
            L(j,i + 1,n) if (dist(x[j], y[j], x[i], y[i]) + EPS < t*2.0) {
                g[i].pb(j);
                g[j].pb(i);
            }
        }
        // cout << "Returned\n";
        int cmp = 0;
        vec<int> vis(n);
        vec<vec<int>> gc(n);
        auto go = [&](auto && dfs, int u) -> void {
            if (vis[u]) return;
            vis[u] = 1;
            comp[u] = cmp;
            gc[comp[u]].pb(u);
            for (int v: g[u]) if (!vis[v]) dfs(dfs, v);
        };
        L(j,0,n) {
            go(go, j);
            cmp++;
        }
        for (auto compo: gc) {
            if (compo.empty()) continue;
            bool up = 0, left = 0, right = 0, down = 0;
            for (int u: compo) {
                up |= dist(x[u], Y, x[u], y[u]) < t;
                down |= dist(x[u], 0, x[u], y[u]) < t;
                left |= dist(0, y[u], x[u], y[u]) < t;
                right |= dist(X, y[u], x[u], y[u]) < t;
            }
            if (left && right) return false;
            if (up && down) return false;
            if (left && down) return false;
            if (right && up) return false;
        }
        // cout << "Here\n";
        // L(j,0,n) cout << comp[j] << " ";
        // cout << "\n";
        return true;
    };
    while (abs(lo - hi) >= EPS) {
        ld md = (lo + hi) / 2.0;
        if (check(md)){
            lo = md;
        } else {
            hi = md;
        }
    }
    ld ans = (lo + hi) / 2.0;
    cout << fixed << setprecision(10) << ans << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    // cin >> TT;
    while(TT--)
    {
        solve();
    }
}