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
    int n, q; cin >> n >> q;
    vec<vec<int>> bits(32);
    vec<ll> flip(32);
    L(i,0,32){
        flip[i] = (1ll<<(i + 1)) - 1;
        // cout << bitset<32>(flip[i]) << "\n";
    }
    vec<ll> a(n);
    vec<ll> pref(n);
    L(i,0,n){
        cin >> a[i];
        pref[i] = a[i];
        if (i > 0) pref[i] ^= pref[i - 1];
        if (a[i] == 0) continue;
        int b = 0;
        for (int bit = 31; bit >= 0; bit --){
            if ((a[i] & (1ll<<bit))) {
                b = bit;
                break;
            }
        }
        bits[b].push_back(i);
        // cout << b << "\n";
    }
    auto get = [&](int l, int r){
        ll ans = pref[r];
        if (l > 0) ans ^= pref[l - 1];
        return ans;
    };
    L(qi, 0, q){
        int l, r; cin >> l >> r;
        l --; r --;
        ll cur = get(l, r);
        for (int bit = 31; bit >= 0; bit --){
            if ((cur & (1ll<<bit)) == 0) {
                auto it = lower_bound(ALL(bits[bit]), l);
                if (it != bits[bit].end() && *it <= r) {
                    // cout << "TMP: " << cur << " Using " << *it << "\n";
                    cur ^= flip[bit];
                }
            }
        }
        cout << cur << "\n";
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