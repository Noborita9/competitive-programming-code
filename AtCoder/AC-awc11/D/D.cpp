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
    int n, q; cin >> n >> q;
    vec<ll> a(n), ans(n);
    vec<int> par(n, -1);
    L(i,0,n) cin >> a[i];
    vec<vec<int>> ch(n);
    L(i, 1, n) {
        cin >> par[i];
        par[i] --;
        ch[par[i]].pb(i);
    }
    auto calc = [&](auto && dfs, int u, ll acc) -> void {
        acc += a[u];
        ans[u] = acc;
        for (int v: ch[u]) dfs(dfs, v, acc);
    };
    calc(calc, 0, 0ll);
    L(qi,0,q){
        int x; cin >> x;
        x --;
        cout << ans[x] << "\n";
    }
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