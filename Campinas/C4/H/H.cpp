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

const ll mod = 1e9 + 7;

ll bpow(ll a, ll b) {
    for (ll res = 1; b > 0; b >>= 1, a=(a*a)%mod)
     if (b & 1) res = (res * a) % mod;
}

void solve()
{
    
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