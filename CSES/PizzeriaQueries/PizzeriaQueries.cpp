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


const ll oo = (ll)1e18;

struct node {
    ll ln, le, ri;
    node(ll ln_, ll le_, ll ri_): ln(ln_), le(le_), ri(ri_) {}
};

node merge(node a, node b){ // [a, b] contiguous, a left of b
    ll ln = a.ln + b.ln;
    ll le = min(a.le, a.ln + b.le);
    ll ri = min(b.ri, a.ri + b.ln);
    return node{ln, le, ri};
}

struct ST {
    vec<node> st; int k;
    ST(vec<ll>&a): k(1) {
        int n = SZ(a);
        while(k<=n)k<<=1;
        st.assign(2*k,node{0ll,0ll, 0ll});
        L(i,0,n) st[i + k] = node(1ll, a[i],a[i]);
        for (int i = k - 1; i > 0; i --) st[i] = merge(st[2*i],st[2*i+1]);
    }
    void upd(int i, int x){
        i+=k;st[i]=node(1ll, x, x);
        while(i>>=1)st[i]=merge(st[2*i],st[2*i+1]);
    }
    node query(int l, int r){
        node bestL = node{0,oo,oo};
        node bestR = node{0,oo,oo};
        for (l +=k, r += k; l < r; l >>= 1, r >>= 1){
            if(l&1)bestL=merge(bestL, st[l++]);
            if(r&1)bestR=merge(st[--r], bestR);
        }
        return merge(bestL,bestR);
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
            int x; cin >> x;
            x --;
            cout << min(st.query(0, x+1).ri, st.query(x, n).le) << "\n";
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