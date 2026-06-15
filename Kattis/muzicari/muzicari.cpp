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

void solve()
{
    int T, n; cin >> T >> n;
    vec<int> dp(T + 1);
    vec<int> prev(T + 1, - 1);
    dp[0] = 1;
    vec<int> t1(n);
    vec<int> TI(n);
    L(i,0,n){
        int ti; cin >> ti;
        TI[i] = ti;
        for (int j = T; j >= ti; j --) if (!dp[j]) { // just cover it one time
            if (dp[j - ti]) {
                dp[j] = 1;
                prev[j] = i;
            }
        }
    }
    for (int j = T; j >= 0; j --){
        if (dp[j]){
            int it = j;
            while (prev[it] != -1) {
                int used =prev[it];
                it -= TI[used];
                t1[used] = 1;
            }
            break;
        }
    }
    int tt1 = 0;
    int tt2 = 0;
    L(i,0,n){
        if (t1[i]) {
            cout << tt1 << " ";
            tt1 += TI[i];
        } else {
            cout << tt2 << " ";
            tt2 += TI[i]; 
        }
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