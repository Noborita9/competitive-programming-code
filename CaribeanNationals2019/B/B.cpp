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

struct STI {
    vec<ll> st; int n, K;
    STI(vec<ll> &a): n(SZ(a)), K(1) {
        while(K<=n) K<<=1;
        st.assign(2*K, 0); // 0 default
        L(i,0,n) st[K+i] = a[i];
        for (int i = K - 1; i > 0; i --) st[i] = st[i*2] + st[i*2+1];}
    void upd(int i, ll w) {
        i += K; st[i] += w;
        while(i>>=1)st[i]=st[i*2]+st[i*2+1];}
    ll query(int l, int r) { // [l, r)
        ll res = 0;
        for (l += K, r += K; l < r; l>>=1, r>>=1){
            if (l & 1) res += st[l++];
            if (r & 1) res += st[--r];
        } 
        return res;
    }
};


void solve()
{
    int n; cin >> n;
    const ll MOD = 998244353LL;
    vec<int> p(n);
    vec<ll> f(n + 1, 1);    
    L(i,0,n) cin >> p[i];
    vec<ll> a(n + 1, 1);
    STI st(a);
    ll ans = 0;
    L(i,1,n + 1) f[i] = (f[i - 1] * i) % MOD;
    st.upd(0, -1);
    L(i,0,n)
    {
        st.upd(p[i], -1);
        ans += (ll)st.query(1,p[i]) * f[n - 1 - i];
        cout << st.query(1, p[i]) << " " << f[n - 1 - i] << "\n";
        ans %= MOD;
    }

    cout << ans << "\n";
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