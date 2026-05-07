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

using ii = pair<ll, ll>;
void solve()
{
    int n; ll k; cin >> n >> k;
    vec<ll> a(n), b(n);
    L(i,0,n) cin >> a[i] >> b[i];
    vec<ii> c(n);
    L(i,0,n) c[i] = {b[i], a[i]};
    sort(ALL(c), greater());
    ll sm = 0;
    multiset<ll, greater<ll>> S;
    L(i,0,n){
        // cout << c[i].first <<" - " << c[i].second << "\n";
        while (k > 0 && SZ(S) && *begin(S) > c[i].first) {
            auto it = begin(S);
            sm += *it;
            // cout << "Picked: " << *it << "\n";
            k --;
            S.erase(it);
        }
        ll times = min(k, c[i].second/c[i].first);
        sm += times * c[i].first;
        // cout << "Got: " << times * c[i].first << "\n";
        k -= times;
        if (c[i].second % c[i].first != 0) {
            S.insert(c[i].second % c[i].first);
        }
        // cout << "Sum: " << sm << "\n";
    }
    while(k > 0 && SZ(S)) {
        sm += *begin(S);
        S.erase(begin(S));
        k --;
    }
    cout << sm << "\n";
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