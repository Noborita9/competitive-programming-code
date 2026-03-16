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

using ii = pair<int, int>;
void solve()
{
    int n, k; cin >> n >> k;
    if (n == 1){
        cout << "0\n";
        return;
    }
    vec<vec<ii>> g(n);
    L(i, 1, n ){
        int u, v, d; cin >> u >> v >> d;
        u --; v--;
        g[u].eb(v, d);
        g[v].eb(u, d);
    }
    auto dist = [&](auto && dfs, int u, int p, vec<int>&di, vec<int> &prev) -> void {
        for (const auto &[v, d]: g[u]) if (v != p) {
            di[v] = di[u] + d;
            prev[v] = u;
            dfs(dfs, v, u, di, prev);
        }
    };
    vec<int> d(n), prev(n, -1);
    dist(dist, 0, -1, d, prev);
    int l = max_element(ALL(d)) - begin(d);
    prev[l] = -1;
    d[l] = 0;
    dist(dist, l, -1, d, prev);
    int r = max_element(ALL(d)) - begin(d);
    vec<int> path;
    for (int x = r; x != -1; x = prev[x]) path.pb(x);
    reverse(ALL(path));
    int ln = SZ(path);
    vec<int> mx(ln);
    L(i, 1, ln - 1) { // fill the middle
        int mxi = 0;
        auto mxcmp = [&](auto && dfs, int u, int p, int dp) -> void {
            mxi = max(mxi, dp);
            for (const auto &[v, di]: g[u]) if (v != path[i -1] && v != path[i + 1] && v != p) {
                dfs(dfs, v, u, dp + di);
            }
        };
        mxcmp(mxcmp, path[i], -1, 0);
        mx[i] = mxi;
    }
    deque<ii> dq;
    k = min(k, ln);
    L(i,0,k){
        while(SZ(dq) && dq.back().first <= mx[i]) dq.pop_back();
        dq.eb(mx[i], i);
    }
    int ans = 2e9;
    for (int i = k; i <= ln; i ++) {
        ans = min(ans,
            max({
            d[path[i - k]],
            d[r] - d[path[i - 1]],
            dq.front().first}));
        if (i != ln) {
            while(SZ(dq) && dq.front().second < i - k) dq.pop_front();
            while (SZ(dq) && dq.back().first <= mx[i]) dq.pop_back();
            dq.eb(mx[i], i);
        }
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