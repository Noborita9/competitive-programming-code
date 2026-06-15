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
int dp[N][N];

void solve()
{
    int n, q; cin >> n >> q;
    L(i,1,n + 1){
        L(j,1, n + 1) {
            char c; cin >> c;
            int x = c == '*';
            dp[i][j] = x;
        }
    }
    L(dim, 0, 2){
        L(i,1,n+1){
            L(j,1,n+1){
                int pi = i - (dim==0), pj = j - (dim==1);
                dp[i][j] += dp[pi][pj];
            }
        }
    }
    while(q--)
    {
        int s_x, s_y, e_x, e_y; cin >> s_x >> s_y >> e_x >> e_y;
        cout << dp[e_x][e_y] - dp[e_x][s_y-1] - dp[s_x-1][e_y] + dp[s_x-1][s_y-1] << "\n";
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