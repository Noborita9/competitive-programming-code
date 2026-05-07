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
    int n, m; cin >> n >> m;
    bool q1 = 1;
    bool q2 = 1;
    vec<int> u(m);
    L(i,0,n) {
        int x; cin >> x;
        x --;
        if (u[x]) {
            q1 = 0;
        }        
        u[x] = 1;
    }
    q2 = accumulate(ALL(u), 0) == m;
    cout << (q1 ? "Yes" : "No") << "\n";
    cout << (q2 ? "Yes" : "No") << "\n";
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