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

const int N = 3e5 + 10;


void solve()
{
    int n; cin >> n;
    vec<ll> ans(n + 1, -1);
    set<ll> nums;
    L(i,0,n) {
        ll x; 
        cin >> x;
        nums.insert(x);
        ans[x] = 1;
    }
    for (const ll x: nums) {
        for (int i = x + x; i <= n; i += x) {
            if (i % x == 0) {
                if (ans[i] == -1) {
                    if (ans[i / x] != -1)  {
                        ans[i] = ans[i / x] + 1;
                    }
                } else {
                    if (ans[i / x] != -1) {
                        ans[i] = min(ans[i], ans[i / x] + 1);
                    }
                }
            }
        }
    }
    
    
    L(i,1,n +1) cout << ans[i] << " "; cout << "\n";
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