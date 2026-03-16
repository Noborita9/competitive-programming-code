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
    int n; ll s; cin >> n >> s;
    if (n <= 20) {
        vec<ll> a(n); L(i,0,n) cin >>a[i];
        ll ansSimple = 0;
        auto backSimple = [&](auto && dfs, int ix, ll sm, int used) -> void {
            if (sm > s) return;
            if (ix == n) {
                ansSimple += sm == s;
                return;
            }
            dfs(dfs, ix + 1, sm + a[ix], used | (1<<ix));
            dfs(dfs, ix + 1, sm, used);
        };
        backSimple(backSimple, 0, 0ll, 0);
        cout << ansSimple << "\n";
    } else {
        vec<ll> a(20);
        L(i,0,20) cin >> a[i];
        int res = n - 20;
        vec<ll> b(res);
        L(i,0,res) cin >> b[i];
        unordered_map<ll, ll> M;
        auto backSimple = [&](auto && dfs, int ix, ll sm, int used) -> void {
            if (sm > s) return;
            if (ix == 20) {
                M[sm]++;
                return;
            }
            dfs(dfs, ix + 1, sm + a[ix], used | (1<<ix));
            dfs(dfs, ix + 1, sm, used);
        };
        backSimple(backSimple, 0, 0ll, 0);
        ll ans = 0;
        auto back = [&](auto && dfs, int ix, ll sm, int used) -> void {
            if (sm > s) return;
            if (ix == res) {
                ans += M[s - sm];
                return;
            }
            dfs(dfs, ix + 1, sm + b[ix], used | (1<<ix));
            dfs(dfs, ix + 1, sm, used);
        };
        back(back, 0, 0ll, 0);
        cout << ans << "\n";
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