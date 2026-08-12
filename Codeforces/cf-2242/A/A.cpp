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
    vec<int> a(n); L(i,0,n) cin >> a[i];
    sort(ALL(a), greater<>());
    L(i,0,n)
    {
        if (a[i] >= 3) {
            cout << "YES\n";
            return;
        } else if (i + 1 < n && a[i] >= 2 && a[i + 1] >= 2) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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