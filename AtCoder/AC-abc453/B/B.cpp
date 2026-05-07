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
    int n, x; cin >> n >> x;
    vec<pair<int,int>> r;
    vec<int> a(n+1); L(i,0,n+1) cin >> a[i];
    r.pb({0,a[0]});
    L(i,1,n+1){
        if (abs(a[i]-r.back().second) >= x) r.pb({i, a[i]});
    }
    for (auto [t, xi]: r) {
        cout << t << " " << xi <<"\n";
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