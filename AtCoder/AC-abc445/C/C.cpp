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
    vec<vec<int>> back(n);
    vec<int> ans(n, -1);
    vec<int> a(n);
    L(i,0,n){
        cin >> a[i];
        a[i] --;
        back[a[i]].pb(i);
    }
    for (int i = n - 1; i >= 0; i --){
        if (a[i] == i) ans[i] = i;
        else ans[i] = ans[a[i]];
    }
    // auto go = [&](auto && dfs, int u) -> void {
    //     for (int v: back[u]) if (ans[v] == -1){
    //         ans[v] = ans[u];
    //         dfs(dfs, v);
    //     }
    // };
    // for (int i = n - 1; i >= 0; i --){
    //     if (ans[i] == -1){
    //         ans[i] = i;
    //         go(go, i);
    //     }
    // }
    L(i,0,n) cout << ans[i] + 1 << " ";
    cout << "\n";
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