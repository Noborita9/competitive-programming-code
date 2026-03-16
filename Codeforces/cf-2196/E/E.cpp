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
    vec<ll> a(n), b(m);
    L(i,0,n) cin >> a[i];
    L(i,0,m) cin >> b[i];
    sort(ALL(a), greater<ll>());
    sort(ALL(b), greater<ll>());
    if (a[0] > b[0]) {
        cout << "No\n";
        return;
    }
    ll n_masks = (1ll << n);
    vec<ll> cost(n_masks);
    L(mask,0,n_masks) {
        L(i,0,n) if (mask & (1<<i)) {
            cost[mask] += a[i];
        }
    }
    vec<int> dp(n_masks, m + 1);
    dp[0] = 0; // levar 0 paquetes toma 0 camiones
    L(mask, 0, n_masks) {
        if (dp[mask] >= m) continue; // Conf no valida o no hay suficientes camiones
        int cur = dp[mask];
        ll cap = b[cur];
        int rem = (n_masks-1) & (~mask); // todas - cubro
        for (int s = rem; s > 0; s=(s-1)&rem){
            if (cost[s] <= cap){
                int next_mask = s | mask;
                dp[next_mask] = min(dp[next_mask], cur + 1);
            }
        }
    }

    if (dp[n_masks - 1] <= m) {
        cout << "Yes" << "\n";
        return;
    }
    cout << "No\n";
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