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
    int n, d; cin >> n >> d;
    vec<ll> x(1e6 + 10);
    L(i,0,n) {
        int s, t; cin >> s >> t;
        if (t - s + 1 < d) continue;
        x[s]++;
        x[t - d + 1]--;
    }
    ll ans = 0;
    ll tm = SZ(x);
    L(i,1,tm){
        x[i] += x[i - 1];
        ans += (x[i] * (x[i] - 1)) / 2;
    }

    cout << ans << "\n";

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
