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
    int n, m, q; cin >> n >> m >> q;
    while(q--)
    {
        int ans = 0;
        int t, x; cin >> t >> x;
        if (t == 2){
            ans = n * x;
            m -= x;
        } else {
            ans = m * x;
            n -= x;
        }

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