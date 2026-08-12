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

const int N = 1e6 + 10;
int dp[N][3][3];

void solve()
{
    int n, m; cin >> n >> m;
    vec<int> h(m+3); L(i,0,n) {int x; cin >> x; h[x]++;}
    const int oo = 1e9;
    L(i,0,N)L(j,0,3)L(k,0,3)dp[i][j][k]=-oo;
    dp[0][0][0] = 0;
    int ans = 0;
    L(i,1,m + 3)
    {
        L(j,0,3)
        {
            L(k,0,3)
            {
                L(l,0,3)
                {
                    if (h[i] - j - k - l >= 0)
                    {
                        int prev = dp[i-1][l][j];
                        int plus = (h[i] - j - k - l) / 3;
                        dp[i][j][k] = max(dp[i][j][k], prev + plus + k);
                    }
                }
            }
        }
    }
    cout << dp[m + 2][0][0] << "\n";
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