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

using iii = tuple<ll, int, int>;


void solve()
{
    int n; cin >> n;
    vec<ll> a(n);
    set<int> rem;
    multiset<iii> D;
    L(i,0,n) {
        cin >> a[i];
        rem.insert(i);
    }
    sort(ALL(a));
    L(i,1,n){
        D.insert({a[i] - a[i - 1], i - 1, i});
    }

    ll ans = 0;
    L(i,0,n / 2) {
        auto [mn, l, r] = *begin(D);
        rem.erase(l);
        rem.erase(r);
        rem.lower_bound(r); // sig der
        rem.lower_bound(l) -- ; // prev 

        erase(begin(D));
        
    }
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