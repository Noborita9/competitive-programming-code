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
        st.assign(2*k, 0);
        L(i,0,n) st[i + k] = 1;
        for (int i = k - 1; i; i --) st[i] = st[i * 2] + st[i * 2 + 1];
    }
    void upd(int i, int w){
        i += k; st[i] += w; while (i >>= 1) st[i] = st[2 * i] + st[2 * i + 1];
    }
    int query(int l, int r){
        int sm = 0;
        for (l += k, r += k; l < r; l>>=1, r>>=1) {
            if (l & 1) sm += st[l++];
            if (r & 1) sm += st[--r];
        }
        return sm;
    }
};

void solve()
{
    int n, q; cin >> n >> q;
    const int PMAX = 2e5 + 10;
    vec<int> a(n);
    vec<vec<int>> g(PMAX);
    L(i,0,n){
        cin >> a[i];
        g[a[i]].pb(i);
    }
    vec<int> l(q), r(q);
    L(i,0,q) {
        cin >> l[i] >> r[i];
        l[i] --;
    }
    ST st(n);
    // cout << st.query(0, n) << endl;
    int t_cur = 0;
    vec<int> ans(q, 1);
    auto st_add = [&](int i_q, int mp) {
        // cout << "Pre Upd" << endl;
        for (int ix: g[i_q]) st.upd(ix, mp);
        // cout << "post Upd" << endl;
    };
    auto calc = [&](auto && rec, int low, int high, vec<int> &own) -> void {
        if (own.empty()) return;
        int mid = (low + high) / 2;
        while (t_cur < mid) st_add(t_cur++, -1);
        while (t_cur > mid) st_add(--t_cur, 1);
        vec<int> left, right;
        // cout << "Preeval" << endl;
        // cout << "MID: " << mid << "\n";
        // L(i,0,n) cout << st.query(i, i + 1) << " "; cout << endl;
        for (int o: own) {
            int sm = st.query(l[o], r[o]);
            if (sm >= mid) {
                ans[o] = mid;
                right.pb(o);
            } else left.pb(o);
        }
        // cout << "Posteval" << endl;
        own.clear();
        if (low < high) {
            rec(rec, low, mid, left);
            rec(rec, mid + 1, high, right);
        }
    };
    vec<int> owners(q);
    iota(ALL(owners), 0);
    calc(calc, 1, PMAX, owners);
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