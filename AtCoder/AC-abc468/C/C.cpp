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
    vec<int> p(n), q(n);
    L(i,0,n) cin >> p[i];
    L(i,0,n) cin >> q[i];
    vec<int> o(n); iota(ALL(o), 1);
    int ans = 0;
    do {
        int g = -1;
        int l = -1;
        L(i,0,n) {
            if (g == -1 && p[i] != o[i]) {
                g = o[i] > p[i];
            }
            if (l == -1 && q[i] != o[i]) {
                l = o[i] < q[i];
            }
        }
        if (g == 1 && l == 1) ans ++;
    } while(next_permutation(ALL(o)));

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