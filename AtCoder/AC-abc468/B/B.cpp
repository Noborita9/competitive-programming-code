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
    int n, d; cin >> n >> d;
    string s; cin >> s;
    vec<bool> w(n);
    int ans = n;
    L(i,0,n)
    {
        if (s[i] == 'G')
        {
            L(j,0,d+1)
            {
                if (i + j < n && !w[i + j]) {
                    ans --;
                    w[i + j] = 1;
                } 
                if (i - j >= 0 && !w[i - j]){
                    ans --;
                    w[i - j] = 1;
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