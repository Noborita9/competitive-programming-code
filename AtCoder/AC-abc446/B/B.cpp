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
    int n, m; cin >> n >> m;
    vec<int> used(m);
    L(i,0,n){
        int U = -1;
        int l; cin >> l;
        vec<int> x(l);
        L(i,0,l) {
            cin >> x[i];
            x[i] --;
            if (U==-1 && !used[x[i]]) {
                used[x[i]] = 1;
                U = x[i];
            }
        }
        cout << U+1<<"\n";
        
    }
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