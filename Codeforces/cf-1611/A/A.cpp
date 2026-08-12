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
    string s; cin >> s;
    int e = 0;
    int n = SZ(s);
    L(i,0,n) {
        int c = s[i] - '0';
        if (c % 2 == 0) {
            e ++;
        }
    }
    if (!e) {
        cout << "-1\n";
        return;
    }
    if ((s.back() - '0') % 2 == 0) {
        cout << "0\n";
    } else if ((s[0] - '0') %2 == 0){
        cout << "1\n";
    } else cout <<"2\n";
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