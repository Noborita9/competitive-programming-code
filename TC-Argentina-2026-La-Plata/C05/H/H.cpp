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

const int N = 1504;
char g[N][N];
pair<int,int> fv[N][N];
bool vis[N][N]; 

void solve()
{
    int n, m; cin >> n >> m;
    int si = 0;
    int sj = 0;
    L(i,0,n){
        L(j,0,m){
            cin >> g[i][j];
            if (g[i][j] == 'S') {
                si = i; sj = j;
            }
        }
    }
    bool pos = 0;
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {-1,1,0,0};
    auto go = [&](auto && dfs, int x, int y) -> void {
        L(k,0,4) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int norx = ((nx % n) + n ) % n;
            int nory = ((ny % m) + m) % m;
            if (pos)return;
            if (g[norx][nory] == '#') continue;
            if (vis[norx][nory]) {
                if (fv[norx][nory].first != nx || fv[norx][nory].second != ny) {
                    pos = 1;
                    return;
                }
                continue;
            }
            vis[norx][nory] = 1;
            fv[norx][nory] = {nx, ny};
            dfs(dfs, nx, ny);
        }
    };  
    fv[si][sj] = {si, sj};
    vis[si][sj] = 1;
    go(go, si, sj);

    cout << (pos ? "YES" : "NO") << "\n";
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