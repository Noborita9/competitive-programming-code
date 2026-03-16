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
    vec<int> st; int k;
    ST(int n): k(1) {
        while(k<=n)k<<=1;
        st.assign(2*k,0);
        // for (int i = k - 1; i > 0; i --) st[i] = st[2*i]+st[2*i+1];
    }
    void upd(int i, int x){
        i+=k;st[i]+=x;
        while(i>>=1)st[i]=st[2*i]+st[2*i+1];
    }

    int query(int l, int r){
        int ans = 0;
        for (l += k, r += k; l < r; l>>=1, r>>=1) {
            if(l&1)ans+=st[l++];
            if(r&1)ans+=st[--r];
        }
        return ans;
    }
};


void solve()
{
    int n, q; cin >> n >> q;
    vec<int> a(n); L(i,0,n) cin >> a[i];
    vec<vec<pair<int,int>>> qs(n);
    L(i,0,q) {
        int l, r; cin >> l >> r;
        qs[l-1].pb({r, i});
    }
    vec<int> ans(q);
    ST st(n);
    vec<int> stck;
    for (int i = n - 1; i >= 0; i --){
        // Make updates
        while (SZ(stck) && a[stck.back()] <= a[i]) {
            st.upd(stck.back(), -1);
            stck.pop_back();
        }
        st.upd(i, 1);
        stck.pb(i);
        for (auto [r, ix]: qs[i])  {
            ans[ix] = st.query(i, r);
        }
    }
    L(i,0,q) cout << ans[i] << "\n";
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