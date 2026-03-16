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

int comp(int c, int o, int r) {
    if (o == 0) return 0;
    if (c == 0) return o - 1;
    if (r == 0) return o - 1;
    // in want to test using k r with a 01 formation 
    ll lo = 0;
    ll hi = r;
    ll ans = 0;
    auto check = [&](ll k) -> bool {
        ll need1 = (k + 1) / 2;
        ll need0 = 1 + (k / 2);
        // cout << need0 << " - " << need1 << "\n";
        return need1 <= o && need0 <= c;
    };
    
    while (lo <= hi) {
        ll m = (lo + hi) / 2ll;
        // cout << "Try " << m << "\n";

        if (check(m)) {
            lo = m + 1;
            ll need1 = (m + 1) / 2;
            ll need0 = 1 + (m / 2);
            ll rem1 = o - need1;
            ll rem0 = c - need0;
            ll score = m;
            if (need1) {
                score += rem1;
            }
            // cout << "Could " << m << "\n";
            ans = max(ans, score);
            // 0101        
        } else {
            hi = m - 1;
        }
    }

    return ans;
}

void solve()
{
    int n, m ,o; cin >> n >> m >> o;
    cout << max(0, comp(n, m, o)) << "\n";
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