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


const ll mod = (ll)1e9 + 7;

struct ST {
    vec<ll> st; int k;
    ST(int n): k(1) {
        while(k<=n)k<<=1;
        st.assign(2*k,0ll);
    }
    void upd(int x, ll w){
        x+=k;(st[x]+=w)%=mod;
        while(x>>=1)st[x]=st[2*x]+st[2*x+1];
    }
    ll query(int l, int r) {
        ll sm = 0;
        for(l+=k,r+=k;l<r;l>>=1,r>>=1){
            if(l&1)(sm+=st[l++])%=mod;
            if(r&1)(sm+=st[--r])%=mod;
        }
        return sm;
    }
};

void solve()
{
    int n; cin >> n;
    vec<int> a(n); L(i,0,n) cin >> a[i];
    vec<int> raw(ALL(a));
    raw.pb(0);
    sort(ALL(raw));
    raw.erase(unique(ALL(raw)),end(raw));
    auto idx = [&](int x){return lower_bound(ALL(raw), x) - begin(raw);};
    L(i,0,n) a[i] = idx(a[i]);
    ST st(SZ(raw));
    st.upd(0,1);
    L(i,0,n){
        st.upd(a[i], st.query(0,a[i]));
    }
    cout << st.query(1,SZ(raw)) <<'\n';
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