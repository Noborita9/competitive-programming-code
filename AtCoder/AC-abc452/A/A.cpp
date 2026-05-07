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
    int a, b; cin >> a >> b;
    if (a == 1 && b == 7) cout << "Yes\n";
    else if (a == 3 && b == 3) cout << "Yes\n";
    else if (a == 5 && b == 5) cout << "Yes\n";
    else if (a == 7 && b == 7) cout << "Yes\n";
    else if (a == 9 && b == 9) cout << "Yes\n";
    else cout << "No\n";
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