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
    int n = SZ(s);
    vec<ll> dp(258);
    dp['a'] = 0;
    dp['b'] = 0;
    dp['c'] = 0;
    L(i,0,n)
    {
        char l = s[i];
        if (l == 'a'){
            (dp['a'] += (dp['b'] + dp['c'] + 1) % mod) %= mod;
        } else if (l == 'b') {
            (dp['b'] += (dp['a'] + dp['c'] + 1) % mod) %= mod;
        } else {
            (dp['c'] += (dp['b'] + dp['a'] + 1) % mod) %= mod;
        }
    }

    cout << ((dp['a'] + dp['b'] + dp['c'])%mod) << "\n";
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