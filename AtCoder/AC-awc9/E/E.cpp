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

struct SPT {
    vec<vec<int>> st;
    SPT(vec<int> &a) {
        int n = SZ(a), K = 0; while((1<<K)<=n) K ++;
        st = vec<vec<int>>(K, vec<int>(n));
        L(i,0,n) st[0][i] = a[i];
        L(i,1,K) for (int j = 0; j + (1 << i) <= n; j ++) 
            st[i][j] = min(st[i-1][j], st[i - 1][j + (1 << (i - 1))]); // change op
    }
    int get(int l, int r) {
        int bit = log2(r - l + 1);
        return min(st[bit][l], st[bit][r - (1<<bit) + 1]); // change op
    }
};

struct SPTMax {
    vec<vec<int>> st;
    SPTMax(vec<int> &a) {
        int n = SZ(a), K = 0; while((1<<K)<=n) K ++;
        st = vec<vec<int>>(K, vec<int>(n));
        L(i,0,n) st[0][i] = a[i];
        L(i,1,K) for (int j = 0; j + (1 << i) <= n; j ++) 
            st[i][j] = max(st[i-1][j], st[i - 1][j + (1 << (i - 1))]); // change op
    }
    int get(int l, int r) {
        int bit = log2(r - l + 1);
        return max(st[bit][l], st[bit][r - (1<<bit) + 1]); // change op
    }
};


void solve()
{
    int n, q; cin >> n >> q;
    vec<int> a(n); L(i,0,n) cin >> a[i];
    SPT spt(a);
    SPTMax stpmax(a);
    L(qi,0,q){
        int l, r; cin>> l >> r;
        l --; r --;
        int mx = stpmax.get(l, r);
        int mn = spt.get(l, r);
        cout << mx - mn << "\n";
    }
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