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

const ll MOD = (ll)1e9 + 7;

void solve()
{
    int n; cin >> n;
    vec<vec<ll>> dp(n + 1, vec<ll>(n + 1));
    L(i,0,n){
        L(j,0,n){
            cin >> g[i+1][j+1];
        }
    }
    dp[1][1] = g[1][1] == '.';
    L(i,1,n+1){
        L(j,1,n+1) if(g[i][j] == '.'){
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }
    cout << dp[n][n] << "\n";
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