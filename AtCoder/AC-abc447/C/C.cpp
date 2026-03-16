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
    string s, t; cin >> s >> t;
    string sa = "", st = "";
    for (char c: s) if (c != 'A') sa+=c;
    for (char c: t) if (c != 'A') st+=c;
    if (sa != st){
        cout << "-1\n";
        return;
    }
    // It's possible
    int ops = 0;
    int i = 0; // s
    int j = 0; // t
    // Voy por t matcheando s
    while (1)
    {
        if (j == SZ(t)) {
            // ended matching t, erase remaining 'A's
            while(i < SZ(s)) {
                i ++;
                ops ++;
            }
            break;
        }
        if (t[j] == 'A') {
            if (i < SZ(s) && s[i] == 'A') {
                i ++;
                j ++;
                continue;
            }
            ops ++;
            j ++;
        } else {
            if (i < SZ(s) && s[i] == t[j]) {
                i ++;
                j ++;
                continue;
            }
            if (i < SZ(s)) {
                // does not match, remove A
                i ++;
                ops ++;
            }
        }
    }
    cout << ops << "\n";

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