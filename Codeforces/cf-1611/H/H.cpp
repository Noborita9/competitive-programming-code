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
    int n, m; cin >> n >> m;
    vec<pair<ll,ll>> a0; a0.reserve(n * m);
    vec<pair<ll,ll>> a1; a1.reserve(n * m);

    L(i,1,n+1){
        L(j,1,m+1){
            char c; cin >> c;
            if (c == '1') {
                if ((i + j) % 2 == 0){
                    a0.eb(j + i, j - i);
                } else a1.eb(j + i, j - i);
            }
        }
    }
    auto calc = [&](vec<pair<ll,ll>> &a) -> int {
        sort(ALL(a), [](const pair<ll,ll> &lhs, const pair<ll,ll> &rhs) {
            if (lhs.first != rhs.first) return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        });
        vec<ll> lds;
        for (auto [x, y]: a) {
            auto it = lower_bound(ALL(lds), y);
            if (it == end(lds)) lds.pb(y);
            else *it = y;
        }
        return SZ(lds);
    };
    cout << calc(a0) + calc(a1) << "\n";
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