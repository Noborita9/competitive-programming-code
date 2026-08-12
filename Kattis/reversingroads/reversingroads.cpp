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

int n, m;
multiset<int> g[55];
vec<pair<int,int>> e(2500);
void solve()
{
    L(i,0,n) g[i].clear();
    L(i,0,m){
        int u, v; cin >> u >> v;
        e[i] = {u, v};
        g[u].insert(v);
    }
    auto check = [&]() -> bool {
        bool va = 1;
        L(i,0,n){
            vec<bool> vis(n, 0);
            int vs = 1;
            queue<int> q; q.push(i);
            vis[i] = 1;
            while(SZ(q)) {
                int u = q.front(); q.pop();
                for (int v: g[u]) if (!vis[v]){
                    vis[v] = 1;
                    vs ++;
                    q.push(v);
                }
            }

            va = vs == n;
            if (!va) break;
        }
        return va;
    };

    if (check()) {
        cout << "valid\n";
        return;
    }
    // try all
    L(i,0,m)
    {
        auto [u, v] = e[i];
        g[u].erase(g[u].find(v));
        g[v].insert(u);

        if (check()) {
            cout << u << " " << v << "\n";
            return;
        }
        
        g[v].erase(g[v].find(u));
        g[u].insert(v);
    }

    cout << "invalid\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    //cin >> TT;
    while (1)
    {
        if (!cin.good() || cin.eof()) break;
        cin >> n;
        if (!cin.good() || cin.eof()) break;
        cin >> m;
        cout << "Case " << TT << ": ";
        solve();
        TT ++;
    }
}