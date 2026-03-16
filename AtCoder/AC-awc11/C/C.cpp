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
    int n; ll k; cin >> n >> k;
    ll cur = 0;
    int tot = 0;
    L(i,0,n){
        ll x; cin >> x;
        if ((x & k) < x) continue; // x has bits that k does not have
        // if (k == 0)
        cur |= x;
        tot ++;
    }
    if (cur != k || tot == 0){
        cout << "-1\n";
    } else cout << tot << "\n";
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