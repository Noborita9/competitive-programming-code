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
    int n; ll m; cin >> n;
    ll sm = 0; cin >> m;
    L(i,0,n){
        ll x; cin >> x;
        sm += x;
    }
    // cout << m << " " << sm << "\n";
    cout << (m <= sm ? "Yes": "No") << "\n"; 
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