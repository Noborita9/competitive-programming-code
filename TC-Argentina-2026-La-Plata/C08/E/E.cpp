#include <bits/stdc++.h>
using namespace std;
#define L(i,j,n) for(int i=j;i<int(n);i++)
#define ALL(x) begin(x),end(x)
#define SZ(x) int(x.size())
#define pb push_back
#define eb emplace_back
#define vec vector
using ll=long long;
using ld=long double;

using iii = tuple<int,int,int,int, int>;
// BUS: {ti, BUS, l, r, ix}
// PER: {ti, PER, l, r, ix}

const ll oo = 1e18;
using ii = pair<ll,int>;
struct node {
    ll mn; int ix;
    node(ll x, int ix_): mn(x), ix(ix_) {}
};

node merge(node a, node b){
    return node(min(a.mn, b.mn), -1);
}


struct ST {
    vec<node> st; int k;
    ST(int n): k(1){
        while(k<n) k <<=1;
        st.assign(2 * k, {oo, -1});
    }
    void upd (int x, ll w, bool add, int ix ){
        x += k;
        if (add) st[x] = node(w, ix);
        else st[x] = node(oo, -1);
        while(x>>=1)st[x] = merge(st[2 * x], st[2 * x + 1]);
    }
    int query(int v, int L, int R, int mn, int lb) {
        if (R <= lb) return -1; // time lower bound
        if (st[v].mn == -oo) return -1;
        if (st[v].mn > mn) return -1;
        if (R - L == 1) {
            return st[v].ix;
        }
        int m = (L + R) / 2;
        int ql = query(2 * v, L, m, mn, lb);
        if (ql != -1) return ql;
        return query(2 * v + 1, m, R, mn, lb);
    }
    int query(int l, int r){
        return query(1,0,k, l,r);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    vec<int> raw;raw.reserve(n + q);
    vec<iii> E; E.reserve(n + q);
    const int BUS = 1;
    const int PER = 0;
    vec<iii> buses; buses.reserve(n);
    L(i,0,n){
        int l, r, t; cin >> l >> r >> t;
        raw.pb(t);
        E.eb(r, BUS, t, l, i);
        buses.eb(r, BUS, t, l,i);
    }
    L(i,0,q){
        int l, r, t; cin >> l >> r >> t;
        raw.pb(t);
        E.eb(r, PER, t, l, i);
    }
    sort(ALL(raw));
    raw.erase(unique(ALL(raw)), end(raw));
    auto gix = [&](int x){return lower_bound(ALL(raw), x) - begin(raw);};
    sort(ALL(E));
    ST st(SZ(raw));
    for (const auto &[r, e_, t_, l, ix_]: buses) {
        st.upd(gix(t_), l, 1, ix_);
    }
    vec<int> ans(q, -1);
    for (const auto &[r, e, t, l, ix]: E) {
        if (e == BUS) {
            st.upd(gix(t), l, 0, ix);
        } else {
            int rl = st.query(l, gix(t));
            if (rl != -1) rl ++;
            ans[ix] = rl;
        }
    }
    L(i,0,q) cout << ans[i] << " ";
    cout <<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int TT=1;
    // cin>>TT;
    while(TT--){
        solve();
    }
}