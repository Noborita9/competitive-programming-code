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
const int MAXV = 100 * 1000 + 10;
bitset<MAXV> dp;

void solve()
{   
    int n; cin >> n;
    vec<int> c(n); L(i,0,n) cin >> c[i];
    dp[0] = 1;
    L(i,0,n){
        dp |= (dp << c[i]);
    }
    vec<int> out;
    L(i,1,MAXV) {
        if (dp[i]) out.pb(i);
    }
    cout << SZ(out) << "\n";
    for (int o: out) cout << o << " ";
    cout << "\n";
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