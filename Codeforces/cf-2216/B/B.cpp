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
    ll t, h, u; cin >> t >> h >> u;
    ll tu = min(t, u);
    u -= tu;
    t -= tu;
    ll tht = min(t/2, h);
    t -= tht*2;
    h -= tht;

    ll th = min(t, h);
    t -= th;
    h -= th;
    
    // cout << tu << " " << tht << " " << th << " " << tt << "\n"; 
    ll ans = (tu * 4ll) + (tht * 7ll) + (th * 5) + (h * 3ll) + (u * 3ll);
    if (t == 1) ans += 3;
    else if (t > 1) ans += 3 + (2 * (t-1));
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