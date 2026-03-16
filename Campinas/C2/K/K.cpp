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
    vec<int> st;
    int k;
    ST(int n): k(1) {
        while (k <= n) k<<=1;
        st.assign(k * 2, 0);
    }
    int query(int l, int r) { 
        int res = 0;
        for (l += k, r += k; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, st[l ++]);
            if (r & 1) res = max(res, st[-- r]);
        }
        return res;
    }
    void update(int i, int x){
        int pos = i + k;
        st[pos] = x;
        while((pos >>= 1) > 0) st[pos] = max(st[pos * 2], st[pos * 2 + 1]);
    }
};


int n;
void solve()
{
    vec<int> a(n), lis(n);
    ST st(n + 1);
    int mxLis = 0;
    int lixs = 0;
    L(i,0,n) {
        cin >> a[i];
        if (a[i] == 0) continue;
        int mx = st.query(0, a[i]);
        // cout << "Query" << endl;
        st.update(a[i], mx + 1);
        // cout << "Update" << endl;
        lis[i] = mx + 1;
        if (lis[i] >= mxLis){
            mxLis = lis[i];
            lixs = i;
        }
    }
    vec<int> imp(n), back(n + 1, - 1);
    back[mxLis] = a[lixs];
    imp[lixs] = 1;
    for (int i = lixs - 1; i >= 0; i --){
        if (a[i] == 0) continue;
        if (mxLis == lis[i]) {
            back[mxLis] = max(back[mxLis], a[i]);
            imp[i] = 1;
        } else{
            if (a[i] < back[lis[i] + 1]) {
                back[lis[i]] = max(back[lis[i]], a[i]);
                imp[i] = 1;
            }
        }
    }
    vec<pair<int, int>> upd; // {lis[i], a[i]}
    vec<int> mn(n + 1, n + 10);
    vec<int> pref(n + 2);
    upd.pb({0,0});
    L(i,0,n) {
        if (a[i] == 0) {
            for (const auto &[l, ai]: upd){
                mn[l] = min(mn[l], ai);
            }
            upd.clear();
        } else {
            if (imp[i]) {
                int rng = a[i] - mn[lis[i] - 1] - 1;
                if (rng > 0) {
                    pref[mn[lis[i] - 1] + 1] ++;
                    pref[a[i]] --;
                }
            }
            upd.pb({lis[i], a[i]});
        }
    }
    int acc = lis[0];
    int mnLi = a[0];
    L(i,1,n) {
        if (a[i] == 0 && acc == mxLis) {
            // cout << i << ": " << acc << " " << mnLi << " " << mxLis << "\n";
            pref[mnLi + 1] ++;
            continue;
        }
        if (lis[i] > acc) {
            acc = lis[i];
            mnLi = a[i];
        } else if (lis[i] == acc) {
            mnLi = min(a[i], mnLi);
        }
    }
    if (a.back() == 0) {
        int mnL = n + 10;
        L(i,0,n) if (lis[i] == mxLis) mnL = min(mnL, a[i]);
        if (mnL == n + 10) pref[0] ++;
        else pref[mnL + 1] ++;
    }
    L(i,1,n + 1) pref[i] += pref[i - 1];
    ll score = 0;
    // L(i,0,n + 1) cout << pref[i] << " "; cout << "\n";
    L(i,1,n + 1) {
        score += 1LL *(mxLis + (pref[i]>0)) *(ll)i;
    }
    cout << score << "\n";
    // L(i,0,n) cout << imp[i] << " "; 
    // cout << "\n";
    // L(i,0,n) cout << lis[i] << " ";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    // cin >> TT;
    while (1)
    {
        cin >> n; if (n == 0) break;
        solve();
    }
}