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

using ii = pair<int,int>;

void solve()
{
    int n; cin >> n;
    vec<ii> d; d.reserve(n);
    L(i,0,n){
        int w, h; cin >> w >> h;
        d.eb(w, -h);
    }
    sort(ALL(d));
    vec<int> lds; lds.pb(d[0].second);
    L(i,1,n) {
        int h = d[i].second;
        if (h >= lds.back()) lds.pb(h);
        else {
            auto it = upper_bound(ALL(lds), h) - begin(lds);
            lds[it] = h;
        }
    }
    // for (int l: lds) cout << l << " ";
    // cout << "\n";
    cout << SZ(lds) << "\n";
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