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
    ST(const vec<ll>&a): k(1){
        int n = SZ(a);
        while(k<=n)k<<=1;
        st.assign(2*k,0);
        L(i,0,n)st[k+i]=a[i];
        for (int i = k - 1; i > 0;i--) st[i]=st[2*i]+st[2*i+1];
    }
    void upd(int i, ll v){
        i+=k;st[i]=v;
        while(i>>=1)st[i]=st[2*i]+st[2*i+1];
    }
    ll query(int l, int r){
        ll ans = 0;
        for (l+=k, r +=k; l < r; l>>=1,r>>=1){
            if(l&1)ans+=st[l++];
            if(r&1)ans+=st[--r];
        }
        return ans;
    }
};


void solve()
{
    int n, q; cin >> n >> q;
    vec<ll> a(n);
    L(i,0,n) cin >> a[i];
    ST st(a);
    // cout << st.query(0, 0) << " " << st.query(0, 1) << "\n";
    L(i,0,q){
        int op; cin >> op;
        if (op == 1) {
            int l, r; cin >> l >> r;
            l --; r--;
            cout << st.query(l, r + 1) << "\n";
        } else {
            int x; ll v; cin >> x >> v;
            x --;
            st.upd(x, v);
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