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

struct node {
    ll tot, pref, suff, ans;
    node(ll x): tot(x), pref(max(0ll, x)), suff(max(0ll,x)), ans(max(0ll, x)) {}
    node(ll t, ll p, ll s, ll a): tot(t), pref(p), suff(s), ans(a) {}
};

node merge(node a, node b){
    ll tot = a.tot + b.tot;
    ll pref = max(a.pref, a.tot + b.pref);
    ll suff = max(b.suff, a.suff + b.tot);
    ll ans = max({a.ans, b.ans, a.suff + b.pref});
    return node{tot, pref, suff, ans};
}


struct ST {
    vec<node> st; int k;
    ST(vec<ll> &a): k(1) {
        int n = SZ(a);
        while(k<=n)k<<=1;
        st.assign(2*k,node(0));
        L(i,0,n) st[i + k] = node(a[i]);
        for (int i = k - 1; i > 0; i --) st[i] = merge(st[2*i],st[2*i+1]);
    }
    void upd(int i, ll x){
        i+=k;st[i]=node(x);
        while(i>>=1)st[i]=merge(st[2*i],st[2*i+1]);
    }
    ll query(int l, int r){
        node ansL = node(0);
        node ansR = node(0);
        for (l +=k, r += k; l < r; l >>= 1, r >>= 1){
            if(l&1)ansL=merge(ansL,st[l++]);
            if(r&1)ansR=merge(st[--r],ansR);
        }
        return merge(ansL,ansR).ans;
    }
};

void solve()
{
    int n, q; cin >> n >> q;
    vec<ll> a(n);
    L(i,0,n) cin >> a[i];
    ST st(a);
    while(q--)
    {
        int ix; ll w; cin >> ix >> w;
        st.upd(ix - 1, w);
        cout << st.query(0, n) << "\n";
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