#include <bits/stdc++.h>
#include <cassert>
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
    vec<pair<int, int>> p; p.reserve(n);
    L(i,0,n){
        int h, t; cin >> h >> t;
        p.eb(t, h);
    }
    sort(ALL(p));
    int q; cin >> q;
    vec<pair<int,int>> qs; qs.reserve(q);
    L(i,0,q) {
        int t; cin >> t;
        qs.eb(t, i);
    }
    sort(ALL(qs));
    multiset<int> H;
    L(i,0,n) H.insert(p[i].second);
    vec<int> ans(q);
    int pi = 0;
    // cout << "INit" << endl;
    L(i,0,q)
    {
        auto [tq, iq] = qs[i];
        // cout << "Pre" << endl;
        while (pi < n && p[pi].first <= tq) {
            H.erase(H.find(p[pi].second));
            pi ++;
        }
        // cout << "post" << endl;
        assert(!H.empty());
        ans[iq] = *H.rbegin();
    }
    
    L(i,0,q) cout << ans[i] << "\n";
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