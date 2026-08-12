#include <bits/stdc++.h>
using namespace std;
#define L(i,j,n) for(int i=j;i<int(n);i++)
#define ALL(x) begin(x),end(x)
#define SZ(x) int(x.size())
#define vec vector
#define pb push_back
#define eb emplace_back
using ll=long long;
using ld=long double;

const ll mod = (1LL << 61) - 1;
inline ll modmul(ll a, ll b){
    __int128 p = (__int128)a * b;
    ll hi = (ll)(p >> 61);
    ll lo = (ll)(p & mod);
    ll res = hi + lo;
    if (res >= mod) res -= mod;
    return res;
}
inline ll modsum(ll a, ll b){
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

using ii = pair<int,int>;
using iii = tuple<int, int,int>;
const int oo = 1e9;
const int N = 1005;
char g[N][N];
vec<iii> fg[N][N];
vec<iii> rg[N][N];
int dist[N][N];
ll rp1[N][N];
ll fp1[N][N];
bool vis[N][N];
bool ap[N][N];
int dfs_low[N][N], dfs_num[N][N];
int dfs_time = 0;


void solve(){
    int n, m; cin >> n >> m;
    L(i,0,n){
        L(j,0,m){
            cin >> g[i][j];
            dist[i][j] = oo;
            dfs_low[i][j] = dfs_num[i][j] = -1;
        }
    }
    dist[0][0] = 0;
    queue<ii> q;
    q.push({0,0});
    const int dx[4] = {0 ,0, -1, 1};
    const int dy[4] = {-1, 1, 0, 0};
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        L (k,0,4) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny] == 'X') continue;
            if (dist[nx][ny] == oo) {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
                fg[x][y].eb(nx, ny, 1);
            } else if (dist[nx][ny] > dist[x][y]) {
                fg[x][y].eb(nx, ny, dist[nx][ny] == dist[x][y] + 1);
            }
        }
    }
    L(i,0,n)L(j,0,m) dist[i][j] = oo;
    dist[n - 1][m - 1] = 0;
    q.push({n - 1, m - 1});
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        // cout << "@: " << x << " " << y << "\n";
        L (k,0,4) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny] == 'X') continue;
            // cout << nx << " " << ny << " " << dist[nx][ny] << "\n";
            if (dist[nx][ny] == oo) {
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
                rg[x][y].eb(nx, ny, 1);
            } else if (dist[nx][ny] > dist[x][y]) {
                rg[x][y].eb(nx, ny, dist[nx][ny] == dist[x][y] + 1);
            }
            // dist[nx][ny] =dist[x][y] + 1;
            // rg[x][y].eb(nx, ny);
            // q.push({nx, ny});
        }
    }
    auto calcR1 = [&](auto && dfs, int x, int y) -> void {
        if (vis[x][y]) return ;
        vis[x][y] = 1;
        rp1[x][y] = 0;
        for (const auto &[nx, ny, dt]: rg[x][y]) if (dt >= 1) {
            dfs(dfs, nx, ny);
            rp1[x][y] = modsum(rp1[x][y], rp1[nx][ny]);
        }
    };
    vis[0][0] = 1;
    rp1[0][0] = 1;
    calcR1(calcR1, n - 1, m - 1);
    L(i,0,n)L(j,0,m)vis[i][j] = 0;
    auto calcF1 = [&](auto && dfs, int x, int y) -> void {
        if (vis[x][y]) return ;
        vis[x][y] = 1;
        fp1[x][y] = 0;
        for (const auto &[nx, ny, dt]: fg[x][y]) if (dt >= 1) {
            dfs(dfs, nx, ny);
            fp1[x][y] = modsum(fp1[x][y], fp1[nx][ny]);
        }
    };
    vis[n - 1][m - 1] = 1;
    fp1[n - 1][m - 1] = 1;
    calcF1(calcF1, 0, 0);
    auto tarjan = [&](auto && dfs, int x, int y, int px, int py) -> bool {
        dfs_low[x][y] = dfs_num[x][y] = dfs_time ++;
        bool has_target = (x == n -1 && y == m- 1);
        L(k,0,4){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny] == 'X') continue;
            if (nx == px and ny == py) continue;
            if (dfs_num[nx][ny] == -1) {
                bool cht = dfs(dfs, nx, ny, x, y);
                dfs_low[x][y] = min(dfs_low[x][y], dfs_low[nx][ny]);
                if (dfs_low[nx][ny] >= dfs_num[x][y] && cht) {
                    ap[x][y] = 1;
                }
                has_target |= cht;
            }  else dfs_low[x][y] = min(dfs_low[x][y], dfs_num[nx][ny]);
        }
        return has_target;
    };
    tarjan(tarjan, 0, 0, -1, -1);
    // L(i,0,n){
    //     L(j,0,m){
    //         cout << ap[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    L(i,0,n){
        L(j,0,m) if (!((i == 0 && j == 0) || (i == n - 1 && j == m - 1)) && g[i][j] == '.' && !ap[i][j]) {
            ll hsL =  fp1[0][0]; // total amount of shortest paths
            ll hsCur = modmul(fp1[i][j], rp1[i][j]);
            if (hsL == hsCur) g[i][j] = '*'; // Do not block all
        }
    }
    
    L(i,0,n){
        L(j,0,m){
            cout << g[i][j];
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int TT=1;
    // cin>>TT;;
    while(TT--)solve();
}
