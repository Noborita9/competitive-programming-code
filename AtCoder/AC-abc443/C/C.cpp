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
    int n, t; cin >> n >> t;
    if (n == 0){
        cout << t << "\n";
        return;
    }
    int tot = 0;
    int last = 0;
    vec<int> a(n);
    L(i,0,n) cin >> a[i];
    
    L(i,0,n){
        if (last < a[i]) {
            tot += a[i] - last;
            last = a[i] + 100;
        }
    }
    last = min(t,max(last, a.back()));
    tot += t - last;
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