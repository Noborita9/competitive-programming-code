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
    int n, B; cin >> n >> B;
    vec<int> a(n); L(i,0,n) cin >> a[i];
    vec<int> x(n);
    L(i,0,n) x[i] = (a[i] & 1) ? -1 : 1;
    vec<int> cuts;
    int sm = 0;
    L(i,0,n - 1){
        sm += x[i];
        if (sm == 0) {
            // cout << i << ": ";
            // cout << abs(a[i]-a[i+1]) << "\n";
            cuts.pb(abs(a[i]-a[i+1]));
        }
    }
    // cout << "\n";
    sort(ALL(cuts));
    int ans = 0;
    for (int c: cuts) {
        if (c <= B) {
            // cout << "Took: " << c << "\n";
            ans ++;
            B -= c;
        }
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