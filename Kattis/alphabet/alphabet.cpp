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
    vec<int> lis(n, 1);
    int mx = 1;
    L(i,1,n){
        L(j,0,i){
            if (s[i] > s[j]) lis[i] = max(lis[i],lis[j] +1);
        }
        mx = max(mx, lis[i]);
    }
    cout << 26 - mx << "\n";
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