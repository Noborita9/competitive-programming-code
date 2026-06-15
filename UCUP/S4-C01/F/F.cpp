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
    int n, m; cin >> n >> m;
    vec<int> p(n), b(n);
    L(i,0,n) {
        cin >> p[i];
        b[p[i]] = i;
    }
    multiset<ii> ls;
    multiset<ii, greater<ii>> rs;
    ll ans = 0;
    L(i,0,m)
    {
        int l, r; cin >> l >> r;
        l --; r--;
        ls.insert({l, r});
        rs.insert({r, l});
    }
    L(v,0,n)
    {
        int pos = b[v];
        auto lit = ls.upper_bound({pos, n + 10});
        int ml = -1;
        int mr = -1;
        ll tot = 0;
        if (lit != end(ls)) {
            ml = lit->first;
            mr = lit->second;
            while(lit != end(ls))
            {
                tot ++;
                ml = max(ml, lit->first);
                mr = min(mr, lit->second);
                rs.erase(rs.find({lit->second, lit->first}));
                ls.erase(lit);
                lit = ls.upper_bound({pos, n + 10});
            }
        }
        // cout << "Clear L " << endl;
        auto rit = rs.upper_bound({pos, -1});
        if (rit != end(rs)) {
            ml = ml == -1 ? rit->second : max(rit->second, ml);
            mr = mr == -1 ? rit->first : min(rit->first, mr);
            while(rit != end(rs))
            {
                tot ++;
                ml = max(ml, rit->second);
                mr = min(mr, rit->first);
                ls.erase(ls.find({rit->second, rit->first}));
                rs.erase(rit);
                rit = rs.upper_bound({pos, -1});
            }
            
        }
        if (ml != -1){
            ans += (tot - 1) * v;
            rs.insert({mr, ml});
            ls.insert({ml, mr});
        }
        
        // cout << "Clear R " << endl;

    }

    ans += (SZ(ls) - 1) * n;
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