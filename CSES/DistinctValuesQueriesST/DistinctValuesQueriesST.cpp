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
    // Index compression
    vec<int> raw(ALL(a)); 
    sort(ALL(raw));
    raw.erase(unique(ALL(raw)), end(raw));
    auto gix = [&](int t){return lower_bound(ALL(raw), t) - begin(raw);};
    L(i,0,n) a[i] = gix(a[i]);
    // a[i] ahora esta comprimido entre [0, n]
    vec<vec<pair<int,int>>> qs(n);
    L(i,0,q) {
        int l, r; cin >> l >> r;
        qs[r - 1].eb(l - 1, i);
    }
    ST st(n + 1);
    vec<int> last(n, -1);
    vec<int> ans(q);
    L(r,0,n){
        if (last[a[r]] != -1) st.upd(last[a[r]], - 1);
        last[a[r]] = r;
        st.upd(r, 1);
        for (auto [l, i]: qs[r]) {
            ans[i] = st.query(l, r + 1);
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