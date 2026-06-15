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
    vec<int> x(3);
    L(i,0,n){
        int p; cin >> p;
        x[p] ++;
    }
    int ans = x[0];
    int mx2 = min(x[1],x[2]);
    ans += mx2;
    x[1] -= mx2;
    x[2] -= mx2;
    ans += x[1]/3;
    ans += x[2]/3;
    cout << ans << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}