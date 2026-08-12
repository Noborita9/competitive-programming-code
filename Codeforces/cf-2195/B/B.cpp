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
    vec<int> a(n + 1);
    L(i,0,n) {
        cin >> a[i + 1];
        // a[i] --;
    }
    L(i,1,((n + 1)/2) + 1) {
        if (a[i] == i) continue;
        int nxt = (i * 2);
        // looking for i
        // cout << i << " - " << nxt << "\n";
        while (nxt <= n && a[nxt] != i) {
            nxt = (nxt * 2);
            // cout << i << " - " << nxt << "\n";
        }
        if (nxt > n) {
            cout << "NO\n";
            return;
        }
        // cout << "Swap " << i << " - " << nxt << "\n";

        swap(a[i], a[nxt]);
    }
    // L(j,0,n + 1) cout << a[j] << " "; cout << "\n";
    bool ans = is_sorted(ALL(a));
    cout << (ans ? "YES" : "NO") << "\n";
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