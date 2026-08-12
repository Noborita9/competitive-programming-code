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

const int MXV = 1e5 + 10;
void solve()
{
    vec<ll> c(4);
    L(i,0,4) cin >> c[i];
    int q; cin >> q;
    vec<ll> w(MXV);
    w[0] = 1;
    
    L(j,0,4)
    {
        L(i,c[j],MXV) {
            w[i] += w[i - c[j]];
        }
    }
    // L(i,1,11) cout << w[i] << " "; cout << "\n";
    while(q--)
    {
        vec<ll> d(4); int v;
        L(i,0,4) cin >> d[i];
        cin >> v;
        ll ans = w[v];
        L(mask, 1, 16) {
            ll mt = 1;
            ll vused = 0;
            L(bit,0,4) if (mask & (1<<bit)) {
                vused += (d[bit] + 1) * c[bit];
                mt *= -1;
            }
            if (vused <= v) {
                // cout << mt << " " << v << " " << vused <<" "<< w[v - vused] << "\n"; 
                ans += mt * w[v - vused];
            }
        }
        cout << ans << "\n";
    }
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