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
    vec<ll> st; int n;
    ST(int n, ll d): st(4 * n + 5), n(n) {build(1,0,n,d);}
    void build(int v, int L, int R, ll d){
        if (R - L == 1) st[v] = d;
        else {
            int m = (L + R) / 2;
            build(2 * v, L, m);
            build(2 * v + 1, m, R);
        }
    }
    void upd(int v, int L, int R, int ql, int qr) {
        if (qr <= L || R <= ql) return;
        if (ql <= L && R <= qr) {
            st[v] --;
            return;
        }
        
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    vec<int> l(n), r(m);
    L(i,0,n) cin >> l[i];
    L(i,0,m) cin >> r[i];
    
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