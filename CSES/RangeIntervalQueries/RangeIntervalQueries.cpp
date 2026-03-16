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
        st.assign(2*k,0);
        // for (int i = k - 1; i > 0; i --) st[i] = st[2*i]+st[2*i+1];
    }
    void upd(int i, int x){
        i+=k;st[i]+=x;
        while(i>>=1)st[i]=st[2*i]+st[2*i+1];
    }

    int query(int l, int r){
        int ans = 0;
        for (l += k, r += k; l < r; l>>=1, r>>=1) {
            if(l&1)ans+=st[l++];
            if(r&1)ans+=st[--r];
        }
        return ans;
    }
};



const int QIN = 0;
const int NUMBER = 1;
const int QOUT = 2;


using iii = tuple<int,int,int,int,int>;
            // {x, Type, b, c, d}
            // [Qin] -> {mn, Qin, mx, le, ri}
            // [Number] -> {x, Number, 0, 0, 0}
            // [Qout] -> {mx, Qout, mn, le, ri}

void solve()
{
    int n, q; cin >> n >> q;
    vec<iii> E;
    E.reserve(n + 2 * q);
    L(i,0,n) {
        int x; cin >> x;
        E.eb(x, NUMBER, i,0,0);
    }
    L(i,0,q){
        int le, ri, mn, mx; cin >> le >> ri >> mn >> mx;
        E.eb(mn, QIN, i, le-1, ri);
        E.eb(mx, QOUT, i, le-1, ri);
    }
    sort(ALL(E));
    ST st(n);
    vec<int> ans(q);
    for (auto [x, t, a, b, c]: E) { // Just sorted by x_i-1 <= x_i
        if (t == NUMBER) {
            st.upd(a, 1);
        } else if (t == QIN) {
            ans[a] -= st.query(b, c);
        } else {
            ans[a] += st.query(b, c);
        }
    }
    L(i,0,q) cout << ans[i] << "\n";
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