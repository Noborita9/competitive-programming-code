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
    vec<int> a(n), pref(n), suff(n);
    L(i,0,n) cin >> a[i];
    pref[0] = a[0] == 1 ? 1 : -1;
    L(i,1,n){
        pref[i] = a[i] == 1 ? 1 : -1;
        pref[i] += pref[i - 1];
    }
    for (int i = n - 2; i >= 0; i --) {
        suff[i] = a[i] == 3 ? -1 : 1;
        suff[i] += suff[i + 1];
    }
    // L(i,0,n) cout << pref[i] << " ";
    // cout << "\n";
    // L(i,0,n) cout << suff[i] << " ";
    // cout << "\n";
    
    bool pos = 0;
    const int oo = 1e9;
    int mn = 0;
    for (int i = n - 2; i >= 1; i --) {
        if (pref[i - 1] >= 0 && suff[i] - mn >= 0) {
            pos = 1;
        } 
        mn = min(mn, suff[i]);
    }
    if (pos) cout << "YES\n";
    else cout << "NO\n";
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