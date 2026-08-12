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

const int K = 24;

void solve()
{
    int n; cin >> n;
    const int masks = 1 << K;
    vec<short> sos(masks);
    L(i,0,n){
        string s; cin >> s;
        vec<int> b = {s[0] - 'a', s[1] - 'a', s[2] - 'a'};
        int b0 = 1 << b[0];
        int b1 = 1 << b[1];
        int b2 = 1 << b[2];
        sos[b0] ++;
        sos[b1] ++;
        sos[b2] ++;
        sos[b0 | b1] --;
        sos[b0 | b2] --;
        sos[b1 | b2] --;
        sos[b0 | b1 | b2] ++;
    }
    L(d, 0, K)
    {
        const int prev = 1 << d;
        L(mask, 0, masks) if (mask & prev) {
            sos[mask] += sos[mask ^ prev];
        }
    }
    ll ans = 0;
    L(i,0,masks) {
        ans ^= (ll)sos[i]*(ll)sos[i];
    }
    cout << ans << "\n";
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