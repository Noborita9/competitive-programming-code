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
    int n; cin >> n;
    vec<int> a(n); L(i,0,n) cin >> a[i];
    // map<int,int> freq;
    // int mx = 0;
    // L(i,0,n) mx = max(mx, ++freq[a[i]]);
    // if (mx == 1){
    //     L(i,0,n){
    //         cout << "No\n";
    //     }
    //     return;
    // }
    // Sure somewhere happens
    vec<vec<int>> g(n);
    L(i,1,n){
        int u, v; cin >> u >> v;
        u --; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    unordered_map<int,int> freq;
    vec<int> ans(n, -1);
    auto calc = [&](auto && dfs, int u, int p, int cur) -> void {
        if (freq[a[u]] == 1) cur = 1;
        freq[a[u]] ++;
        ans[u] = cur;
        for (int v: g[u]) if (v != p){
            dfs(dfs, v, u, cur);
        }
        freq[a[u]] --;
    };
    calc(calc, 0, - 1, 0);
    L(i,0,n) cout << (ans[i]? "Yes": "No") << "\n";
    // vec<unordered_map<int,int>> h(n);
    // int sm = n;
    // vec<int> hix(n);
    // int cix = 0;
    // vec<int> sz(n + 1);
    // auto smt = [&](auto && dfs, int u, int p, int d) -> int {
    //     sz[u] = 1;
    //     if (p != -1 && SZ(g[u]) == 1) {
    //         hix[u] = cix;
    //         h[cix][a[u]] = d; // which depth i found the element
    //         cix ++;
    //         return sz[u];
    //     }
    //     int bix = n;
    //     for (int v: g[u]) if (v != p){
    //         int csz = dfs(dfs, v, u, d + 1);
    //         sz[u] += csz;
    //         if (csz > sz[bix]) bix = v;
    //     }
    //     hix[u] = hix[bix];
    //     // I take my biggest children data
    //     for (int v: g[u]) if (v != p && v != bix) {
    //         // it's a small children
    //         for (auto [k, dp]: h[hix[v]]) {
    //             if (h[hix[u]][k]) {
    //                 sm = min(sm, (dp - d) + (h[hix[u]][k] - d) + 1);
    //                 h[hix[u]][k] = min(h[hix[u]][k], dp);
    //             } else {
    //                 h[hix[u]][k] = dp;
    //             }
    //         }
    //     }

    //     // Now I add myself to equation
    //     if (h[hix[u]][a[u]]) sm = min(sm, h[hix[u]][a[u]] - d + 1);
    //     h[hix[u]][a[u]] = d;
    //     return sz[u];
    // }; // que hermoso, lastima que no sirve para responder el problema aaasjdajsdjasjdjasjdajsdjasjdkasdjklsadj
    // smt(smt, 0, -1, 1);
    // cout << sm << "\n";
    // L(i,0,sm - 1) {
    //     cout << "No\n";
    // }
    // L(i,0,n-sm + 1){
    //     cout << "Yes\n";
    // }
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