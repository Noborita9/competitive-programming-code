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
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    ll sm = 0;
    sort(ALL(a));
    L(i,0,n) sm += a[i];
    auto check = [&](ll l) -> bool {
        int matched = 0;
        int j = 0;
        for (int i = n - 1; i >= 0; i --){
            if (a[i] == l) {
                matched ++;
                continue;
            }
            if (i <= j) return matched == n;
            if (a[i] + a[j] == l){
                matched += 2;
                j ++;
            }
        }
        return matched == n;
    };
    vec<ll> out;
    if (check(a.back())) out.pb(a.back());
    if (n > 1 && check(a.back()+a[0])) out.pb(a.back()+a[0]);
    sort(ALL(out));
    out.erase(unique(ALL(out)),end(out));
    for (ll o: out) cout << o << " "; cout << "\n";
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