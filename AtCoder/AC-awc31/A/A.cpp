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
    int n, m, k; cin >> n >> m >> k;
    vec<int> v(n), c(n);
    vec<vec<int>> t(n);
    L(i,0,n) {
        cin >> v[i] >> c[i];
        L(j,0,c[i]) {
            int x; cin >> x;
            t[i].pb(x - 1);
        }
    }
    vec<int> ord(n);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&](int a, int b){
        if (v[a] != v[b]) return v[a] > v[b];
        return a < b;
    });

    vec<int> used(m);

    L(i,0,k){
        int u = ord[i];
        for (int e: t[u]) used[e] ++;
    }

    int ans = 0;
    L(i,0,m) if (used[i] == k) ans ++;

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