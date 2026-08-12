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
    string s; cin >> s;
    int n = SZ(s);
    vec<int> c(26);
    L(i,0,n) c[s[i] - 'A'] ++;
    int imp = 0;
    L(i,0,26) if (c[i] & 1) imp ++;
    string md = "";
    if (imp > 1) {
        cout << "NO SOLUTION\n";
        return;
    } else if (imp == 1) {
        L(i,0,26) if (c[i] & 1) {
            md += (char)('A'+i);
            c[i] --;
        }
    }
    string front = "";
    L(i,0,26) {
        while (c[i]) {
            front += (char)('A'+i);
            c[i] -= 2;
        }
    }
    cout << front << md;
    reverse(ALL(front));
    cout<<front << "\n";
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