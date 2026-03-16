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
    ll tot, pref;
    node(ll tot_=0,ll pref_=0): tot(tot_), pref(max(pref_, 0ll)) {}
};

node merge(node a, node b){ // [a, b] contiguous, a left of b
    ll pref = max(a.pref, a.tot + b.pref);
    ll tot = a.tot + b.tot;
    return node{tot, pref};
}

struct ST {
    vec<node> st; int k;
    ST(vec<ll>&a): k(1) {
        int n = SZ(a);
        while(k<=n)k<<=1;
        st.assign(2*k,node{0ll,0ll});
        L(i,0,n) st[i + k] = node(a[i],a[i]);
        for (int i = k - 1; i > 0; i --) st[i] = merge(st[2*i],st[2*i+1]);
    }
    void upd(int i, int x){
        i+=k;st[i]=node(x, x);
        while(i>>=1)st[i]=merge(st[2*i],st[2*i+1]);
    }
    ll query(int l, int r){
        node bestL = node{0ll,0ll};
        node bestR = node{0ll,0ll};
        for (l +=k, r += k; l < r; l >>= 1, r >>= 1){
            if(l&1)bestL=merge(bestL, st[l++]);
            if(r&1)bestR=merge(st[--r], bestR);
        }
        return merge(bestL,bestR).pref;
    }
};

void solve()
{
    int n, q; cin >> n >> q;
    vec<ll> a(n); L(i,0,n) {cin >> a[i];}
    ST st(a);
    while(q--){
        int op; cin >> op;
        if (op == 2) {
            int l, r; cin >> l >> r;
            cout << st.query(l - 1, r) << "\n";
        } else {
            int x; ll w; cin >> x >> w;
            st.upd(x - 1, w);
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