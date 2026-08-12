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
    int n; cin >> n;
    ll ans = 0;
    vec<vec<ll>> c(26, vec<ll>(2));
    map<string, ll> h;
    L(i,0,n){
        string p; cin >> p;
        ans += c[p[0]-'a'][0];
        ans += c[p[1]-'a'][1];
        ans -= 2 * h[p];
        c[p[0]-'a'][0]++;
        c[p[1]-'a'][1]++;
        h[p] ++;
    }
    cout << ans << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}