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
    vec<vec<int>> dp(n + 1);
    vec<int> ord(n + 1);
    // L(i,0,n) dp[i+1].pb(0);
    vec<int> a(n + 1);
    L(i,0,n) {
        cin >> a[i+1];
        dp[a[i+1]].pb(i+1);
        ord[i + 1] = SZ(dp[a[i+1]]);
    }
    vec<int> adp(n + 1);
    L(i,1,n+1){
        int o = ord[i];
        auto &cdp = dp[a[i]];
        adp[i] = adp[i - 1];
        if (o >= a[i]) {
            adp[i] = max(adp[i], adp[cdp[o - a[i]]-1] + a[i]);
            // cdp[o] = max(cdp[o], cdp[o - a[i]] + a[i]);
        }
    }
    // L(i,0,n+1)cout <<adp[i] << " "; cout << "\n\n";
    cout << adp[n] << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}