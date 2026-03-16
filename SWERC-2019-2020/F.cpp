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

using point = pair<ll, ll>;

ld poly_area(const vec<point> & poly) {
    ll area = 0;
    int n = SZ(poly);
    L(i,0,n){
        ll j = (i+1)%n;
        area += poly[i].first*poly[j].second - poly[i].second*poly[j].first;
    }
    return abs((ld)area) / (ld)2;
}

void solve()
{
    ll n; cin>>n;
    ld area = 0;
    while(n--){
        ll k; cin>>k;
        vec<point> pol(k);
        L(i,0,k){
            cin>>pol[i].first;
            cin>>pol[i].second;
        }
        area += poly_area(pol);
    }

    ll res = area;

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