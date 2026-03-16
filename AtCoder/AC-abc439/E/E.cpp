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

using ii = pair<int,int>;

const int oo = 1e9;

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
    vec<ii> a(n);
    L(i,0,n) cin >> a[i].first >> a[i].second;
    sort(ALL(a), [](const ii &lhs, const ii &rhs){
        if (lhs.first != rhs.first) return lhs.first < rhs.first;
        return lhs.second > rhs.second;
    });
    vec<int> b(n);
    L(i,0,n) b[i] = a[i].second;
    int ans = lis(b);

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