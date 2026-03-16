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

using ii = pair<ll, int>;

const ii oo = {-1,-1};

ii merge(ii a, ii b){
    if(a.first==-1)return b;
    if(b.first==-1)return a;
    if(a.first>b.first)return a;
    if(b.first>a.first)return b;
    return {a.first, min(a.second,b.second)};
}

struct ST {
    vec<ii> st; int n;
    ST(vec<ll> &a): st(4 * SZ(a) + 5), n(SZ(a)) {
        build(1,0, n, a);
    }
    void build(int v, int L, int R, vec<ll>&a){
        if (R - L == 1){
            st[v] = {a[L], L};
        } else {
            int m = (L + R) / 2;
            build(2 * v, L, m, a);
            build(2 * v + 1, m, R, a);
            st[v] = merge(st[2 * v], st[2 * v + 1]);
        }
    }
    void upd(int v, int L, int R, int pos, ll w) {
        if (R - L == 1){
            st[v].first -= w;
            return;
        }
        int m = (L + R) / 2;
        if (pos < m )upd(2 * v, L, m, pos, w);
        else upd(2 * v + 1, m, R, pos, w);
        st[v] = merge(st[v*2],st[v*2+1]);
    }
    ii query(int v, int L, int R, ll w){
        if (st[v].first < w) return oo;
        if (R - L == 1) return st[v];
        int m = (L + R) / 2;
        ii ql = query(2 * v, L, m, w);
        if (ql == oo) return query(2 * v + 1, m , R, w);
        return ql;
    }
    void upd(int x, ll w){
        upd(1, 0, n, x, w);
    }
    ii query(ll x){
        return query(1, 0, n,x);
    }
};


void solve()
{
    int n, q; cin >> n >> q;
    vec<ll> h(n); L(i,0,n) cin >> h[i];
    ST st(h);
    while(q--)
    {
        ll w; cin >> w;
        ii qr = st.query(w);
        if (qr == oo) {
            cout << "0 ";
        } else {
            cout << qr.second+1<< " ";
            st.upd(qr.second, w);
        }
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