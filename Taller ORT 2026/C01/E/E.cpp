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
    int n, k; cin >> n >> k;
    vec<int> a(n), b(n);
    L(i,0,n) cin >> a[i];
    L(i,0,n) cin >> b[i];
    vec<pair<int,int>> d(n);
    L(i,0,n) d[i] = {b[i] - a[i], i};
    sort(ALL(d), greater());
    int sm = 0;
    L(i,0,k) {
        sm += a[d[i].second];
    }
    L(i,k,n) sm += min(a[d[i].second], b[d[i].second]);
    cout << sm << "\n";
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