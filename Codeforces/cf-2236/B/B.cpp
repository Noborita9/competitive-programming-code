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
    int n, k; cin >> n >> k;
    vec<int> a(n); L(i,0,n){
        char c; cin >> c; a[i] = c == '1';
    }
    for (int i = n - 1 ; i >= k; i --) {
        if (a[i]) {
            a[i] = 0;
            a[i - k] = 1 - a[i - k];
        }
    }
    bool pos = 1;
    L(i,0,k) pos = pos && (a[i] == 0);
    cout << (pos ? "YES" :  "NO") << "\n";
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