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
    int n, c; cin >> n >> c;
    vec<vec<bool>> vis(2, vec<bool>(n));
    vec<bool> cu(n);
    c --;
    vis[0][c] = 1;
    vec<string> s(n);
    L(i,0,n) cin >> s[i];
    reverse(ALL(s));
    L(i,0,n) {
        if (s[0][i] == '.') cu[i] = 1;
    }
    L(i,1,n){
        string &f = s[i];
        int cur = i % 2;
        int prev = 1 - cur;
        L(j,0,n) {
            vis[cur][j] = 0;
            if (f[j] == '.' || cu[j]) {
                vis[cur][j] = vis[prev][j];
            }
            if (j - 1 >= 0) {
                if (f[j] == '.' || cu[j]) vis[cur][j] = vis[cur][j] || vis[prev][j - 1];
            }
            if (j + 1 < n) {
                if (f[j] == '.' || cu[j]) vis[cur][j] = vis[cur][j] || vis[prev][j + 1];
            }
            if (f[j] == '#' && !vis[cur][j]) cu[j] = 0;
        }
    }
    int nth = 1 - (n % 2);
    L(i,0,n) {
        cout << vis[nth][i];
    }
    cout << "\n";
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