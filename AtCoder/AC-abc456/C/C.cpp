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

const ll mod = 998244353;

void solve()
{
    string s; cin >> s;
    s += s.back();
    int n = SZ(s);
    ll tot = 0;
    int j = -1;
    L(i,1,n){
        if (s[i] == s[i - 1]) {
            // from i - 1 to j all valid
            ll len = ((ll)i - 1) - j;
            (tot += ((len * (len + 1)) / 2) % mod) %= mod;
            j = i - 1;
        }
        
    }
    cout << tot <<"\n";
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