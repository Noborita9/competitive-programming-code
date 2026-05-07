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

using iii = tuple<int, int, ll>; // {b, a, p}

void solve()
{
    int n; cin >> n;
    vec<iii> E;
    E.reserve(n);
    L(i,0,n){
        int a, b; ll p; cin >> a>> b >> p;
        E.eb(b, a, p);
    }
    sort(ALL(E));
    map<int, ll> dp;
    dp[0] = 0ll;
    for (auto &[b, a, p]: E) {
        auto best = dp.upper_bound(a);
        best --;
        while (best->first >= a) best --;
        auto last = dp.lower_bound(b);
        last --;
        dp[b] = max({dp[b], best->second + p, last->second});
    }
    cout << rbegin(dp)->second << "\n";
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