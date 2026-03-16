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
    vec<int> a(n); L(i,0,n) cin >> a[i];
    vec<int> id(n);
    iota(ALL(id),0);
    while(SZ(id) > 1){
        vec<int> cur;
        int gps = (SZ(id)+k-1)/k;
        cur.reserve(gps);
        
        L(j,0,gps) {
            ll mx = a[id[k * j]];
            int ix = k * j;
            L(i,1,k){
                if (k * j + i >= SZ(id)) break;
                if (a[id[k * j + i]] > mx){
                    mx = a[id[k * j + i]];
                    ix = k * j + i;
                }
            }
            cur.pb(id[ix]);
        }
        id.swap(cur);
    }
    cout << id.back()+1 << "\n";
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