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
    vec<int> st; int k;
    ST(int n): k(1) {
        while(k<=n)k<<=1;
        st.assign(2*k,1);
        for (int i = k - 1; i > 0; i --) st[i] = st[2*i]+st[2*i+1];
    }
    void upd(int i, int x){
        i+=k;st[i]+=x;
        while(i>>=1)st[i]=st[2*i]+st[2*i+1];
    }
    int query(int w) {
        int v = 1;
        while(v < k) {
            if (st[2*v]>=w) v = 2 * v;
            else {
                w -= st[2*v];
                v = 2 * v + 1;
            }
        }
        return v - k;
    }
};


void solve()
{
    int n; cin >> n;
    vec<int> a(n); L(i,0,n) cin >> a[i];
    ST st(n);
    L(i,0,n){
        int ix; cin >> ix;
        int u = st.query(ix);
        cout << a[u] << " ";
        st.upd(u, -1);
    }
    cout << "\n";
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