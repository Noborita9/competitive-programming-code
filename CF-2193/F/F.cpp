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

using ii = pair<ll,ll>;
struct pt {
    ll x, y;
};

void solve()
{
    int n; ll s_x, s_y, e_x, e_y; cin >> n >> s_x >> s_y >> e_x >> e_y;
    vec<pt> p(n + 1);
    map<ll, ll> mup, mdown;
    L(i,0,n) {
        cin >> p[i].x;
    }
    L(i,0,n) {
        cin >> p[i].y;
        mup[p[i].x] = max(mup[p[i].x], p[i].y);
        if (!mdown[p[i].x]) mdown[p[i].x] = p[i].y;
        else mdown[p[i].x] = min(mdown[p[i].x], p[i].y);
    }
    mup[e_x] = max(mup[e_x], e_y);
    if (!mdown[e_x]) mdown[e_x] = e_y;
    else mdown[e_x] = min(mdown[e_x], e_y);

    ll mov_x = e_x - s_x;

    ll eup = s_y;
    ll eup_c = 0;
    
    ll edown = s_y;
    ll edown_c = 0;
    
    const ll oo = 4e18;
    
    for (const auto &[x, up]: mup) {
        ll down = mdown[x];
        ll dist = up - down;
        ll neup = oo;
        ll ndown = oo;
        // end up
        // eup -> up
        if (eup >= up) {
            ll pot = eup - up;
            pot += dist * 2 + 1;
            neup = eup_c + pot;
        } else if (eup <= down) {
            ll pot = down - eup;
            pot += dist;
            neup = eup_c + pot;
        } else {
            ll pot = eup - down;
            pot += dist;
            neup = eup_c + pot;
        }
        
        // edown -> up

        if (edown >= up) {
            ll pot = edown - up;
            pot += dist * 2;
            neup = min(edown_c + pot, neup);
        } else if (edown <= down) {
            ll pot = down - edown;
            pot += dist;
            // neup = eup_c + pot;
            neup = min(edown_c + pot, neup);
        } else {
            ll pot = edown - down;
            pot += dist;
            // neup = eup_c + pot;
            neup = min(edown_c + pot, neup);
        }
    
        // end down
        // eup -> down
        if (eup >= up) {
            ll pot = eup - up;
            pot += dist ;
            ndown = eup_c + pot;
        } else if (eup <= down) {
            ll pot = down - eup;
            pot += dist * 2;
            // pot += dist;
            ndown = eup_c + pot;
        } else {
            ll pot = up - eup;
            pot += dist;
            ndown = eup_c + pot;
        }

        // edown - > down

        if (edown >= up) {
            ll pot = edown - up;
            pot += dist ;
            ndown = min(edown_c + pot, ndown);
        } else if (edown <= down) {
            ll pot = down - edown;
            pot += dist * 2;
            // pot += dist;
            ndown = min(edown_c + pot, ndown);
        } else {
            ll pot = up - edown;
            pot += dist;
            ndown = min(edown_c + pot, ndown);
        }
        // Update vars for next x
        eup_c = neup;
        edown_c = ndown;
        eup = up;
        edown = down;
    }
    

    ll mov_y = min(eup_c, edown_c); // min mov y ending up or down
    ll ans = mov_x + mov_y;
    cout << ans << "\n";
}


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int TT = 1;
    cin >> TT;
    while (TT--)
    {
        solve();
    }
}