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
    int n, m; cin >> n >> m;
    vec<set<int>> g(n + 1); 
    int tot = 0;
    L(i,0,m)
    {
        int u, v; cin >> u >> v;
        if (g[v].find(u) != end(g[v])) {
            tot ++;
        }
        g[u].insert(v);
    }
    cout << tot << "\n";
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