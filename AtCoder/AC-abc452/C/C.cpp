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
    int n; cin >> n;
    vec<int> a(n), b(n);
    L(i,0,n )cin >> a[i] >> b[i];
    int m; cin >> m;
    vec<string> s(m); L(i,0,m) cin >> s[i];
    vec<vec<vec<int>>> dp(26, vec<vec<int>>(11, vec<int>(11)));
    L(i,0,m) {
        L(j,0,SZ(s[i])){
            int x = s[i][j] - 'a';
            dp[x][j][SZ(s[i])] = 1;
        }
    }
    for (const string t: s) {
        if (SZ(t) != n) {
            cout << "No\n";
            continue;
        }
        bool pos = 1;
        L(i,0,SZ(t)) {
            pos = pos && dp[t[i]-'a'][b[i]-1][a[i]];
        }
        cout << (pos ? "Yes" : "No" ) << "\n";
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