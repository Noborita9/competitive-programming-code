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

using ii = pair<ll, int>;
void solve()
{
    int n, m; cin >> n >> m;
    vec<ll> f(n), d(n);
    L(i,0,n) cin >> f[i] >> d[i];
    ll ans = 0;
    priority_queue<ii> pq;
    L(i,0,n)pq.push({f[i],i});
    while(m--){
        auto [h, i] = pq.top(); pq.pop();
        ans += h;
        pq.push({max(0ll, h - d[i]), i});
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