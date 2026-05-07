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
int dp[N];

void solve()
{
    int x; cin >> x;
    cout << dp[x] << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    L(i,1,10){
        int x = i;
        while(x < N) {
            dp[x] ++;
            x*=10;
        }
    }
    L(i,1,N) dp[i] += dp[i-1];
    
    while (TT--)
    {
        solve();
    }
}