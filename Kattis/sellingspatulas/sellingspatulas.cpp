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

const ll COST = 8;

int n;
void solve()
{
    ll prof = 0;
    ll best = 0;
    int btle = 0;
    int btri = 0;

    int time = -1;
    int tle = 0;
    int tri = 0;
    
    L(i,0,n){
        int ti; ld pid; cin >> ti >> pid;
        ll pi = round(100 * pid);
        ll sh = pi - COST;
        ll kg = prof + pi - ((ti - time) * COST);
        if (sh >=    kg){
            tle = ti;
            prof = sh;
        } else {
            prof = kg;
        }
        tri = ti;
        time = ti;
        if (prof == best){
            int cp = btri - btle;
            int ap = tri - tle;
            if (ap < cp) {
                btle = tle;
                btri = tri;
            }
        }
        else if (prof > best){
            best = prof;
            btle = tle;
            btri = tri;
        }
    }

    if (best == 0) {
        cout << "no profit\n";
        return;
    }
    
    cout << fixed << setprecision(2) << ((ld)best/100.0 + 0.00001) << " " << btle << " " << btri  << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    // cin >> TT;
    while (1)
    {
        cin >> n;
        if (n == 0) break;
        solve();
    }
}