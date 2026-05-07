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
    vec<int> a(n); L(i,0,n) cin >> a[i];
    sort(ALL(a));
    if (n % 2 != 0) {
        cout << "NO\n";
        return;
    }
    a.pb(1e9);
    int i = 1;
    int cnt = 1;
    while (i < n){
        if (a[i] == a[i - 1]) cnt ++;
        else {
            // handle break
            if (cnt == 1) break;
            if ((cnt%2==1) && a[i] - 1 != a[i - 1]) {
                break;
            }
            cnt = (cnt % 2) + 1;
        }
        i ++;
    }
    cnt %= 2;
    // cout << i << " " << cnt << "\n";
    if (i < n || cnt) {
        cout << "No\n";
    } else {
        cout << "Yes\n";    
    }
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