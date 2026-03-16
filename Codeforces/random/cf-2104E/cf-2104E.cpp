// #pragma GCC target ("avx2")
// #pragma GCC optimize ("Ofast")
// #pragma GCC optimize ("unroll-loops")
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
const int K = 26;
int nxt[N][K];

void solve()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vec<int> last(k, n+1);
    vec<int> mxi(n + 2, 0);
    vec<int> dp(n + 2, n + 1);
    dp[n + 1] = 0; 
    for (int i = n; i >= 0; i --){
        L(j,0,k) {
            nxt[i][j] = last[j];
            mxi[i] = max(mxi[i], last[j]);
        }
        dp[i] = 1 + dp[mxi[i]];
        if (i) last[s[i-1]-'a'] = i;
    }
    int q; cin >> q;

    L(qi,0,q){
        string p; cin >> p;
        int x = 0;
        int ops = 0;
        for (const char c: p){
            if (x == n + 1) break;
            x = nxt[x][c-'a'];
        }
        cout << dp[x] << "\n";
    }
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
    }
}