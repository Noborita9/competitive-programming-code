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
    vec<vec<ll>> m(n, vec<ll>(n));
    L(i,0,n) {
        L(j,i + 1,n) {
            cin >> m[i][j];
            m[j][i] = m[i][j];
        }
    }
    bool p = 0;
    L(i,0,n){
        L(j,i+1,n){
            L(k,j+1,n){
                if (m[i][k]>m[i][j]+m[j][k]) p = 1;
            }
        }
    }

    cout << (p ? "Yes" : "No") << "\n";
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