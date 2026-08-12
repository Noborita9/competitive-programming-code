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

void solve()
{
    int n, q; cin >> n >> q;
    string s, t; cin >> s >> t;
    vec<vec<int>> pf(n + 1, vec<int>(4));
    L(i,0,n)
    {
        pf[i + 1][0] = pf[i][0] + ((s[i] == t[i] && s[i] == '0') ? 1 : 0);
        pf[i + 1][1] = pf[i][1] + ((s[i] == t[i] && s[i] == '1') ? 1 : 0);
        pf[i + 1][2] = pf[i][2] + ((s[i] != t[i] && s[i] == '0') ? 1 : 0);
        pf[i + 1][3] = pf[i][3] + ((s[i] != t[i] && s[i] == '1') ? 1 : 0);
    }

    while(q--)
    {
        int l, r; cin >> l >> r;
        int t0 = pf[r][0] - pf[l - 1][0];
        int t1 = pf[r][1] - pf[l - 1][1];
        int t2 = pf[r][2] - pf[l - 1][2];
        int t3 = pf[r][3] - pf[l - 1][3];
        int pr = min(t2, t3);
        t2 -= pr;
        t3 -= pr;

        if ((t2 + t3) <= (t0 + t1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
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