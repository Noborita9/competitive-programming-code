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
    int pp = a[0] % 2;
    int ip = a[1] % 2;
    for (int i = 0; i < n; i += 2) {
        if (a[i] % 2 != pp) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 1; i < n; i += 2) {
        if (a[i] % 2 != ip) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
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