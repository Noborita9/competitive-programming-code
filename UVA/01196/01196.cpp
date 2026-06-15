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

int n;

void solve()
{
    vec<pair<int,int>> ps(n);
    L(i,0,n) {
        cin >> ps[i].first >> ps[i].second;
    }
    sort(ALL(ps));
    vec<int> lis;
    lis.pb(ps[0].second);
    L(i,1,n){
        if (ps[i].second >= lis.back()){
            lis.pb(ps[i].second);
        } else {
            int it = upper_bound(ALL(lis), ps[i].second) - begin(lis);
            lis[it] = ps[i].second;
        }
    }
    cout << SZ(lis) << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    //cin >> TT;
    while (1)
    {
        cin >> n; if (n == 0) {
            cout <<"*\n";
            break;
        }
        solve();
    }
}