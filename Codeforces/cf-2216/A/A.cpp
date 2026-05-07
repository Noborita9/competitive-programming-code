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
    int n, k; cin >> n >> k;
    vec<int> a(k); L(i,0,k) {
        cin >> a[i];
    }
    vec<pair<int,int>> b(n); 
    L(i,0,n) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(ALL(b));
    vec<int> ops;
    for (int j = n - 1; j >= 0; j --){
        // cout << b[j].first << " " << b[j].second << "\n";
        int left = (k + 1) - b[j].first;
        L(asd,0,left) {
            // cout << b[j].second + 1 << "\n";
            ops.pb(b[j].second + 1);
        }
    }
    if (SZ(ops) > 1000) {
        cout << "-1\n";
        return;
    }
    cout << SZ(ops) << "\n";
    for (int o: ops) cout << o << " ";
    cout << "\n";
    
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