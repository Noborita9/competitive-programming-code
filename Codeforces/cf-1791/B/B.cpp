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
    vec<int> a(n), b(m);
    L(i,0,n) cin >> a[i];
    L(i,0,m) cin >> b[i];
    if (m * 2 > n) {
        cout << "NO\n";
        return;
    }
    sort(ALL(a));
    sort(ALL(b));
    bool pos = 1;
    L(i,0,m) {
        pos = pos && a[i] < b[i] && a[n - 1 - i] > b[m - 1 - i];
    }
    

    cout << (pos ? "YES" : "NO") << "\n";
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