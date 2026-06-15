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

const int BLOCK_SIZE = 450;


void solve()
{
    int n, q; cin >> n >> q;
    vec<ll> a(n + 1);
    vec<ll> pref(n + 1);
    L(i,0,n)
    {
        cin >> a[i + 1];
        pref[i + 1] += pref[i] + a[i + 1];
    }    
    vec<pair<ll, ll>> upd; upd.reserve(BLOCK_SIZE);
    vec<ll> delta(n + 10), delta2(n + 10);
    L(qi,0,q)
    {
        ll op, l, r; cin >> op >> l >> r;
        if (op == 1) {
            upd.eb(l, r);
            delta[l] ++;
            delta[r + 1] --;
            delta2[r + 1] -= r - l + 1;

            if (SZ(upd) == BLOCK_SIZE) {
                ll dt = 0;
                ll acc = 0;
                L(i,1,n + 1)
                {
                    acc += delta[i];
                    dt += acc + delta2[i];
                    a[i] += dt;
                    pref[i] = pref[i - 1] + a[i];
                    delta[i] = 0;
                    delta2[i] = 0;
                }
                upd.clear();
            } 
        } else {
            ll ans = pref[r] - pref[l - 1];
            for (const auto &[ul, ur]: upd) {
                int le = max(ul, l);
                int ri = min(ur, r);
                if (le <= ri) {
                    ll len = ri - le + 1;
                    ll upfront = le - ul;
                    ans += ((len * (len + 1)) / 2) + (len * upfront);
                }
            }
            cout << ans << "\n";
        }

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