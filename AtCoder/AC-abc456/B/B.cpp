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
    vec<int> fo(3), fi(3), si(3);
    L(j,0,3){
        L(i,0,6) {
            int x; cin >> x;
            if (x == 4) fo[j]++;
            else if (x == 5) fi[j]++;
            else if (x == 6) si[j]++;
        }
    }
    ld ans = 0.0;
    vec<int> ord(3);
    iota(ALL(ord),0);
    do
    {
        ld i4 = fo[ord[0]];
        ld i5 = fi[ord[1]];
        ld i6 = si[ord[2]];
        ans += (i4/6.0) * (i5/6.0) * (i6/6.0);
    } while (next_permutation(ALL(ord)));
    cout << fixed << setprecision(12) << ans << "\n";
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