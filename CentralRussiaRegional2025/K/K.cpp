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

map<ll,bool> M;
ll n;
void back(ll a, ll vA, ll b, ll vB) {
    if ()
    if (vA % vB == 0 && n * vC == vA / vB) {
        cout << a << " " << max(b, c) << " " << min(b, c) << "\n";
        return;
    }
    M[]
}


void solve()
{
    cin >> n;
    ll fact = 1;
    const ll oo = 1e14;
    for (ll i = 2; i <= 50000; i ++){
        fact *= i;
        if (fact >= oo) break;
        M[fact] = 1;
    }

    back(2, 2, 2, 2, 2, 2);
    cout << "-1 -1 -1\n";
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