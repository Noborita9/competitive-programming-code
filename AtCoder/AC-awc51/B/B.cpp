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
    vec<pair<char, int>> g;
    int ln = 1;
    char c = s[0];
    int n = SZ(s);
    g.pb({c, ln});
    L(i,1,n){
        if (s[i]==g.back().first) g.back().second++;
        else {
            ln = 1;
            c = s[i];
            g.pb({c, ln});
        }
    }
    for (auto [lt, cnt]: g){
        cout << lt;
        if (cnt>1) cout << cnt;
    }
    cout << "\n";
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