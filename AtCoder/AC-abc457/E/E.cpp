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
    ST(int n): k(1){
        while(k<=n)k<<=1;
        st.assign(2*k,-1);
    }
    void upd(int i, int w) {
        i += k; st[i] = max(st[i], w);
        while (i >>= 1) st[i] = max(st[2 * i], st[2 * i + 1]);
    }
    int query(int l, int r){
        int ans = -1;
        for (l += k, r += k; l < r; l >>= 1, r >>= 1){
            if (l & 1) ans = max(ans, st[l++]);
            if (r & 1) ans = max(ans, st[--r]);
        }
        return ans;
    }
};

using ii = pair<int,int>;
void solve()
{
    int n, m; cin >> n >> m;
    ST st(n);
    vec<vec<int>> left(n), right(n);
    set<ii> existing;
    L(i,0,m){
        int l, r; cin >> l >> r;
        l --; r --;
        left[l].pb(r);
        right[r].pb(-l);
        existing.insert({l, r});
        st.upd(r, l);
    }
    L(i,0,n) {
        sort(ALL(left[i]));
        sort(ALL(right[i]));
    }
    int q; cin >> q;
    L(i,0,q){
        int l, r; cin >> l >> r; l --; r --;
        if (existing.find(pair{l,r}) != existing.end()) {
            // This is a border case
            if (SZ(left[l]) > 1 && (left[l][0] != r || left[l][1] == r)) {
                cout << "Yes\n";
                continue;
            }
            if (SZ(right[r]) > 1 && (right[r][0] != -l || right[r][1] == -l)) {
                cout << "Yes\n";
                continue;
            }
            if (st.query(l, r) >= l) {
                cout << "Yes\n";
                continue;
            }
            cout << "No\n";
            continue;
        }
        int fl = l - 1;
        int fr = r + 1;
        if (!left.empty()){
            auto it = upper_bound(ALL(left[l]), r);
            if (it != begin(left[l])) { // I go outside and come back
                it --; fl = *it;
            } else {
                cout << "No\n";
                continue;
            }
        }
        if (!right.empty()){
            auto it = upper_bound(ALL(right[r]), -l);
            if (it != begin(right[r])) { // I go outside and come back
                it --; fr = 0-*it;
            } else {
                cout << "No\n";
                continue;
            }
        }

        // cout << "FL: " << fl << " - " << "FR: " << fr << "\n";
        cout << ((fl + 1 >= fr) ? "Yes" : "No") << "\n";
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