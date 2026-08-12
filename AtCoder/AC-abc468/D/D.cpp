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
    int n = SZ(s);
    ll ans = 0;
    L(i,0,n)
    {
        int miss = 0;
        // single center
        ans ++;
        L(j,1,n)
        {
            if (i - j >= 0 && i + j < n) {
                if (s[i - j ] == s[i + j]) {
                    ans ++;
                } else if (miss == 0) {
                    ans ++;
                    miss ++;
                } else break;
            }
        }
        
        // cout << ans << "\n";
        // force double center
        if (i > 0) {
            ans ++;
            miss = s[i] != s[i - 1];
            L(j,1,n){
                if (i - j - 1 >= 0 && i + j < n) {
                    if (s[i - j - 1] == s[i + j]) {
                        ans ++;
                    } else if (miss == 0) {
                        ans ++; miss++;
                    } else break;
                }
            }
        }        
    }
    cout << ans << "\n";
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