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
const ll b = 500'000'000;
const ll MOD = (ll)INT_MAX;

struct StrHash {
    vec<ll> hs, bs;
    StrHash(const string &s): hs(SZ(s) + 1), bs(SZ(s) + 1, 1) {
        int n = SZ(s);
        L(i,0,n) {
            hs[i + 1] = (hs[i]*b+s[i])%MOD;
            bs[i + 1] = bs[i]*b % MOD;
        }
    }
    ll get(int idx, int len) const {
        ll h = hs[idx + len] - hs[idx]*bs[len] %MOD;
        if (h < 0) h += MOD;
        return h;
    }
};

void solve()
{
    string s; cin >> s;
    StrHash h(s + s);
    int n = SZ(s);
    int best = 0;
    L(i,1,n){
        int lo = 1;
        int hi = n;
        int ans = 0;
        while(lo<=hi) {
            int m = (lo + hi) / 2;
            if (h.get(best, m) == h.get(i, m)) {
                lo = m + 1;
                ans = m;
            } else {
                hi = m - 1;
            }
        }
        if (s[(best + ans)%n] > s[(i + ans)%n]) {
            best = i;
        }
    }
    L(i,0,n) cout << s[(best + i)%n]; cout << "\n";
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