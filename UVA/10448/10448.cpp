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
vec<vec<pair<int,int>>> g;

bool get(int s, int t, vec<int> & costs, vec<bool> &vis) {
    if (s == t) {
        return true;
    }
    vis[s] = 1;
    for (const auto &[v, c]: g[s]) if(!vis[v]) {
        costs.pb(c);
        bool conn = get(v, t, costs, vis);
        if (conn) return true;
        costs.pop_back();
    }
    return false;
}

void solve()
{
    int n, m; cin >> n >> m;
    g = vec<vec<pair<int,int>>>(n);
    L(i,0,m)
    {
        int u, v, c; cin >> u >> v >> c;
        u --; v--;
        g[u].eb(v, c);
        g[v].eb(u, c);
    }
    int k; cin >> k;
    while(k--)
    {
        int s, t, c; cin >> s >> t >> c;
        if (s == t) {
            if (c == 0) cout << "Yes 0\n";
            else cout << "No\n";
            continue;
        }
        s --; t --;
        vec<int> costs;
        vec<bool> vis(n);
        bool conn = get( s, t, costs, vis);
        if (!conn) {
            cout << "No\n";
            continue;
        }
        int done = accumulate(ALL(costs), 0);
        if (done > c) {
            cout << "No\n";
            continue;
        } else if (done == c) {
            cout << "Yes " << SZ(costs) << "\n";
            continue;
        }
        costs.pop_back(); // I can't use the last edge anymore
        int tg = c - done;
        for (int &co: costs) co *= 2;
        const int oo = 1e9;
        vec<int> dp(tg + 1, oo);
        dp[0] = 0;
        L(p, 1, tg + 1) {
            for (int co: costs) if (p - co >= 0) dp[p] = min(dp[p], dp[p - co] + 2);
        }
        // cout << c << " " << done << "\n";
        // cout << "Got to dp\n";
        if (dp[tg] == oo) cout << "No\n";
        else cout << "Yes " << (dp[tg] + SZ(costs) + 1) << "\n";
    }
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
        if (TT) cout << "\n";
    }
}