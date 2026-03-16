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

struct ST {
    vec<ll> st; int k;
    ST(int n): k(1){
        while(k<=n)k<<=1;
        st.assign(2*k,0);
    }
    void upd(int i, ll w){
        i += k; st[i] = w;
        while(i>>=1)st[i]=max(st[2*i],st[2*i+1]);
    }
    ll query(int l, int r){
        ll ans = l == r ? 0 : -oo;
        for(l+=k,r+=k;l<r;l>>=1,r>>=1){
            if(l&1)ans=max(ans,st[l++]);
            if(r&1)ans=max(ans,st[--r]);
        }
        return ans;
    }
};


void solve()
{
    int n, k; cin >> n >> k;
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    ST st(n);
    L(i,0,n){
        st.upd(i, st.query(max(0, i - k), i) + a[i]);
    }
    cout << st.query(n - 1, n) << "\n";
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