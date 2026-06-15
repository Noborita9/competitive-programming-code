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

int solve(int a, int b, int x)
{
    if (a == b) return 0;
    int mx = max(a, b);
    int mn = min(a, b);
    return min(mx - mn, 1 + solve(mx / x, mn, x));
}

void solve()
{
    int a, b, x; cin >> a >> b >> x;
    cout << solve(a, b, x) << "\n";
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