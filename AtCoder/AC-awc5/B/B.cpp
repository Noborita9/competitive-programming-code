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
    int n, m, k; cin >> n >> m >> k;
    vec<ll> a(n); L(i,0,n) cin >> a[i];
    L(i,0,m){
        int x, p; cin >> x >> p;
        a[x - 1] = p;
    }
    int out = 0;
    L(i,0,n) if (a[i] < k) out ++;
    cout << out << "\n";
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