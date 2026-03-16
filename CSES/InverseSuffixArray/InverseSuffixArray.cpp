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
    vec<int> p(n + 1), back(n + 1);
    L(i,0 , n) {
        cin >> p[i]; p[i] --;
        back[p[i]] = i;
    }
    back[n] = -1;
    vec<int> out(n);
    int c = 0;
    L(i,1,n) {
        if (back[p[i - 1] + 1] > back[p[i] + 1]) c++;
        out[p[i]] = c;
    }
    if (c >= 26) {
        cout << "-1\n";
        return;
    }
    L(i,0,n) cout << (char)('a' +out[i]); cout << "\n";
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