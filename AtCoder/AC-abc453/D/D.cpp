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

const int N = 1010;
char g[N][N];

string movs = "LRUD";
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};


using iii = tuple<int,int,int>;

void solve()
{
    int n, m; cin >> n >> m;
    const int oo = (int)1e9;
    vec<vec<vec<int>>> dist(n, vec<vec<int>>(m, vec<int>(4, oo)));
    int s_x, s_y, e_x, e_y;
    L(i,0,n){
        L(j,0,m){
            cin >> g[i][j];
            if (g[i][j] == 'S') {
                s_x = i;
                s_y = j;
            } else if (g[i][j] == 'G') {
                e_x = i;
                e_y = j;
            }
        }
    }
    queue<iii> q;
    L(k,0,4) {
        dist[s_x][s_y][k] = 0;
        q.push({s_x,s_y,k});
    }
    auto build = [&](int i, int j) -> void {
        int x = i;
        int y = j;
        vec<char> path;
        int prev = -1;
        while (x != s_x || y != s_y) {
            int best = 0;
            if (g[x][y] == 'o') {
                best = prev;
            } else if (g[x][y] == 'x') {
                if (best == prev) best ++;
                L(k,0,4) if (k != prev && dist[x][y][k] < dist[x][y][best]) best = k; 
            } else {
                L(k,0,4) if (dist[x][y][k] < dist[x][y][best]) best = k; 
            }
            path.pb(movs[best]);
            x -= dx[best];
            y -= dy[best];
            prev = best;
        };
        reverse(ALL(path));
        for (const char c: path) cout << c;
        cout << "\n";
    };
    
    while(SZ(q)) {
        auto [i, j, p] = q.front(); q.pop();
        vec<int> allow;
        if (g[i][j] == 'o') {
            // only use p
            allow.assign(4, 0);
            allow[p] = 1;
        } else if (g[i][j] == 'x') {
            // don't use p
            allow.assign(4, 1);
            allow[p] = 0;
        } else if (g[i][j] == 'G'){
            cout << "Yes\n";
            build(i,j);
            return;
        } else allow.assign(4, 1);
        L(k,0,4) if (allow[k]) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m || g[ni][nj] == '#') continue;
            if (dist[ni][nj][k] > dist[i][j][p] + 1) {
                dist[ni][nj][k] = dist[i][j][p] + 1;
                q.push({ni,nj,k});
            }
        }
    }
    cout << "No\n";
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