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
    int mv = 0;
    if (s[0] == 'u') {
        mv ++;
        s[0] = 's';
    }
    if (s[SZ(s) - 1] == 'u'){
        mv ++;
        s[SZ(s) - 1] = 's';
    }
    int cu = s[1] == 'u';
    L(i, 2, SZ(s) - 1){
        if (s[i] == 'u') {
            cu ++;
            if (cu == 2){
                s[i] = 's';
                mv ++;
                cu = 0;
            }
        } else {
            cu = 0;
        }
    }

    // cout << s << " => ";
    cout << mv << "\n";
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