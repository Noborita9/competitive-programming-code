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

struct ST {
    vec<ll> st; int K;
    ST(int ln): K(1) {
        while(K<=ln)K<<=1;
        st.assign(2*K,0);
    }
    void upd(int i, ll x){
        i += K; st[i] += x;
        while(i>>=1)st[i]=st[2*i]+st[2*i+1];
    }
    ll query(int l, int r) {
        ll ans =0;
        for (l += K, r += K;l < r; l>>=1, r >>= 1){
            if (l & 1) ans += st[l++];
            if (r & 1) ans += st[--r];
        }
        return ans;
    }
};

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    vec<int> a(n);
    L(i,0,n) {
        if (s[i] == 'A') a[i] = 1;
        else if (s[i] == 'B') a[i] = -1;
    }
    vec<int> raw, pref(n);
    raw.reserve(2 * n);

    L(i,0,n){
        pref[i] += a[i];
        if (i > 0) pref[i] += pref[i - 1];
        raw.pb(pref[i]);
        raw.pb(pref[i] - 1);
    }

    raw.pb(-n - 10); // ulta low value
    raw.pb(0);
    sort(ALL(raw));
    raw.erase(unique(ALL(raw)), end(raw));
    auto get = [&](int t) {return lower_bound(ALL(raw), t) - begin(raw);};
    int ln = SZ(raw);
    ST st(ln + 10);
    st.upd(get(0), 1);
    ll ans = 0;
    // L(i,0,n) cout << pref[i] << " "; cout << "\n";
    L(i,0,n){
        ll tg = pref[i] - 1; // add all lower or eq
        ans += st.query(0, get(tg) + 1);
        st.upd(get(pref[i]), 1);
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