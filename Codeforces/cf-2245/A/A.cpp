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
    string s; cin >> s;
    if (k > n / 2) {
        cout << "-1\n";
        return;
    }
    int ans = 0;
    L(jsdsa,0,n){
        int ls = 0;
        L(i,0,n) {
            if (s[i] == 'R') ls ++;
            else {
                if (ls < k) {
                    s[i] = 'R';
                    ans ++;
                    ls ++;
                }
            }
        }
        int rs = 0;
        for (int i = n - 1; i >= 0; i --){
            if (s[i] == 'L') rs ++;
            else {
                if (rs < k) {
                    ans ++;
                    s[i] = 'L';
                    rs ++;
                }
            }
        }
    }
    
    cout << ans << "\n";
    // cout << s << "\n";
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