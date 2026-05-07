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
    int n, p; cin >> n >> p;
    vec<int> a(n); L(i,0,n) cin >> a[i]; L(i,0,n) a[i] -= p;
    int sm = 0;
    int ans = 0;
    L(i,0,n) {
        sm = max(sm + a[i], a[i]);
        ans = max(ans, sm);
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