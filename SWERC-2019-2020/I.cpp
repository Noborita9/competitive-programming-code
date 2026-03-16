#include <bits/stdc++.h>
using namespace std;

#define L(i,j,n) for (int i = (j);i<(int)n; i ++)
#define pb push_back
#define vec vector
#define SZ(x) int(x.size())
#define ALL(x) begin(x),end(x)
#define eb emplace_back

using ll = long long;
using ld = long double;


void solve()
{
    ld a,b,c; cin>>a>>b>>c;
    ld one = 1;
    ld resLD = (((a+one)*(b+one))/(c+one) - one);
    ll res = resLD;

    cout<<res<<'\n';

}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    // cin >> TT;
    while(TT--){
        solve();
    }
}