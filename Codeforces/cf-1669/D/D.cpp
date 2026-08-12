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
    vec<char> a(n + 2, 'W');
    L(i,1,n+1) cin >> a[i];
    bool pos = 1;
    set<char> s;
    L(i,1,n+1) {
        if (a[i] == 'R' || a[i] == 'B'){
            if (a[i - 1] == 'W' && a[i + 1] == 'W') {
                pos = 0;
            }
            s.insert(a[i]);
        } else {
            if (SZ(s) == 1) pos = 0; 
            s.clear();
        }
    }
    if (SZ(s)) pos = pos && SZ(s) == 2;


    cout << (pos ? "YES" : "NO") << "\n";
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