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

using my_clock = chrono::steady_clock;
mt19937_64 engine(my_clock::now().time_since_epoch().count());

struct SPT {
    vec<vec<int>> st;
    SPT(vec<int> &a) {
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
    int n; cin >> n;
    const int oo = 1e9;
    vec<int> a(n + 2, -oo);
    vec<vec<int>> el(n + 1);
    L(i,0,n + 1) el[i].pb(0);
    L(i,1,n+1) {cin >> a[i]; a[i] --; el[a[i]].eb(i);}
    L(i,0,n + 1) el[i].pb(n + 1);
    vec<ll> shs(n);
    vec<ll> sid(n);
    L(i,0,n)
    {
        sid[i] = engine();
        shs[i] = sid[i];
        if (i > 0) shs[i] += shs[i - 1];
    }
    vec<ll> ha(n + 2);
    L(i,0,n) {
        ha[i + 1] = ha[i] + sid[a[i + 1]];
    }
    auto get = [&](int l, int r) {
        return ha[r] - ha[l - 1];
    };
    SPT st(a);
    ll ans = 0;
    auto go = [&](auto && rec, int l, int r) -> void {
        if (r < l) return;
        if (r == l) {
            ans += a[l] == 0;
            return;
        }
        int mx = st.get(l, r);
        int ix = *lower_bound(ALL(el[mx]), l);
        rec(rec, l, ix - 1); // recurse
        rec(rec, ix + 1, r); // recurse

        int lsz = ix - l;
        int rsz = r - ix;
        if (lsz <= rsz) {
            for (int x = max(l, ix - mx); x <= ix && x + mx <= r; x ++){
                ans += get(x, x + mx) == shs[a[ix]];
            }
        } else {
            for (int x = min(r, ix + mx); x >= ix && x - mx >= l; x --) {
                ans += get(x - mx, x) == shs[a[ix]];
            }
        }
    };
    go(go, 1, n);
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