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

using ii = pair<ll, int>; // {a[i], i}
void solve()
{
    int n; ll D; cin >> n >> D;
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    ll ans = 0;
    multiset<ll> M;
    int i = 0;
    int j = 0;
    auto check = [&](ll x){
        if (SZ(M) < 1) return false;
        auto it = M.lower_bound(x);
        // cout << "Post: " << *it << " " << x << "\n";
        if (it != M.end() && *it - x < D) {
            return true;
        }
        if (it != M.begin()){
            it--;
            if (x - *it < D) {
                // cout << "Prev: " << *it << " " << x << "\n";
                return true;
            }
        } 
        return false;
    };
    
    while (i < n) {
        while (j < i && check(a[i])) {
            M.erase(M.find(a[j]));
            j ++;
        }
        M.insert(a[i]);
        ans += (i - j + 1);
        // cout << "i: " << i << " j:" << j << " -> " << i - j + 1 << "\n"; 
        i ++;
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