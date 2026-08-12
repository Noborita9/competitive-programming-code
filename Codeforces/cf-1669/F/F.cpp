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
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    map<ll, ll> h;
    ll acc = 0;
    L(i,0,n){
        acc += a[i];
        h[acc] = i + 1;
    }
    ll ans = 0;
    acc = 0;
    for (int i = n - 1; i >= 1; i --) {
        acc += a[i];
        if (h[acc]) {
            if (h[acc] > i) break;
            ans = max(ans, h[acc] + (n - i));
        }
    }
    cout << ans << "\n";
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