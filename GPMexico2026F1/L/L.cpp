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
    vec<ll> st; int k;
    ST(int n): k(1) {
        while(k<=n)k<<=1;
        st.assign(2*k,0);
    }
    void upd(int i, ll w){
        st[i += k] += w; while (i >>= 1) st[i] = st[i * 2] + st[i * 2 + 1];
    }
    ll query(int l, int r){
        ll sm = 0;
        for (l += k, r += k; l < r; l >>= 1, r >>= 1){
            if (l & 1) sm += st[l ++];
            if (r & 1) sm += st[--r];
        }
        return sm;
    }
};

void solve()
{
    int n, q; cin >> n >> q;
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    ST st(n + 1);
    vec<ll> pref(n);
    partial_sum(ALL(a), begin(pref));
    ll invs = 0;
    L(i,0,n){
        invs += st.query(a[i], n + 1);
        st.upd(a[i], 1);
    }
    while(q--)
    {
        ll o, i; cin >> o >> i;
        if (o == 2){
            ll delta = (i * (n + 1) - (2ll * (i > 0 ? pref[i - 1] : 0))) ;
            // cout << invs << " + " << delta << "\n";
            cout << invs + delta << "\n";
        } else {
            i --;
            if (a[i] > a[i + 1]) {
                invs --;
            }  else {
                invs ++;
            }
            pref[i] += a[i + 1] - a[i];
            swap(a[i],a[i+1]);
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