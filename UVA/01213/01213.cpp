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

const int N = 1130;
const int K = 15;
ll dp[N][K];
int n_, k_;

void solve()
{
    // cout << n_ << " " << k_ << "\n";
    cout << dp[n_][k_] << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    //cin >> TT;
    dp[0][0] = 1;
    vec<int> crib(N);
    // cout << N << " " << K << "\n";
    L(i,2,N){
        if (crib[i]) continue;
        for (int j = i + i; j < N; j += i) crib[j] = 1;
        // run for dp
        for (int k = K - 1; k > 0; k --){
            for (ll j = N - 1; j >= i; j --) {
                dp[j][k] += dp[j - i][k - 1];
            }
        }
    }
    while (1)
    {
        cin >> n_ >> k_;
        if (n_ == 0 && k_ == 0) break;
        solve();
    }
}