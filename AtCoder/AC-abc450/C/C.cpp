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

const int dx[4] = {-1, 1, 0 ,0};
const int dy[4] = {0, 0, -1, 1};

void solve()
{
    int n, m; cin >> n >> m;
    vec<vec<char>> g(n, vec<char>(m));
    L(i,0,n){
        L(j,0,m){
            cin >> g[i][j];
        }
    }
    vec<vec<bool>> vis(n, vec<bool>(m));
    auto go = [&](auto && dfs, int i, int j) -> void {
        if (vis[i][j]) return;
        vis[i][j] = 1;
        L(k,0,4){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni<0 || nj <0 || ni >= n || nj >= m) continue;
            if (!vis[ni][nj] && g[ni][nj] == '.') dfs(dfs, ni, nj);
        }
    };
    L(i,0,m) if (g[0][i]=='.') go(go, 0, i);
    L(i,0,m) if (g[n - 1][i]=='.') go(go, n - 1, i);
    L(i,0,n) if (g[i][0] == '.') go(go, i, 0);
    L(i,0,n) if (g[i][m - 1] == '.') go(go, i, m - 1);
    int ans = 0;
    L(i,1,n - 1) {
        L(j,1, m - 1) {
            if (!vis[i][j] && g[i][j] == '.') {
                ans ++;
                go(go, i, j);
            }
        }
    }
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