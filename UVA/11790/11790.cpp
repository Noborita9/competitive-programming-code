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
    vec<ll> h(n+1), l(n+1);
    L(i,0,n) cin >> h[i+1];
    L(i,0,n) cin >> l[i+1];
    auto LIS = [&]() -> ll {
        vec<ll> dp(n + 1, LLONG_MIN);
        L(i,1,n+1){
            dp[i] = l[i];
            L(j,1,i) {
                if (h[i] > h[j]) {
                    // cout << i << " - " << j << "=> "<< dp[j] << " " << l[i] << "\n";
                    dp[i] = max(dp[i], dp[j] + l[i]);
                }
            }
        }
        // L(i,0,n+1) cout << dp[i] <<" "; cout << "\n";
        return *max_element(ALL(dp));
    };
    ll inc = LIS();
    L(i,0,n) h[i+1] *= -1;
    ll dec = LIS();
    string sinc = "Increasing (" + to_string(inc) + ").";
    string sdec = "Decreasing (" + to_string(dec) + ").";
    if (dec > inc) swap(sinc, sdec);
    cout << sinc << " " << sdec << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    L(tt,0,TT)
    {
        cout << "Case " << tt+1<<". ";
        solve();
    }
}