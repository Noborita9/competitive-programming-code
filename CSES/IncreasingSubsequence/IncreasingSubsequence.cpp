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

const int oo = (int)1e9 + 10;
int lis(vec<int> &a) {
    int n = SZ(a);
    vector<int> d(n+1, oo);
    d[0] = -oo;
    L(i,0,n){
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l-1] < a[i] && a[i] < d[l]) d[l] = a[i];
    }
    int ans = 0;
    for (int l = 0; l <= n; l++) if (d[l] < oo) ans = l;
    return ans;
}

void solve()
{
    int n; cin >> n;
    vec<int> a(n);
    L(i,0,n) cin >> a[i];
    cout << lis(a) << '\n';
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