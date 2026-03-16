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

const int N = 1e5 + 10;

void solve()
{
    int n, k; cin >> n >> k;
    int tot = 0;
    L(i,1,n + 1){
        int t = i;
        int sm = 0;
        while(t>0){
            sm+=t%10;
            t/=10;
        }
        tot += sm==k;
    }
    cout << tot <<"\n";
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