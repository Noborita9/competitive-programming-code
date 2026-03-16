#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define L(i, j, n) for (int i = (j); i < (int)n; i ++)
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define vec vector
#define pb push_back
#define eb emplace_back

#define ll long long
#define ld long double

const int KMAX = 11;
const int MMAX = 105;
int dp[KMAX][MMAX + 2][MMAX + 2];


void solve()
{
    int K, M; cin >> K >> M;
    cout << dp[K][0][M] << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    // L(i,1,M + 1) dp[1][i] += dp[1][i - 1] + i;
    // dp[i][j] = minima cantidad de firecrackers para asegurar que se rompe 
    //              la i-th caja poniendole j firecrackes
    const int oo = 1e9;
    L(i,0,KMAX)L(j,0,MMAX+2)L(k,0,MMAX+2)dp[i][j][k]=oo;
    L(high, 1, MMAX) L(low,0,high) {
        dp[1][low][high] = 0;
        L(j, low + 1, high + 1) dp[1][low][high] += j;
    }
    // L(i,0,MMAX) cout << dp[1][0][i] << "\n";
    L(i,0,KMAX)L(j,0,MMAX+2)dp[i][j][j] = 0;
    L(k,2,KMAX) {
        L(len, 1, MMAX) {
            L(low, 0, MMAX) {
                if (low + len >= MMAX) break;
                int high = low + len;
                L(x, low + 1, high + 1) {
                    int res = x + max(dp[k - 1][low][x - 1], dp[k][x][high]);
                    dp[k][low][high] = min(dp[k][low][high], res);
                }
            }
        }
    }
    
    
    // cout << dp[1][KMAX][MMAX] << "\n";
    while (TT--)
    {// aaaa
        solve();
    }
}