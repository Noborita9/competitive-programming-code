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
    vec<string> a(n);
    int m = 0;
    L(i,0,n){
        cin >> a[i];
        m = max(m,SZ(a[i]));
    }
    L(i,0,n){
        int k = (m - SZ(a[i])) / 2;
        L(j,0,k) cout << ".";
        cout << a[i];
        L(j,0,k) cout << ".";
        cout << "\n";
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