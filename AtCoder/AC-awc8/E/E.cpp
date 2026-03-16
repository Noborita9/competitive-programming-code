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
        st.assign(2*k,0);
    }
    void upd(int i, ll x){
        i+=k;st[i]+=x;
        while(i>>=1)st[i]=st[2*i]+st[2*i+1];
    }
    ll query(int l, int r){
        ll ans = 0;
        for (l+=k,r+=k;l<r;l>>=1,r>>=1){
            if(l&1)ans+=st[l++];
            if(r&1)ans+=st[--r];
        }
        return ans;
    }
};

void solve()
{
    int n; cin >> n;
    ST st(n + 1);
    ll ans = 0;
    L(i,0,n){
        int x; cin >> x;
        ans += st.query(x + 1, n + 1);
        st.upd(x, 1);
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