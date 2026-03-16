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

const int N = 510;

char g[N][N];

using ii = pair<int, int>;
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
void solve()
{
    int n, m; cin >> n >> m;
    const int oo = 1e9;
    vec<vec<int>> dist(n, vec<int>(m, oo));
    L(i,0,n) L(j,0,m) cin >> g[i][j];
    deque<ii> q;
    q.push_front({0,0});
    dist[0][0] = 0;
    while(SZ(q)){
        auto [x, y] = q.front(); q.pop_front();
        L(k,0,4){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (g[nx][ny] == '.') {
                if (dist[nx][ny] > dist[x][y]) {
                    dist[nx][ny] = dist[x][y];
                    q.push_front({nx,ny});
                }
            } else {
                if (dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push_back({nx,ny});
                }
            }
        }
    }
    cout << dist[n-1][m-1] << "\n";
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