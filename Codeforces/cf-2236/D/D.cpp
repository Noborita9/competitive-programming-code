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
    vec<int> a(n); L(i,0,n) cin >> a[i];
    vec<pair<int,int>> c;
    sort(ALL(a));
    c.eb(a[0], 1);
    bool pos = 0;

    auto proc = [&]() -> void {
        if (pos) return;
        if (c.empty()) return;
        int mxc = c.back().second;
        if (mxc % 2 == 0) {
            pos = 1;
            return;
        }
        if (SZ(c) > 1) {
            pos = 1;
            return;
        }
    };
    L(i,1,n){
        if (a[i] == c.back().first) c.back().second ++;
        else {
            if (a[i] - c.back().first > k) {
                proc();
                c.clear();
            }
            c.eb(a[i], 1);
        }
    }
    proc();
    if (pos) {
        cout << "YES\n";
        return;
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