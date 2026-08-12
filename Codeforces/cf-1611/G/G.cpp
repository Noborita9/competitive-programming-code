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

const ll oo = 1e18;
struct ST { // max st with 0s as defualt
    int n;vec<ll> st, lz;
    ST(int n_): n(n_), st(4*n+5, oo), lz(4*n+5) {}
    void push(int v, int L, int R){
        if (lz[v]) {
            if (R - L > 1) {
                st[2 * v] += lz[v];
                st[2 * v + 1] += lz[v];
                lz[2 * v] += lz[v];
                lz[2 * v + 1] += lz[v];
            }
            lz[v] = 0;
        }
    }
    void upd(int v, int L, int R, int ql, int qr, ll w) {
        if (qr <= L || ql >= R) return;
        push(v, L, R);
        if (ql <= L && R <= qr){
            lz[v] = w;
            st[v] += w;
            return;
        } 
        int m = (L + R) / 2;
        upd(2 * v, L, m, ql, qr, w);
        upd(2 * v + 1, m, R, ql, qr, w);
        st[v] = min(st[2*v], st[2*v+1]);
    }
    ll query(int v, int L, int R, int ql, int qr) {
        if (ql >= R || qr <= L) return oo;
        push(v, L, R);
        if(ql <= L && R <= qr) return st[v];
        int m = (L + R) / 2;
        return min(query(2 * v, L, m, ql, qr), query(2 * v + 1, m, R, ql, qr));
    }
    ll queryP(int v, int L, int R, int x) {
        push(v, L, R);
        if (R - L == 1) return st[v];
        int m = (L + R) / 2;
        if (x < m) return queryP(2 * v, L, m, x);
        return queryP(2 * v + 1, m, R, x);
    }
    void print(int v, int L, int R){
        push(v, L, R);
        if (R - L == 1) cout << st[v] << " ";
        else {
            int m = (L + R) / 2;
            print(2 * v, L, m);
            print(2 * v, m, R);
        }
    }
    void insert(int v, int L, int R, int x, ll w){
        push(v, L, R);
        if (R - L == 1){
            st[v] = w;
            return;
        }
        int m = (L + R) / 2;
        if (x < m) insert(2 * v, L, m, x, w);
        else insert(2 * v + 1, m, R, x, w);
        st[v] = min(st[2 * v], st[2 * v + 1]);
    }
    void upd(int l, int r, ll w){return upd(1,0,n,l,r,w);}
    ll query(int l, int r){return query(1,0,n,l,r);}
    ll queryP(int x){return queryP(1,0,n,x);}
    void insert(int x, ll w){insert(1,0,n,x,w);}
    void print(){print(1,0,n); cout << "\n";}
};

void solve()
{
    int n; ll s; cin >> n >> s;
    // sliding windows of the state with segment tree??
    vec<ll> a(n + 1); L(i,0,n) cin >> a[i + 1];
    int i = 1;
    int j = 1;

    int bL = -1;
    int bR = -1;
    int bestRng = 0;

    ST st(n + 1);
    st.insert(0, s);
    
    while (i <= n){
        ll curState = st.queryP(i - 1) + a[i];
        st.insert(i, curState);
        while (j <= i && st.query(j, i + 1) < 0) {
            st.upd(j, i + 1, -a[j]);
            j ++;
        }
        int rng = i - j + 1;
        if (rng > bestRng) {
            bL = j;
            bR = i;
            bestRng = rng;
        }
        i ++;
        // st.print();
    }
    if (bestRng == 0){
        cout << "-1\n";
        return;
    }
    cout << bL << " " << bR << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}