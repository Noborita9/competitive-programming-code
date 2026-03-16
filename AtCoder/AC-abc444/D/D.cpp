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
    int m; cin >> m;
    int n = (int)2e5 + 10;
    vec<int> pref(n + 1);
    L(i,0,m){
        int a; cin >> a;
        pref[a] ++;
    }
    for (int i = n - 1; i >= 0; i --) pref[i] += pref[i + 1];
    vec<int> out;
    for (int i = 1; i <= n; i ++) {
        if (!pref[i]) break;
        out.pb(pref[i] % 10);
        if (i  + 1 <= n) pref[i + 1] += pref[i] / 10;
    }

    while(SZ(out)) {
        cout << out.back();
        out.pop_back();
    }
    cout << "\n";
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