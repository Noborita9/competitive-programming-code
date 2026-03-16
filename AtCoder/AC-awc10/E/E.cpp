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
    int n, k; cin >> n >> k;
    vec<vec<ll>> c(n, vec<ll>(n));
    L(i,0,n) L(j,0,n) cin >> c[i][j];
    ll best = 0;
    // orden original 0..n-1
    vec<int> ord(n);
    iota(ALL(ord),0);
    do {
        // L(i,0,n) cout << ord[i] << " ";
        // cout << "\n";
        ll disp = 0;
        int swaps = 0;
        L(i,0,n) disp += c[ord[i]][ord[(i+1)%n]];
        vec<bool> vis(n);
        L(i,0,n) if (!vis[ord[i]]){
            swaps ++;
            int v = ord[i];
            while (!vis[v]){
                vis[v] = 1;
                v = ord[v];
            }
        }
        if (n - swaps <= k) best = max(disp, best);
    } while (next_permutation(ALL(ord)));

    cout << best << "\n";
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