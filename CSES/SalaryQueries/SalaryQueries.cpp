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
        for (l +=k, r += k; l < r; l >>= 1, r >>= 1){
            if(l&1)ans+=st[l++];
            if(r&1)ans+=st[--r];
        }
        return ans;
    }
};

void solve()
{
    int n, q; cin >> n >> q;
    vec<int> raw;
    raw.reserve(n + 2 * q);
    vec<int> a(n); L(i,0,n) {cin >> a[i];raw.pb(a[i]);}
    vec<array<int,3>> qs(q);
    L(i,0,q){
        char c; int l, r; cin >> c >> l >> r;
        raw.pb(l);
        raw.pb(r);
        qs[i] = {c=='?', l, r};
    }
    sort(ALL(raw));
    raw.erase(unique(ALL(raw)), end(raw));
    auto idx = [&](int x){return lower_bound(ALL(raw), x) - begin(raw);};
    ST st(SZ(raw));
    L(i,0,n) st.upd(idx(a[i]), 1);
    L(i,0,q){
        auto [op, l, r] = qs[i];
        if (op) {
            cout << st.query(idx(l), idx(r)+1) << "\n";
        } else {
            l --;
            int cur = a[l];
            st.upd(idx(cur), -1);
            st.upd(idx(r), 1);
            a[l] = r;
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