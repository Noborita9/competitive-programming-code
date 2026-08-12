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
    vec<int> a(n); L(i,0,n) cin >> a[i];
    vec<pair<int,int>> ps;
    ps.eb(a[0], 1);
    L(i,1,n) {
        if (a[i] == ps.back().first) {
            ps.back().second ++;
        } else ps.eb(a[i], 1);
    }
    int ans = SZ(ps);
    bool upg = 0;
    L(i,1,ans){
        if (ps[i-1].second >= 2 && ps[i].second >= 2) {
            ans += 2;
            upg = 1;
            break;
        }
    }
    // cout << upg << " " << ans << "\n";
    if (!upg) {
        auto check = [&](int i) -> bool {
            if (i > 0 && ps[i-1].first == ps[i].first) return false;
            if (i + 1 < ans && ps[i].first == ps[i+1].first) return false;
            return true;
        };
        L(i,0,ans) if (ps[i].second >= 2) {
            if (i > 0) {
                swap(ps[i], ps[i - 1]);
                if (check(i - 1)) {
                    ans ++;
                    break;
                }
                swap(ps[i], ps[i - 1]);
            }
            if (i + 1 < ans) {
                swap(ps[i], ps[i + 1]);
                if (check(i + 1)) {
                    ans ++;
                    break;
                }
                swap(ps[i], ps[i + 1]);
            }
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