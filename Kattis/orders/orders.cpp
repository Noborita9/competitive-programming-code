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
    int n; cin >> n;
    int P = 30010;
    const int NONE = 0;
    const int ONCE = 1;
    const int MULT = 2;
    vec<int> dp(P + 10, NONE);
    vec<int> prev(P + 10, - 1);
    dp[0] = ONCE;
    vec<int> v(n);
    L(i,0,n){
        int p; cin >> p;
        v[i] = p;
        for(int j = p; j <= P; j ++){
            if (dp[j - p] == MULT){
                dp[j] = MULT;
                prev[j] = -1;
            } else if (dp[j - p] == ONCE) {
                if (dp[j] == ONCE) {
                    dp[j] = MULT;
                    prev[j] = -1;
                } else if (dp[j] == NONE) {
                    dp[j] = ONCE;
                    prev[j] = i;
                }
            }
        }
    }
    int q; cin >> q;
    while(q--)
    {
        int x; cin >> x;
        if (dp[x] == NONE){
            cout << "Impossible\n";
        } else if (dp[x] == MULT){
            cout << "Ambiguous\n";
        } else {
            vec<int> path;
            int it = x;
            while (prev[it] != -1){
                int used = prev[it];
                it -= v[used];
                path.pb(used);
            } 
            reverse(ALL(path));
            for (int px: path) cout << px + 1 << " ";
            cout << "\n";
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