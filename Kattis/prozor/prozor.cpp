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

const int N = 110;

int dp[N][N];
char c[N][N];

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    L(i,1,n+1){
        L(j,1,m+1){
            cin >> c[i][j];
            dp[i][j] = dp[i-1][j] + dp[i][j - 1] - dp[i-1][j-1] + (c[i][j] =='*');
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }   
    k -= 2;
    int bst = 0;
    int bsti = 1;
    int bstj = 1;
    L(i,k + 1,n){
        L(j,k + 1,m){
            int bi = i - k;
            int bj = j - k;
            int fs = dp[i][j] - dp[i][bj] - dp[bi][j] + dp[bi][bj];
            if (fs > bst) {
                bst = fs;
                bsti = bi;
                bstj = bj;
            }
            // cout << fs << " ";
        }
        // cout << "\n";
    }  
    k += 2;
    c[bsti][bstj] = '+';
    c[bsti + k - 1][bstj + k - 1] = '+';
    c[bsti][bstj + k - 1] = '+';
    c[bsti + k - 1][bstj] = '+';
    L(j,bstj + 1, bstj + k - 1) c[bsti][j] = c[bsti + k - 1][j] = '-';
    L(j,bsti + 1, bsti + k - 1) c[j][bstj] = c[j][bstj + k - 1] = '|';
    cout << bst << "\n";
    L(i,1,n+1){
        L(j,1,m+1){
            cout << c[i][j];
        }
        cout << "\n";
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