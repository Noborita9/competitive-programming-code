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
    vec<int> a(n); L(i,0,n) cin >> a[i];
    int ans = 0;
    vec<int> lis(n, 1), lds(n, 1);

    for (int i = n - 1; i >= 0; i --)
    {
        for (int j = i + 1; j < n; j ++){
            if (a[j] > a[i]) lis[i] = max(lis[i], lis[j] + 1);
            if (a[j] < a[i]) lds[i] = max(lds[i], lds[j] + 1);
        }
        ans = max(ans, lis[i] + lds[i] - 1);
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