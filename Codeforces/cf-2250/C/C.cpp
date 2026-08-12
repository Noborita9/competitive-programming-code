#include <bits/stdc++.h>
using namespace std;

#define L(i, j, n) for (int i = (j); i < (int)n; i ++)
#define SZ(x) int((x).size())
#define ALL(x) begin(x),end(x)
#define mset(x, v) memset(x,v,sizeof(x))
#define show(v) {for(auto it:v)cout<<v<<" ";cout<<"\n"}
#define vec vector
#define pb push_back
#define eb emplace_back

using ll = long long;
using ld = long double;

void solve()
{
    int n; cin >> n;
    vec<int> l(n + 1), r(n + 1), u(n + 1), v(n + 1);
    int ans = 0;

    auto check = [&]()
    
    for (int len = n; len > 0; len --)
    {
        if (check(len))
        {
            ans = len;
            break;
        }
    }
    cout << ans << "\n";
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