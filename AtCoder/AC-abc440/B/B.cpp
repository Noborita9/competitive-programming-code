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
    vec<int> t(n), ord(n);
    L(i,0,n) cin >> t[i];
    iota(ALL(ord),0);
    sort(ALL(ord), [&](int a, int b){return t[a] < t[b];});
    L(i,0,3) cout << ord[i]+1<<" ";
    cout << "\n";

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