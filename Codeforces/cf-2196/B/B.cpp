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
    vec<int> a(2 * n);
    int tot = 0;
    L(i,0,n){
        char l, r; cin >> l >> r;
        a[i * 2] = l == 'N';
        a[i * 2 + 1] = r == 'N';
        if (i > 0) {
            if (a[i * 2] == a[i * 2 - 1]) tot ++;
        }
    }
    cout << tot << "\n";
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