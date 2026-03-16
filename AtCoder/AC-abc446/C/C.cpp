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
    int n, d; cin >> n >> d;
    vec<ll> a(n+1); L(i,0,n) cin >> a[i+1];
    vec<ll> b(n+1); L(i,0,n) cin >> b[i+1];

    int j = 0;
    vec<ll> rem(n + 1);
    L(i,1,n+1){
        rem[i] = a[i];
        ll w = b[i];
        while (j <= i && w > 0){
            if (rem[j] >= w) {
                rem[j] -= w;
                w = 0;
            } else {
                w -= rem[j];
                rem[j] = 0;
                j ++;
            }
        }
        while (i - j >= d) {
            j ++;
        }
    }
    ll out = 0;
    // cout << "J: " << j << ": ";
    // L(i,0,n + 1) cout << rem[i] << " ";
    // cout << "\n";
    L(i,j,n + 1) {
        out += rem[i];
    }
    cout << out << "\n";
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