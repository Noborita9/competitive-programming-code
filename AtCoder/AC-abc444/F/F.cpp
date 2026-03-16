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


// struct mov {
//     int d, x;
//     mov(int d_=-1, int x_=-1): d(d_),x(x_) {};
//     bool operator>(const mov & rhs) const {
//         if (d != rhs.d) d > rhs.d;
//         return x > rhs.d;
//     }
// };

using ii = pair<int, ll>; // {d, x} greater

void solve()
{
    int n, m; cin >> n >> m;
    vec<ll> a(n);
    L(i,0,n) cin >> a[i];
    
    auto check = [&](ll k) -> bool {
        int balance = 0;
        auto score = [&](ll x) {return x >= k ? 1 : -1;};
        auto asMov = [&](ll x) -> ii {
            if (x == 1) return {-10, -1}; // Does not exist anymore
            return {score(x/2)+score((x+1)/2) - score(x), x};
        };
        multiset<ii, greater<ii>> ms;
        L(i,0,n){
            balance += score(a[i]);
            ms.insert(asMov(a[i]));
        }
        L(i,0,m) {
            auto it = begin(ms);
            auto [d, x] = *it;
            ms.erase(it);
            balance += d;
            ms.insert(asMov(x/2));
            ms.insert(asMov((x+1)/2));
        }
        
        return balance >= 0;
    };
    ll lo = 0;
    ll hi = *max_element(ALL(a));
    ll ans = 0;
    while(lo <= hi) {
        ll md = lo + (hi - lo) /2 ;
        if (check(md)) {
            ans = md;
            lo = md + 1;
        }else {
            hi = md - 1;
        }
    }
    cout << ans << "\n";
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