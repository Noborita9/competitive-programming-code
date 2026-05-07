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
    int n; ll k; cin >> n >> k;
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    if (n == 1){
        cout << "0\n";
        return;
    }
    ll mx = *max_element(ALL(a));
    L(i,0,n) {
        a[i] += k * ((mx-a[i])/k);
        // set all lowerbounds near
    }
    sort(ALL(a));
    // L(i,0,n) cout << a[i] << "\n";
    ll mn = *min_element(ALL(a));
    ll ans = mx - mn;
    set<ll> s(ALL(a));
    L(i,0,n){
        auto it = begin(s);
        s.insert(*it + k);
        s.erase(it);
        ans = min(ans, *s.rbegin() - *s.begin());
        // cout << "Found: " << *s.rbegin() << " - " << *s.begin() << "\n";
        // for (int e: s) cout << e << " ";
        // cout << "\n";
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