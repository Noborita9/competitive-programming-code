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
    vec<vec<int>> a(n);
    L(i,0,n) {
        int k; cin >> k;
        L(j,0,k)
        {
            int x; cin >> x;
            x --; a[x].pb(i+ 1);
        }
    }
    for (auto v: a) {
        sort(ALL(v));
        cout << SZ(v) << " ";
        for (int x:v )cout << x << " ";
        cout << "\n";
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
