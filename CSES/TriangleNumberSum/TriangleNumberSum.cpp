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

const ll N = 2e6;
const ll MAXN = 1e12;

inline ll gauss(ll k) {
    return (k * (k + 1)) / 2ll;
}

void solve()
{
    L(i,1,N + 1) {
       cout << i << ": " << gauss(i) << "\n"; 
       if (gauss(i) >= MAXN) break;
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