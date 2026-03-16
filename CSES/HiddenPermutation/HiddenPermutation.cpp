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

bool ask(int i, int j){
    cout << "? " << i << " " << j << endl;
    string s; cin >> s;
    return s == "YES";
}

void ans(vec<int> &out){
    cout << "!";
    L(i,0,SZ(out)) cout << " " << out[i];
    cout << endl;
}

void msort(vec<int> &out, int l, int r){
    if (r - l + 1 <= 1) return;
    int m = (l + r) / 2;
    msort(out, l, m);
    msort(out, m + 1, r);
    int szl = m - l + 1;
    int szr = r - m;
    if (szl == 0 || szr == 0) return;
    vec<int> le(szl);
    vec<int> ri(szr);
    for (int i = l; i < l + szl; i ++) le[i - l] = out[i];
    for (int i = (m + 1); i < (m + 1) + szr; i ++) ri[i - (m + 1)] = out[i];
    // ans(le);
    // ans(ri);
    int lp = 0;
    int rp = 0;
    int k = 0;
    while (lp < szl || rp < szr) {
        if (lp == szl) {
            out[l + k] = ri[rp++];
        } else if (rp == szr) {
            out[l + k] = le[lp++];
        } else {
            if (ask(le[lp], ri[rp])) {
                
            }
        }
        k ++;
    }
}

void solve()
{
    int n; cin >> n;
    vec<int> out(n);
    iota(ALL(out), 1);
    msort(out, 0, n - 1);
    ans(out);
}


int main()
{
    // ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    //cin >> TT;
    while (TT--)
    {
        solve();
    }
}