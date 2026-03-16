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
    int n, m; cin >> n >> m;
    vec<ll> a(n), b(m);
    L(i,0,n) cin >> a[i];
    L(i,0,m) cin >> b[i];
    sort(ALL(a));
    sort(ALL(b));
    int i = 0;
    int j = 0;
    int ops = 0;
    while (i < n && j < m){
        if (a[i] <= b[j]) {
            i ++;
            j ++;
            ops ++;
        } else {
            j ++;
        }
    }
    cout << ops << "\n";
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