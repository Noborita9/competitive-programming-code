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

const ll oo = 1e9;


void solve()
{
    auto ask = [](int x) {
        cout << "? " << x << endl;
        string a; cin >> a;
        return a == "YES";
    };
    auto ans = [](int x){
        cout << "! " << x << endl;
    };
    ll lo = 1;
    ll hi = oo;
    ll out = 0;

    while (lo < hi) {
        ll m = (lo + hi) / 2ll;
        if (ask(m)) {
            lo = m + 1;
        } else {
            hi = m;
        }
    }
    
    ans(lo);
}


int main()
{
    // ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    //cin >> TT;
    while (TT--)
    {
        solve();
    }
}