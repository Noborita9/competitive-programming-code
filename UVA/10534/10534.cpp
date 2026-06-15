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
    if (!cin.good() || cin.eof()) exit(0);
    vec<int> a(n); L(i,0,n) cin >> a[i];
    if (n == 1){
        cout << "1\n";
        return;
    }
    vec<int> mx(n, 0);
    vec<int> lis; lis.pb(a[0]);
    // cout << "FList" << endl;
    L(i,1,n){
        // cout << "IN: " << i << endl;
        
        if (lis.back() < a[i]) {
            mx[i] = SZ(lis);
            lis.pb(a[i]);
        }
        else {
            auto it = lower_bound(ALL(lis),a[i]) - begin(lis);
            auto mil = lower_bound(ALL(lis), a[i]);
            if (mil != begin(lis)) {
                mx[i] = mil - begin(lis);
            }

            if (it == SZ(lis)) continue;
            lis[it] = a[i];
        }
        // cout << "OUT: " << i << endl;
    }

    int best = 1;
    lis.clear();
    lis.pb(a.back());
    // cout << "SList" << endl;
    for (int i = n - 2; i >= 0; i --){
        if (lis.back() < a[i]) {
            int lisR = SZ(lis);
            int lisL = mx[i];
            int mn = min(lisR, lisL);
            best = max(best, 2 * mn + 1);
            lis.pb(a[i]);
        }
        else {
            auto it = lower_bound(ALL(lis),a[i]) - begin(lis);
            auto lisRit = lower_bound(ALL(lis), a[i]);
            if (lisRit != begin(lis)) {
                int lisR = lisRit - begin(lis);
                int lisL = mx[i];
                // for (int l: lis) cout << l << " "; cout << "\n";
                // cout << "This side: " << a[i] << " => " << *lisRit << " " << lisR << " " << lisL << "\n";;
                int mn = min(lisR, lisL);
                best = max(best, 2 * mn + 1);
            } 
            
            if (it == SZ(lis)) continue;
            lis[it] = a[i];
        }
    }


    cout << best<< "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 75;
    //cin >> TT;
    while (TT--)
    {
        if (!cin.good() || cin.eof()) break;
        solve();
    }
}