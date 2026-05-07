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
    ST(int n): k(1) {
        while(k<=n)k<<=1;
        st.assign(k*2,0);
    }
    void upd(int i, ll w) {
        i+=k; st[i] += w;
        while(i>>=1) st[i] = st[2 * i] + st[2 * i + 1];
    }
    ll query(int l, int r) {
        ll ans = 0;
        for (l += k, r += k; l < r; l >>= 1, r>>= 1){
            if (l & 1) ans += st[l++];
            if (r & 1) ans += st[--r];
        }
        return ans;
    }
};

void solve()
{
    int n, m; cin >> n >> m; 
    ST st(n + 1);
    vec<int> q(m);
    L(i,0,m) {
        cin >> q[i];
        st.upd(q[i], 1);
    }
    ll ans = 0;
    L(i,0,m){
        st.upd(q[i], -1);
        ans += st.query(0, q[i]);
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