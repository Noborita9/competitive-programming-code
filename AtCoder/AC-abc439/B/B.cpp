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
    vec<int> vis(10000);
    while (n != 1 && !vis[n]) {
        vis[n] = 1;
        int nx = 0;
        while(n > 0) {
            int d = n % 10;
            nx +=d * d;
            n /= 10;
        }
        n = nx;
    }
    if (n == 1){
        cout << "Yes\n";
    } else {
        cout << "No\n";
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