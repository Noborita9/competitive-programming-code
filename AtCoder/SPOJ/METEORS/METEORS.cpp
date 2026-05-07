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
    ST(int n): k(1){
        while(k<=n)k<<=1;
        st.assign(k*2, 0);
    }
    void upd(int l, int r, ll w){
        for (l += k, r += k; l < r; l >>= 1, r >>= 1){
            if (l & 1) st[l++] += w;
            if (r & 1) st[--r] += w;
        }
    }
    ll sum(int l){
        ll sm = 0;
        for (l += k; l > 0; l >>= 1) sm += st[l];
        return sm;
    }
};

void solve()
{
    int n, m; cin >> n >> m;
    vec<vec<int>> who(n);
    L(i,0,m) {
        int x; cin >> x;
        who[x-1].pb(i);
    }
    vec<ll> need(n);
    L(i,0,n) cin >> need[i];
    int q; cin >> q;
    vec<int> le(q), ri(q); vec<ll> val(q);
    L(i,0,q) cin >> le[i] >> ri[i] >> val[i];
    vec<int> owners(n);
    iota(ALL(owners), 0);
    vec<int> ans(n, - 1);

    ST st(m);
    auto tup = [&](int i_q, ll w) -> void {
        ll v = val[i_q] * w;
        if (le[i_q] <= ri[i_q]) st.upd(le[i_q] - 1, ri[i_q], v);
        else {
            st.upd(le[i_q] - 1, m, v);
            st.upd(0, ri[i_q], v);
        }
    };
    auto calc = [&](auto && rec, int low, int high, vec<int> &own, int &t_cur) -> void {
        if (own.empty()) return;
        int mid = (low + high) / 2;
        while (t_cur <= mid) tup(t_cur++, 1);
        while (t_cur - 1 > mid) tup(--t_cur, -1);
        // cout << low << " " << high << endl;
        vec<int> left, right;
        for (int o: own) {
            ll sm = 0;
            for (int w: who[o]) {
                sm += st.sum(w);
                if (sm >= need[o]) break;
            }
            if (sm >= need[o]) {
                left.pb(o);
                ans[o] = mid;
            } else right.pb(o);
        }
        own.clear();
        // cout << "Post: " << low << " " << high << "\n";
        if (low < high){
            rec(rec, low, mid, left, t_cur);
            rec(rec, mid+1, high, right, t_cur);
        }
        
    };
    // cout << "HERE" << endl;
    int t_cur = 0;
    calc(calc, 0, q - 1, owners, t_cur);
    // cout << "THERE" << endl;
    L(i,0,n) {
        if (ans[i] == -1) cout << "NIE\n";
        else cout << ans[i] + 1 << "\n";
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